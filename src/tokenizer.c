#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/*Return true (non-zero) if c is a whitespace character
('\t' or ' ') */
int space_char(char c)
{
  if (c == '\t' || c == ' '){
      return 1;
  }
  else{
      return 0;
  }
}

/* Return true (non-zero) if c is a non-whitespace 
character (not tab or space).
Zero terminators are not printable (therefore false).*/
int non_space_char(char c)
{
  if (c != '\t' && c != ' '){
      return 1;
  }
  else{
      return 0;
  }
}

/* Returns a pointer to the first character of the next 
space-seperated word in zero-terminated str. Return a zero pointer if
str does not contain any words. */
char *word_start(char *str)
{
  int i = 0;
  while(!non_space_char(str[i])){
      i++;
  }
  
  return &str[i];
}

/* Returns a pointer terminator char following *word. */
char *word_terminator(char *word)
{
  while(!space_char(*word)){
      word += 1;
  }
  return word;
}

/* Counts the number of words in the string argument. */
int count_words(char *str)
{
  int count = 0;
  int tempCount = 0;

  while(*str){
      if(*str == '\t' || *str == ' ' || *str == '\n'){
	  tempCount = 0;
      }
      else if(tempCount == 0){
	  tempCount = 1;
	  count++;
      }
      
      str++;
    }
  
  return count;
}

/* Returns a freshly allocated new zero-terminated string
containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len)
{
  char *temp = inStr;
  char *new_string = NULL;

  //Allocates memory for each string.
  new_string = (char*) malloc(sizeof(char) * (len + 1));
  new_string[len] = '\0';

  int index = 0;

  //While the end of the string has not been reached, increses size.
  while(*temp != '\0'){
      new_string[index++] = *temp++;
  }
  
  return new_string;
}

/* Returns a freshly allocated zero-terminated vecto of freshly allocated 
space-seperated tokens from zero-terminated str. */
char **tokenize(char *str)
{
  int numWords = count_words(str);
  char **token;
  int i;
  
  token = (char**) malloc((numWords + 1) * sizeof(char*));

  char *word_starting = str;
  char *word_ending = word_terminator(str);

  //int i goes through each string user inputs.
  for(i = 0; i < numWords; i++){
    if(i > 0){
      word_starting = word_start(word_ending);
      word_ending = word_terminator(word_starting);
    }

    int token_size = word_ending - word_starting;
    token[i] = malloc(token_size * sizeof(char));

    //int j goes through each word/token in the string.
    for(int j = 0; j < token_size; j++){
      token[i][j] = word_starting[j];
    }
  }
  return token;
}

/* Prints all tokens. */
void print_tokens(char **tokens)
{
  int i = 0;

  while(tokens[i] != NULL){
      printf("%s\n", tokens[i]);
      i++;
  }
}

/* Frees all tokens and the vector containg them. */
void free_tokens(char **tokens)
{
  int i = 0;
  
  while(tokens[i]){
      free(tokens[i]);
      i++;
  }
  
  free(tokens);
}
