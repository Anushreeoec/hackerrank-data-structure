/* This program finds the node of linkedlist from tail */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct SinglyLinkedListNode {
      int data;
      struct SinglyLinkedListNode* next;
} slln;

typedef struct SinglyLinkedList {
      struct SinglyLinkedListNode* head;
      struct SinglyLinkedListNode* tail;
} sll;


slln* create_node (int node_data) {
    slln* node = malloc(sizeof(slln));
    node->data = node_data;
    node->next = NULL;
}

void insert_into_ll (sll** sll, int node_data) {
    slln* node = create_node(node_data);

    if (!((*sll)->head)) {
       (*sll)->head = node;
    } else {
        (*sll)->tail->next = node;
    }

    (*sll)->tail = node;
}

slln* deleteduplicate(slln* head)
{
   slln* current = head;

   while(current->next != NULL) {
      if (current->data == current->next->data) {
          current->next = current->next->next;
      } else {
         current = current->next;
      }
   }

   return head;
}

int main() {
    int n, data, m, result;
    printf("Enter the number of nodes to be inserted");
    scanf("%d", &n);

    sll* ll = malloc(sizeof(sll));

    ll->head = NULL;
    ll->tail = NULL;

    for(int i = 0; i < n; i++) {
        scanf("%d", &data);
        insert_into_ll(&ll, data);
    }

    slln* h = deleteduplicate(ll->head);

    slln* current = h;

    while(current != NULL) {
        printf("%d", current->data);
        current = current->next;
    }

    return 0;
}
