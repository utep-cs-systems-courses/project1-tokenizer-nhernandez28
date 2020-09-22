#include "history.h"
#include "tokenizer.h"
#include <stdio.h>

int main()
{
  printf("Welcome!");
  printf("To tokenize a string enter '1'.\n");
  printf("To print string history enter '2'.\n");
  printf("To exit please enter '-1'\n");

  char in[80];
  List *list = init_history();
  
  char userChoice;
  int choiceTwo;

  while(userChoice != -1)
    {
      printf("To tokenize a string enter '1':\n");
      printf("To print string history enter '2':\n");
      printf("To exit enter '-1'\n");

      scanf("%d", &userChoice);

      if(userChoice == 1)
	{
	  printf("Please enter the string(s) you would like to tokenize:\n");
	  fgets(in, 150, stdin);
	  add_history(list, in);

	  //Tokenizes the sentence the user inputs
	  char **tokens = tokenize(in);

	  print_tokens(tokens);
	  free_tokens(tokens);

	  //Counts the all the words in the sentence.
	  int totalWords = count_words(in);

	  printf("The total number of words in the sentence is %d", totalWords);
	  printf("\n");

	  //Gets the first word in sentence.
	  char *p = word_start(in);

	  printf("This sentence begins with %c", p);
	  printf("\n");
	  
	}

      if(userChoice == 2)
	{
	  printf("Printing string history...\n");
	  print_history(list);

	  printf("Either select a string number to print or enter '-1' to go back.\n");
	  scanf("%d", &choiceTwo);

	  if(choiceTwo != -1)
	    {
	      //Will find specific string in history and print it.
	      char **token = tokenize(get_history(list, choiceTwo));
	      
	      print_tokens(token);
	      free_tokens(token);
	    }
	}
    }

  if(userChoice == -1)
    {
      printf("Now exiting... Goodbye!\n");
      free_history(list);
    }
  
  return 0;
}
