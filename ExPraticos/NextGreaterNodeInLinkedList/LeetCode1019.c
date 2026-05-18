#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int				 val;
	struct ListNode* next;
};

int* nextLargerNodes( struct ListNode* head, int* returnSize ) {
	int count = 0;

	struct ListNode* ptr = head;
	while( ptr != NULL ) {
		count++;
		ptr = ptr->next;
	}

	*returnSize = count;
	int* result = ( int* )malloc( count * sizeof( int ) );

	ptr	  = head;
	int i = 0;
	while( ptr != NULL ) {
		int nextGreater = 0;

		struct ListNode* temp = ptr->next;
		while( temp != NULL ) {
			if( temp->val > ptr->val ) {
				nextGreater = temp->val;
				break;
			}
			temp = temp->next;
		}

		result[i] = nextGreater;
		i++;
		ptr = ptr->next;
	}

	return result;
}

int main() {

	struct ListNode n3 = { 5, NULL };
	struct ListNode n2 = { 1, &n3 };
	struct ListNode n1 = { 2, &n2 };

	int	 returnSize = 0;
	int* result		= nextLargerNodes( &n1, &returnSize );

	for( int i = 0; i < returnSize; i++ ) {
		printf( "%d ", result[i] );
	}
	printf( "\n" );

	free( result );
	return 0;
}