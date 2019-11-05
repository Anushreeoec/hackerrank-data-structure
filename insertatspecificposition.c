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
struct SinglyLLNode* insertNodeAtHead(struct SinglyLLNode**, int);
void insertNodeAtSpecificPosition(int, int, struct SinglyLLNode**);
void printsll(struct SinglyLLNode*);

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

  printf("Enter next data to be inserted");
  printf("Enter position of data");

  scanf("%d", &d);
  scanf("%d", &pos);

  insertNodeAtSpecificPosition(d, pos, &(llist->head));

  printsll(llist->head);
}

slln* createANode(int data) {
   slln* node = malloc(sizeof(slln));
   node->data = data;
   node->next = NULL;

   return node;
}

void insertNodeAtSpecificPosition(int d, int pos, slln** head_ref)
{
  slln* new_node;
  new_node = createANode(d);
  slln* cur_node = *head_ref;
  int cur_pos = 0;
  while (cur_node->next != NULL) {
     cur_pos++;
     if (cur_pos == (pos)) {
        break;
     }
     cur_node = cur_node->next;
  }
  if (cur_pos != (pos-1)) {
     printf("Cannot insert");
  } else {
     printf("Inserting..\n");
     slln* tmp_node = malloc(sizeof(slln));
     tmp_node = cur_node->next;
     new_node->next = tmp_node;
     cur_node->next = new_node;
  }
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

void printsll(slln* head) {
    while(head != NULL) {
       printf("%d\n", head->data);
       head = head->next;
    }
}


