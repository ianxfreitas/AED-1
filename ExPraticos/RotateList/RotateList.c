#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// funcao principal que rotaciona a lista k vezes pra direita
struct ListNode* rotateRight ( struct ListNode* head, int k ) {

    // se a lista eh vazia ou tem so um elemento, retorna ela mesmo
    if ( head == NULL || head->next == NULL ) {
        return head;
    }
    
    // conta quantos nos tem na lista e guarda o ultimo no
    int    listSize = 1;
    struct ListNode* lastNode = head;

    while ( lastNode->next != NULL ) {
        lastNode = lastNode->next;
        listSize++;
    }

    // otimiza k usando modulo, porque rotacionar listSize vezes eh igual a nao rotacionar
    k = k % listSize;

    // se k deu zero depois do modulo, nao precisa fazer nada
    if ( k == 0 ) {
        return head;
    }

    // calcula em qual posicao fica o novo tail 
    int    stepsToNewTail = listSize - k - 1;
    struct ListNode* newTail = head;

    // anda ate o novo tail
    for ( int step = 0; step < stepsToNewTail; step++ ) {
        newTail = newTail->next;
    }

    // salva o novo head, corta a lista e reconecta o final com o inicio
    struct ListNode* newHead = newTail->next;
    newTail->next =  NULL;
    lastNode->next = head;

    return newHead;
}

// imprime a lista no formato [1,2,3,4,5]
void printList ( struct ListNode* head ) {
    printf ( "[" );
    while ( head != NULL ) {
        printf ( "%d", head->val );
        if ( head->next != NULL ) printf ( "," );
        head = head->next;
    }
    printf ( "]\n" );
}

int main () {
    // cria os nos estaticamente (sem malloc)
    struct ListNode n5 = {5, NULL};
    struct ListNode n4 = {4, &n5};
    struct ListNode n3 = {3, &n4};
    struct ListNode n2 = {2, &n3};
    struct ListNode n1 = {1, &n2};
    
    struct ListNode* head = &n1;
    
    printf ( "Lista original: ");
    printList ( head );
    
    // chama a funcao pra rotacionar 2 vezes
    head = rotateRight ( head, 2 );
    
    printf ( "Apos rotacao:   " );
    printList ( head );
    
    return 0;
}