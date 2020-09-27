#include "history.h"
#include "tokenizer.h"
#include <stdio.h>

int main()
{
  List *list = init_history();
  char userInput[80], userChoice;
  int choiceTwo;

  printf("Welcome!");
  printf("\n");
  printf("To tokenize a string enter '1'.\n");
  printf("To print string history enter '2'.\n");
  printf("To exit enter '-1'.\n");
  scanf("%d", &userChoice);
  printf("\n");
  
  while(userChoice != -1){
    printf("To tokenize a string keep pressing enter.\n");
    printf("To print string history enter '2'.\n");
    printf("To exit enter '-1'.\n");
    printf("\n");
    
    scanf("%d", &userChoice);
    printf("\n");
    
    if(userChoice == 1){
      printf("\n");
      printf("Please enter the string(s) you would like to tokenize.\n");
      printf("\n");
      
      fgets(userInput, 150, stdin);
      printf("\n");
      
      add_history(list, userInput);

      char ** tokens = tokenize(userInput);
      print_tokens(tokens);
      free_tokens(tokens);

      int totalWords = count_words(userInput);
      printf("The total number of words in the sentence is %d\n", totalWords);

      char *firstWord = word_start(userInput);
      printf("This sentence begins with %c\n", firstWord);
      printf("\n");
    }
      if(userChoice == 2){
	printf("Now printing history...\n");
	print_history(list);

	printf("Select a string number to print. If you wish to go back enter '-1'\n");
	scanf("%d", &choiceTwo);
      
	if(choiceTwo != -1){
	  char **token = tokenize(get_history(list, choiceTwo));
	  print_tokens(token);
	  free_tokens(token);
	}
     }
  }
  if(userChoice == -1){
    printf("Now exiting... Goodbye!");
    free_history(list);
    printf("\n");
  }
  return 0;
}
