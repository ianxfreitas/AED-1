#include <stdio.h>

void abertura(int n) {
	printf("Tabuada do %d\n\n", n);
}

int main(){
 int n;
 
 printf("Digite um numero inteiro ate 10: ");
 scanf("%d", &n);
 printf("\n");
 
 abertura(n);

 for ( int i = 1; i <= 10; i++){
	printf("%d * %d = %d\n", n, i, n * i);
	}
	return 0;
}
		 