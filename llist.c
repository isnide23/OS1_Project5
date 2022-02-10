#include "llist.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  struct node *head = 0;

  for(int position = 1; position < argc; position++) {
    if(strcmp(argv[position], "ih") == 0) {
      int val = atoi(argv[++position]);
      struct node *inserted_node = node_alloc(val);
      llist_insert_head(&head, inserted_node);
    }
    else if(strcmp(argv[position], "it") == 0) {
      int val = atoi(argv[++position]);
      struct node *inserted_node = node_alloc(val);
      llist_insert_tail(&head, inserted_node);
    }
    else if(strcmp(argv[position], "dh") == 0) {
      llist_delete_head(&head);
    }
    else if(strcmp(argv[position], "f") == 0) {
      llist_free(&head);
    }
    else if(strcmp(argv[position], "p") == 0) {
      llist_print(head);
    }
    else { 
      printf("enter a valid command:\n 'ih', 'it', 'dh', 'f', 'p'\n");
      exit(0);
    }
  }
}

struct node *node_alloc(int value) {
  struct node *inserted_node = malloc(sizeof(struct node));

  inserted_node->value = value;
  inserted_node->next = 0;

  return inserted_node;
}

void node_free(struct node *n) {
  free(n);
}

void llist_print(struct node *head) {
  if(head == 0) {
    printf("[empty]");
  }
  else {
    printf("%d", head->value);
    struct node *next_node = head->next;
    while(next_node != 0) {
      printf(" -> %d", next_node->value);
      next_node = next_node->next;
    }
  }

  printf("\n");
}

void llist_insert_head(struct node **head, struct node *n) {
  n->next = *head;
  *head = n;
}

struct node *llist_delete_head(struct node **head) {
  if(*head == 0) {
    return 0;
  }
  else {
    struct node *temp = *head;
    *head = (*head)->next;
    return temp;
  }
}

void llist_insert_tail(struct node **head, struct node *n) {
  if(*head == 0) {
    *head = n;
  }
  else {
    struct node *tail_node = *head;

    while (tail_node->next != 0) {
      tail_node = tail_node->next;
    }
    tail_node->next = n;
  }
}

void llist_free(struct node **head) {
  if(*head == 0) {
    return;
  }
  else {
    struct node *current_node = *head;
    struct node *next_node = current_node->next;

    while(next_node != 0) {
      next_node = current_node->next;
      free(current_node);
      current_node = next_node;
    }
    
    *head = 0;
  }
}