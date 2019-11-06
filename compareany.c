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
void printsll(struct SinglyLLNode*);
bool compareLL(struct SinglyLLNode*, struct SinglyLLNode*);

typedef struct SinglyLLNode {
   int data;
   struct SinglyLLNode* next;
} slln;

//slln *head = NULL;

typedef struct SinglyLinkedList {
   slln *head;
} sll;

int main()
{
  int   n;
  int   d;

  //Head pointer memory creation
  sll*  llist1 = malloc(sizeof(sll));
  if(NULL == llist1) {
    printf("out of memory\n");
    return -1;
  }
  memset(llist1, 0, sizeof(sll));

  llist1->head = NULL;

  printf("Enter the number of nodes to be inserted in list 1 \n");
  scanf("%d", &n);

  printf("enter elements");

  for (int i = 0; i < n; i++) {
     scanf("%d", &d);
     slln* llist_head1 = insertNodeAtTail(&(llist1->head), d);
     llist1->head = llist_head1;
  }

  sll* llist2 = malloc(sizeof(sll));
  if(NULL == llist2) {
     printf("out of memory\n");
     return -1;
  }

  memset(llist2, 0, sizeof(sll));
  llist2->head = NULL;

  printf("Enter number of nodes to be inserted in list 2 \n");
  scanf("%d", &n);

  printf("enter elements ..");

  for (int i = 0; i < n; i++) {
    scanf("%d", &d);
    slln* llist_head2 = insertNodeAtTail(&(llist2->head), d);
    llist2->head = llist_head2;
  }

  bool istrue = compareLL(llist1->head, llist2->head);
  printf("%d\n", istrue);
}

bool compareLL(slln* head1, slln* head2)
{
  slln* h = head2;
  bool present = false;
  while(head1 != NULL) {
    h = head2;
    present = false;
    while(h != NULL) {
      if (head1->data == h->data) {
        present = true;
        break;
      } else {
        h = h->next;
      }
    }
    if (present != true) {
      return false;
    } else {
      head1 = head1->next;
    }
  }
  return present;
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

void printsll(slln* head) {
    while(head != NULL) {
       printf("%d\n", head->data);
       head = head->next;
    }
}


