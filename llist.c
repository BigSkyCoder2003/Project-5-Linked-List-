//llist.c
//Daniel Lounsbury

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "llist.h"

int main(int argc, char *argv[]){
struct node *head = NULL;
struct node *n;
for (int i = 1; i < argc; i++)
{
if (strcmp(argv[i], "ih") == 0){
  n = node_alloc(atoi(argv[i+1]));
  llist_insert_head(&head,n);
  i++;
}
else if(strcmp(argv[i], "it")==0){
  n = node_alloc(atoi(argv[i+1]));
  llist_insert_tail(&head,n);
  i++;
}
else if(strcmp(argv[i], "dh")==0)
{
 llist_delete_head(&head);
}
else if(strcmp(argv[i], "p")==0)
{
llist_print(head);  
}
else if(strcmp(argv[i], "f")==0)
{
llist_free(&head);  
}
else{
  perror("error parsing command. Please recheck input.");
  exit(EXIT_FAILURE);
  }
}
}
 
void llist_insert_head(struct node **head, struct node *n)
{
    if (*head == NULL) {
        *head = n;
    } else {
        n->next = *head;
        *head = n;
    }
}

struct node *llist_delete_head(struct node **head)
{
if (*head == NULL) {
        return NULL;
    }
  else{
    struct node *temp = *head;
    *head = (*head) -> next;  
    temp -> next = NULL;
    return temp;
  }
}

void llist_insert_tail(struct node **head, struct node *n)
{
if (*head == NULL){
  *head = n;
}
else{
  struct node *current = *head;
  while(current->next != NULL)
  {
    current = current-> next;
  }
  current -> next = n;
}
}

void llist_print(struct node *head)
{
  if (head == NULL){
    printf("[empty]\n");
  }
  else{
    struct node *current = head;
    printf("%d",current->value);
    current = current-> next;
    while(current!= NULL)
    {
      printf(" -> %d",current->value);
      current = current-> next;
    }
    printf("\n");
  }
}



void llist_free(struct node **head)
{
  struct node *current = *head;
  struct node *next;
  while(current != NULL)
  {
    next = current->next;
    node_free(current);
    current = next;
  }
  *head = NULL;
}

struct node *node_alloc(int num){
    struct node *new_node = (struct node *)malloc(sizeof(struct node)); 
    new_node->value = num;
    new_node->next = NULL;
    return new_node;
}

void node_free(struct node *n)
{
  free(n);
}