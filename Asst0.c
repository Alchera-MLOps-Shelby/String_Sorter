/*
 *Daniel Finlay
 *Seong Sohn
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>

int main(int argc, char* argv[]) 
{

  //Below are self-documenting variables.
  int inputStringIndex = 0;
  char *inputString = argv[1];
  char *sentence = "";
  char *word = "";
  char delimiters[] = " 1234567890!@#$%^&*()`~-_=+[{]}\\|;:',<.>/?\n\t\r\v\f";
  int inputStringLength = strlen(argv[1]);
  int sentenceIndex = 0;
  int tokenArrayIndex = 0;
  int tokenCount = 1;
  int sortHelpingVariable = 0;
  char *tokenArray[inputStringLength];
  char *temporaryVariable = "";
 
  //Check for correct input format. Upon incorrect entry, notification of false input and correct format is output.
  if(argc != 2)
  {
    printf("False input. Correct format: ./pointersorter \"<input>\"\n");
    return 0;
  }

  //Allocate memory of size of the input string's length to "sentence".
  sentence = (char*) malloc(sizeof(inputStringLength));

  //Copy the input string into sentence to prevent changing of argv[1].
  strcpy(sentence, argv[1]);

  //Allocate memory of same size as before to "word" since the number of words in a given string will never exceed the number of characters given in the same string.
  word = (char*)malloc(sizeof(sentence));

  //Tokenize the sentence and store first token into "word".
  word = strtok(sentence, delimiters);

  //Traverse through the rest of the tokens and return null pointer once done.
  while(word != NULL)                   
  {
    tokenArray[tokenArrayIndex] = word;
    word = strtok(NULL, delimiters);
    tokenArrayIndex++;
    tokenCount++;
  }

  //Sort tokens by comparing subsequent values and switching if the 2nd token is alphabetically higher (Example: a over f).
  for(tokenArrayIndex = 0; tokenArrayIndex < tokenCount; tokenArrayIndex++)       
  {
    for(sortHelpingVariable = tokenArrayIndex + 1; sortHelpingVariable < tokenCount; sortHelpingVariable++) 
    {
      if(strcmp(tokenArray[tokenArrayIndex], tokenArray[sortHelpingVariable]) > 0)
      {
        strcpy(temporaryVariable, tokenArray[tokenArrayIndex]);
        strcpy(tokenArray[tokenArrayIndex], tokenArray[sortHelpingVariable]);
        strcpy(tokenArray[sortHelpingVariable], temporaryVariable);
      }
    }
  }

  //Print out all the words.
  for(tokenArrayIndex = 0; tokenArrayIndex < tokenCount; tokenArrayIndex++)
  {
    printf("%s\n", tokenArray[tokenArrayIndex]);
  }
  return 0;
}
