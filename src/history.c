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

/* Add a history item to the end of the list. 
List *list - the linked list
char *str - the string to store */
void add_history(List *list, char *str)
{
  char *copy;
  char *end = str;
  
  while(*end != '\0')
    {
      end++;
    }
  
  int len = end - str - 1;
  char *copy = copy_str(str, len);

  if (list->root == NULL)
    {
      list->root = (Item*) malloc(sizeof(Item));
      list->root->id = 1;
      list->root->str = copy;
      list->root->next = NULL;
    }
  else
    {
      Item *temp;
      temp = list->root;

      while(temp->next != NULL)
	{
	  temp = temp->next;
	}

      temp->next = (Item*) malloc(sizeof(Item));
      temp->next->id = temp->id + 1;
      temp->next->str = copy;
      temp->next->next = NULL;
    }
}

/* Retrieve the string stored in the node where Item->id == id.
List *list - the linked list
int id - the id of the Item to find */
char *get_history(List *list, int id)
{
  Item *tempt = list->root;
  
  while(temp != NULL)
    {
      if(temp->next == NULL)
	{
	  return "OutOfBounds";
	}
      else if(temp->id == id)
	{
	  return temp->str;
	}
      else
	{
	  temp = temp->next;
	}
    }
}

// Print the entire contents of the list.
void print_history(List *list)
{
  Item *temp == list->root;

  while(temp != NULL)
    {
      printf("%d.-%s \n", temp->id, temp->str);
      temp = temp->next;
    }
}

//Free the history list and the strings it references.
void free_history(List *list)
{
  Item *temp == list->root;

  while(temp != NULL)
    {
      free(temp->str);
      free(temp);
      temp = temp->next;
    }
  
  free(list);
}
