#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX 50
#define EMAIL_MAX 50

// Buffer: count | option | peopleDataSize | tempName | tempAge | tempEmail | people...
#define AREA_FIXA ( sizeof( int ) * 2 + sizeof( size_t ) + NAME_MAX + sizeof( int ) + EMAIL_MAX )

void AddPerson( void** ppBuffer );
void DeletePerson( void** ppBuffer );
void ListPeople( void* pBuffer );
void PrintPerson( void* pBuffer );

int main() {

	void* pBuffer = malloc( AREA_FIXA );
	if( !pBuffer ) {
		printf( "Erro ao alocar memória!\n" );
		return 1;
	}

	int* count = ( int* )pBuffer;
	*count	   = 0;

	int* option = ( int* )( ( char* )pBuffer + sizeof( int ) );

	size_t* peopleDataSize = ( size_t* )( ( char* )pBuffer + sizeof( int ) * 2 );
	*peopleDataSize		   = 0;

	while( 1 ) {

		do {
			printf( "\n#------------------------#\n" );
			printf( "#     Agenda pBuffer     #\n" );
			printf( "#------------------------#\n" );
			printf( "# 1 - Adicionar Pessoa   #\n" );
			printf( "# 2 - Remover Pessoa     #\n" );
			printf( "# 3 - Buscar Pessoa      #\n" );
			printf( "# 4 - Listar Todas       #\n" );
			printf( "# 5 - Sair               #\n" );
			printf( "#------------------------#\n" );
			printf( "Escolha uma opcao: " );

			if( scanf( "%d", option ) != 1 ) {
				while( getchar() != '\n' )
					;
				*option = 0;
				continue;
			}

			while( getchar() != '\n' )
				;

		} while( *option < 1 || *option > 5 );

		switch( *option ) {
		case 1:
			AddPerson( &pBuffer );
			// Atualizar ponteiros após realloc
			count  = ( int* )pBuffer;
			option = ( int* )( ( char* )pBuffer + sizeof( int ) );
			break;

		case 2:
			DeletePerson( &pBuffer );
			// Atualizar ponteiros após realloc
			count  = ( int* )pBuffer;
			option = ( int* )( ( char* )pBuffer + sizeof( int ) );
			break;

		case 3:
			PrintPerson( pBuffer );
			break;

		case 4:
			ListPeople( pBuffer );
			break;

		case 5:
			printf( "\nSaindo...\n" );
			free( pBuffer );
			return 0;

		default:
			printf( "Opcao inválida.\n" );
		}
	}

	return 0;
}

void AddPerson( void** ppBuffer ) {

	int* count = ( int* )( *ppBuffer );

	// Área temporária no buffer para guardar os dados antes de salvar
	char* tempName	= ( char* )( *ppBuffer ) + sizeof( int ) * 2 + sizeof( size_t );
	int*  tempAge	= ( int* )( tempName + NAME_MAX );
	char* tempEmail = ( char* )( tempAge + 1 );

	printf( "\nNome: " );
	fgets( tempName, NAME_MAX, stdin );
	tempName[strcspn( tempName, "\n" )] = '\0';

	printf( "Email: " );
	fgets( tempEmail, EMAIL_MAX, stdin );
	tempEmail[strcspn( tempEmail, "\n" )] = '\0';

	printf( "Idade: " );
	while( scanf( "%d", tempAge ) != 1 ) {
		while( getchar() != '\n' )
			;
		printf( "Idade invalida. Digite um numero: " );
	}
	getchar();

	// Aumentar o buffer para caber mais uma pessoa
	size_t* peopleDataSize = ( size_t* )( ( char* )*ppBuffer + sizeof( int ) * 2 );

	char* people  = ( char* )( *ppBuffer ) + AREA_FIXA;
	void* listEnd = ( char* )( *ppBuffer ) + AREA_FIXA + *peopleDataSize;

	while( people < ( char* )listEnd ) {
		char* name	= ( char* )people + sizeof( int );
		char* email = ( char* )( name + strlen( name ) + 1 );
		char* next	= ( char* )( email + strlen( email ) + 1 );

		if( strcmp( email, tempEmail ) == 0 ) {
			printf( "\nJa existe uma pessoa com este email!\n" );
			return;
		}
		people = next;
	}

	*ppBuffer = realloc( *ppBuffer, AREA_FIXA + *peopleDataSize + sizeof( int ) + strlen( tempName ) + 1 + strlen( tempEmail ) + 1 );

	if( !( *ppBuffer ) ) {
		printf( "Erro ao realocar memória.\n" );
		exit( 1 );
	}

	// Atualizar ponteiros após realloc (endereço pode ter mudado)
	count		   = ( int* )( *ppBuffer );
	peopleDataSize = ( size_t* )( ( char* )*ppBuffer + sizeof( int ) * 2 );
	tempName	   = ( char* )( *ppBuffer ) + sizeof( int ) * 2 + sizeof( size_t );
	tempAge		   = ( int* )( tempName + NAME_MAX );
	tempEmail	   = ( char* )( tempAge + 1 );

	// Posição onde a nova pessoa será salva
	char* newPerson = ( char* )( *ppBuffer ) + AREA_FIXA + *peopleDataSize;

	memcpy( newPerson, tempAge, sizeof( int ) );
	memcpy( newPerson + sizeof( int ), tempName, strlen( tempName ) + 1 );
	memcpy( newPerson + sizeof( int ) + strlen( tempName ) + 1, tempEmail, strlen( tempEmail ) + 1 );

	*peopleDataSize += sizeof( int ) + strlen( tempName ) + 1 + strlen( tempEmail ) + 1;

	( *count )++;

	printf( "\nPessoa adicionada com sucesso!\n" );
}

void DeletePerson( void** ppBuffer ) {
	int* count = ( int* )( *ppBuffer );
	if( *count == 0 ) {
		printf( "\nNenhuma pessoa cadastrada.\n" );
		return;
	}

	char* tempEmail = ( char* )( *ppBuffer ) + sizeof( int ) * 2 + sizeof( size_t ) + NAME_MAX + sizeof( int );

	printf( "\nDigite o email da pessoa a remover: " );
	fgets( tempEmail, EMAIL_MAX, stdin );
	tempEmail[strcspn( tempEmail, "\n" )] = '\0';

	size_t* peopleDataSize = ( size_t* )( ( char* )*ppBuffer + sizeof( int ) * 2 );
	char*	people		   = ( char* )( *ppBuffer ) + AREA_FIXA;
	void*	listEnd		   = ( char* )( *ppBuffer ) + AREA_FIXA + *peopleDataSize;

	while( people < ( char* )listEnd ) {
		int*  age	= ( int* )people;
		char* name	= ( char* )people + sizeof( int );
		char* email = ( char* )( name + strlen( name ) + 1 );
		char* next	= ( char* )( email + strlen( email ) + 1 );

		if( strcmp( email, tempEmail ) == 0 ) {
			printf( "\nPessoa encontrada e removida.\n" );

			size_t* peopleSize = ( size_t* )( ( char* )*ppBuffer + sizeof( int ) * 2 + sizeof( size_t ) + NAME_MAX );
			*peopleSize		   = sizeof( int ) + strlen( name ) + 1 + strlen( email ) + 1;

			memmove( people, next, ( char* )listEnd - ( char* )next );

			( *count )--;
			*peopleDataSize -= *peopleSize;

			*ppBuffer = realloc( *ppBuffer, AREA_FIXA + *peopleDataSize );
			if( !( *ppBuffer ) && *peopleDataSize > 0 ) {
				printf( "Erro ao realocar memória.\n" );
				return;
			}
			return;
		}
		people = next;
	}
	printf( "\nPessoa nao encontrada.\n" );
}

void ListPeople( void* pBuffer ) {
	int* count = ( int* )pBuffer;

	if( *count == 0 ) {
		printf( "\nNenhuma pessoa cadastrada.\n" );
		return;
	}

	printf( "\n--- LISTA DE PESSOAS ---\n" );

	size_t* peopleDataSize = ( size_t* )( ( char* )pBuffer + sizeof( int ) * 2 );
	char*	people		   = ( char* )pBuffer + AREA_FIXA;
	void*	listEnd		   = ( char* )pBuffer + AREA_FIXA + *peopleDataSize;

	while( people < ( char* )listEnd ) {
		int*  age	= ( int* )people;
		char* name	= ( char* )people + sizeof( int );
		char* email = ( char* )( name + strlen( name ) + 1 );
		char* next	= ( char* )( email + strlen( email ) + 1 );

		printf( "\nPessoa:\n" );
		printf( "Nome : %s\n", name );
		printf( "Idade: %d\n", *age );
		printf( "Email: %s\n", email );

		people = next;
	}
}

void PrintPerson( void* pBuffer ) {
	int* count = ( int* )pBuffer;

	if( *count == 0 ) {
		printf( "\nNenhuma pessoa cadastrada.\n" );
		return;
	}

	char* tempEmail = ( char* )pBuffer + sizeof( int ) * 2 + sizeof( size_t ) + NAME_MAX + sizeof( int );

	printf( "\nDigite o email para buscar: " );
	fgets( tempEmail, EMAIL_MAX, stdin );
	tempEmail[strcspn( tempEmail, "\n" )] = '\0';

	size_t* peopleDataSize = ( size_t* )( ( char* )pBuffer + sizeof( int ) * 2 );
	char*	people		   = ( char* )pBuffer + AREA_FIXA;
	void*	listEnd		   = ( char* )pBuffer + AREA_FIXA + *peopleDataSize;

	while( people < ( char* )listEnd ) {
		int*  age	= ( int* )people;
		char* name	= ( char* )people + sizeof( int );
		char* email = ( char* )( name + strlen( name ) + 1 );
		char* next	= ( char* )( email + strlen( email ) + 1 );

		if( strcmp( email, tempEmail ) == 0 ) {
			printf( "\n--- PESSOA ENCONTRADA ---\n" );
			printf( "\nNome : %s\n", name );
			printf( "Idade: %d\n", *age );
			printf( "Email: %s\n", email );
			return;
		}
		people = next;
	}
	printf( "\nPessoa nao encontrada.\n" );
}