#include <stdio.h>
#include <stdlib.h>

int** generateMatrix ( int n, int* returnSize, int** returnColumnSizes ) {
    int** matrix = ( int** ) malloc( n * sizeof ( int* ));
    int i, j;
    for ( i = 0; i < n; i++ ) {
        matrix [ i ] = ( int* ) malloc( n * sizeof ( int ));
    }

    *returnSize = n;
    *returnColumnSizes = ( int* ) malloc( n * sizeof ( int ));
    for ( i = 0; i < n; i++ ) {
        ( *returnColumnSizes )[ i ] = n;
    }

    int num = 1;
    int passos = n; 
    int row = 0;
    int col = 0;
    int total = n * n;

    while ( num <= total ) {

        for ( j = 0; j < passos && num <= total; j++ ) {
            matrix [row][col] = num;
            num++;
            col++;
        }
        col--;
        row++;

        for ( j = 0; j < passos - 1 && num <= total; j++ ) {
            matrix [row][col] = num;
            num++;
            row++;
        }
        row--;
        col--;

        for ( j = 0; j < passos - 1 && num <= total; j++ ) {
            matrix [row][col] = num;
            num++;
            col--;
        }
        col++;
        row--;

        for ( j = 0; j < passos - 2 && num <= total; j++ ) {
            matrix [row][col] = num;
            num++;
            row--;
        }
        row++;
        col++;

        passos = passos - 2; 
    }

    return matrix;
}

void imprimirMatriz ( int** matrix, int n ) {
    int i, j;
    for ( i = 0; i < n; i++ ) {
        for ( j = 0; j < n; j++ ) {
            printf ( "%d ", matrix[i][j] );
        }
        printf( "\n" );
    }
}

int main() {
    int returnSize;
    int* returnColumnSizes;
    int i;

    printf ( "Exemplo 1 (n = 3):\n" );
    int** matrix1 = generateMatrix ( 3, &returnSize, &returnColumnSizes);
    imprimirMatriz ( matrix1, 3 ); 

    for ( i = 0; i < returnSize; i++ ) 
    free ( matrix1[i] );
    free( matrix1 );
    free( returnColumnSizes );

    printf ( "\n" );

    printf ( "Exemplo 2 (n = 1):\n" );
    int** matrix2 = generateMatrix ( 1, &returnSize, &returnColumnSizes );
    imprimirMatriz ( matrix2, 1 );

    for ( i = 0; i < returnSize; i++ ) 
    free ( matrix2[i] );
    free ( matrix2 );
    free ( returnColumnSizes );

    printf ( "\n" );

    printf ( "Exemplo 3 (n = 4):\n");
    int** matrix3 = generateMatrix ( 4, &returnSize, &returnColumnSizes );
    imprimirMatriz ( matrix3, 4 );

    for ( i = 0; i < returnSize; i++ ) 
    free ( matrix3[i] );
    free ( matrix3 );
    free ( returnColumnSizes );

    return 0;
}