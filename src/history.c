#include "history.h"
#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

/* Initialize the linked list to keep the history. */
List *init_history()
{
  List *head = (List*) malloc(sizeof(List));
  head->root = NULL;

  return head;
}

/* Add a history item to the end of the list. */
void add_history(List *list, char *str)
{
  //copies length of string
  char *stringEnd = str;

  while(*stringEnd != '\0'){
    stringEnd++;
  }

  //uses length of string to obtain exact copy of string
  int stringLen = stringEnd - str - 1;
  char *stringCopy = copy_str(str, stringLen);

  //if no string has not been allocated yet
  if(list->root == NULL){
    list->root = (Item*) malloc(sizeof(Item));
    list->root->next = NULL;
    list->root->str = stringCopy;
    list->root->id = 1;
  }

  //if string has already been allocated to some memory
  else{
    Item *temp_p = list->root;

    //keeps going until reached last allocation saved
    while(temp_p->next != NULL){
      temp_p = temp_p->next;
    }

    //makes new allocation for remaining string
    temp_p->next = (Item*) malloc(sizeof(Item));
    temp_p->next->next = NULL;
    temp_p->next->str = stringCopy;
    temp_p->next->id = temp_p->id + 1;
  }
}

/* Retrieve the string stored in the node where Item->id == id */
char *get_history(List *list, int id)
{
  Item *temp_p = list->root;

  while(temp_p != NULL){
    //if id input matches history id return string
    if(temp_p->id == id){
      return temp_p->str;
    }
    //keeps going until input id is found
    else{
      temp_p = temp_p->next;
    }
  }
}

/* Print the entire contents of the list. */
void print_history(List *list)
{
  Item *temp_p = list->root;

  while(temp_p != NULL){
      printf("%d. %s\n", temp_p->id, temp_p->str);
      temp_p = temp_p->next;
  }
  printf("\n");
}

/* Free the history list and the strings it references. */
void free_history(List *list)
{
  Item *temp_p = list->root;

  while(temp_p != NULL){
      free(temp_p->str);
      free(temp_p);
      temp_p = temp_p->next;
  }
  
  free(list);
}
