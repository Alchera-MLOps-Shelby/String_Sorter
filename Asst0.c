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

  //printf("enter main\n");

  //Check for correct input format. Upon incorrect entry, notification of false input and correct format is output.
  if(argc != 2)
  {
    printf("False input. Correct format: ./pointersorter \"<input>\"\n");
    return 0;
  }
  //Below are self-documenting variables.
  char *sentence = NULL;
  char *word;
  char delimiters[] = " 1234567890!@#$%^&*()`~-_=+[{]}|;:',<.>/?\\";
  int inputStringLength = strlen(argv[1]);
  int tokenArrayIndex = 0;
  int tokenCount = 0;
  int sortHelpingVariable = 0;
  char *tokenArray[inputStringLength];
  char *temporaryVariable = "";
  
  //printf("variables init\n");

  //Allocate memory of size of the input string's length to "sentence".
  sentence = (char*) malloc(sizeof(inputStringLength));

  //printf("malloc sentence\n");
  
  //Copy the input string into sentence to prevent changing of argv[1].
  strcpy(sentence, argv[1]);

  //printf("sentence gets string characters\n");
  
  //Allocate memory of same size as before to "word" since the number of words in a given string will never exceed the number of characters given in the same string.
  word = (char*)malloc(sizeof(sentence));

  //printf("malloc word\n");
  
  //Tokenize the sentence and store first token into "word".
  word = strtok(sentence, delimiters);

  //printf("tokenize sentence into word\n");
  
  //Traverse through the rest of the tokens and return null pointer once done.
  while(word != NULL)                   
  {
    tokenArray[tokenArrayIndex] = word;
    word = strtok(NULL, delimiters);
    tokenArrayIndex++;
    tokenCount++;
  }

  //printf("%d\n", tokenCount);

  //printf("print out tokens\n");
  //for(int i = 0; i < tokenCount; i++) {
  //  printf("%s\n", tokenArray[i]);
  //}

  //printf("enter sort\n");
  
  //Sort tokens by comparing subsequent values and switching if the 2nd token is alphabetically higher (Example: a over f).

   for(tokenArrayIndex = 0; tokenArrayIndex < tokenCount; tokenArrayIndex++)       
   {
     for(sortHelpingVariable = tokenArrayIndex + 1; sortHelpingVariable < tokenCount; sortHelpingVariable++) 
     {
       if(strcmp(tokenArray[tokenArrayIndex], tokenArray[sortHelpingVariable]) > 0)
       {
         temporaryVariable = tokenArray[tokenArrayIndex];
         tokenArray[tokenArrayIndex] = tokenArray[sortHelpingVariable];
         tokenArray[sortHelpingVariable] = temporaryVariable;
       }
     }
  }
  //printf("exit sort\n");

  //printf("print out sorted tokens\n");
  //for(int j = 0; j < tokenCount; j++) {
  //  printf("%s\n", tokenArray[j]);
  //}

  //printf("start printing\n");
  
  //Print out all the words.
  for(tokenArrayIndex = 0; tokenArrayIndex < tokenCount; tokenArrayIndex++)
  {
    printf("%s\n", tokenArray[tokenArrayIndex]);
    //printf("printed token\n");
  }
  //printf("exit main\n");
  free(word);
  free(sentence);
  return 0;
}
