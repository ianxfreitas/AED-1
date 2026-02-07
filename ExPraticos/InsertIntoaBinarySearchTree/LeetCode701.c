#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* insertIntoBST ( struct TreeNode* root, int val ) {
    if ( root == NULL ) {
        struct TreeNode* novo = ( struct TreeNode* ) malloc ( sizeof ( struct TreeNode ));
        novo -> val = val;
        novo -> left = NULL;
        novo -> right = NULL;
        return novo;
    }

    // Decide se vai pra direita ou esquerda
    if ( val > root -> val ) {
        root -> right = insertIntoBST ( root -> right, val );
    } else {
        root -> left = insertIntoBST ( root -> left, val );
    }

    return root;
}

void imprimir ( struct TreeNode* root ) {
    if ( root != NULL ) {
        imprimir ( root -> left );
        printf ( "%d ", root -> val );
        imprimir ( root -> right );
    }
}

int main () {
    struct TreeNode* raiz = NULL;

    raiz = insertIntoBST ( raiz, 4 );
    raiz = insertIntoBST ( raiz, 2 );
    raiz = insertIntoBST ( raiz, 7 );
    raiz = insertIntoBST ( raiz, 1 );
    raiz = insertIntoBST ( raiz, 3 );

    printf ( "Arvore Original: " );
    imprimir ( raiz );
    printf ( "\n" );

    printf ( "Inserindo o 5\n" );
    insertIntoBST ( raiz, 5 );

    printf ( "Resultado Final: " );
    imprimir ( raiz );

    return 0;
}