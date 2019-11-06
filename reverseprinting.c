#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SinglyLLNode* insertNodeAtTail(struct SinglyLLNode**, int);
void reverseprintsll(struct SinglyLLNode*);

typedef struct SinglyLLNode {
   int data;
   struct SinglyLLNode* next;
} slln;

typedef struct SinglyLinkedList {
   slln *head;
} sll;

int main()
{
  int   n;
  int   d,pos;

  //Head pointer memory creation
  sll*  llist = malloc(sizeof(sll));
  if(NULL == llist) {
    printf("out of memory\n");
    return -1;
  }
  memset(llist, 0, sizeof(sll));

  llist->head = NULL;

  printf("Enter the number of nodes to be inserted..");
  scanf("%d", &n);

  printf("Enter %d data", n);

  for (int i = 0; i < n; i++) {
     scanf("%d", &d);
     slln* llist_head = insertNodeAtTail(&(llist->head), d);
     llist->head = llist_head;
  }

  reverseprintsll(llist->head);
}

void reverseprintsll(slln* head) {
  if (head == NULL) {
     return;
  }

  reverseprintsll(head->next);

  printf("%d\n", head->data);

  return;
}

slln* createANode(int data) {
   slln* node = malloc(sizeof(slln));
   node->data = data;
   node->next = NULL;

   return node;
}

slln* insertNodeAtTail(slln** head_ref, int data)
{
  slln* new_node;
  new_node = createANode(data);
  if (*head_ref == NULL) {
     *head_ref = new_node;
  } else {
     slln* node = *head_ref;
     while(node->next != NULL) {
        node = node->next;
     }
     node->next = new_node;
  }
  return *head_ref;
}



