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

  printf("enter main\n");

  //Check for correct input format. Upon incorrect entry, notification of false input and correct format is output.
  if(argc != 2)
  {
    printf("False input. Correct format: ./pointersorter \"<input>\"\n");
    return 0;
  }
  //Below are self-documenting variables.
  char *sentence = NULL;
  char *word = NULL;
  char delimiters[] = " 1234567890!@#$%^&*()`~- _=+[{]}|;:',<.>/?\\";
  int inputStringLength = strlen(argv[1]);
  int tokenArrayIndex = 0;
  int tokenCount = 0;
  int sortHelpingVariable = 0;
  int parsingHelperVariable = 0;
  char *tokenArray[inputStringLength];
  char *temporaryVariable = "";
  
  printf("variables init\n");

  //Allocate memory of size of the input string's length to "sentence".
  sentence = (char*) malloc(sizeof(argv[1])); // FIX*************?

  printf("malloc sentence\n");
  
  //Copy the input string into sentence to prevent changing of argv[1].
  strcpy(sentence, argv[1]);

  printf("sentence gets string characters\n");
  
  //Allocate memory of same size as before to "word" since the number of words in a given string will never exceed the number of characters given in the same string.
  word = (char*)malloc(sizeof(sentence));

  printf("malloc word\n");

  tokenArray[tokenArrayIndex] = (char*)malloc(sizeof(sentence));// FIX*************?

  printf("malloc tokenArray[tokenArrayIndex]\n");  
  
  temporaryVariable = (char*)malloc(sizeof(sentence));

  printf("malloc temporaryVariable\n");
  
  //Tokenize the sentence and store first token into "word".
  word = strtok(sentence, delimiters);

  printf("tokenize sentence into word\n");
  int count = 0;
  //Traverse through the rest of the tokens and return null pointer once done.
  while(count < inputStringLength)                   
  {
    printf("In While\n");
    printf("At start of while: count(%d) < inputStringLength(%d)\n", count, inputStringLength); 
    
    if(word != NULL)
    {  
     tokenArray[tokenArrayIndex] = word;
     printf("TokenArray[tokenArrayIndex(%d): %s\n", tokenArrayIndex, tokenArray[tokenArrayIndex]);
     count = count + strlen(word);
     printf("count = count + strlen(word): %d\n", count);
    }
    if(word != NULL)
    {  
     word = strtok(NULL, delimiters);
     printf("Normal Word: %s\n", word);
    }
    if(word == NULL)
    {
     printf("in word == NULL(important)\n");
     parsingHelperVariable = isalpha(sentence[count]);
     printf("parsingHelperVariable(%d)\n", parsingHelperVariable);
     printf("sentence[count]: %c\n", sentence[count]);
     if(parsingHelperVariable != 0)
     {
      printf("in parsingHelperVariable != 0 if statment\n");
      word = strtok(NULL, delimiters);
      printf("Word: %s\n", word);
      printf("end if%s\n");
     }
    }
    if(word != NULL)
    {
    tokenArrayIndex++;
    printf("tokenArrayIndex: %d\n", tokenArrayIndex);
    tokenCount++;
    printf("tokenCount: %d\n", tokenCount);
    }
    if(word == NULL)
    count++;
    printf("At end of while: count(%d) < inputStringLength(%d)\n", count, inputStringLength);
  }


  printf("%d\n", tokenCount);

  printf("print out tokens\n");
  int i = 0;
  for(i = 0; i < tokenCount; i++) {
    printf("%s\n", tokenArray[i]);
  }

  printf("enter sort\n");
  
  //Sort tokens by comparing subsequent values and switching if the 2nd token is alphabetically higher (Example: a over f).

   for(tokenArrayIndex = 0; tokenArrayIndex < tokenCount+1; tokenArrayIndex++)       
   {
    printf("In outter for loop\n");
     for(sortHelpingVariable = tokenArrayIndex + 1; sortHelpingVariable < tokenCount+1; sortHelpingVariable++) 
     {
      printf("In inner for loop\n");
       if(strcmp(tokenArray[tokenArrayIndex], tokenArray[sortHelpingVariable]) > 0)
       {
         printf("in if statment\n");
         printf("tokenArray[tokenArrayIndex(%d)], tokenArray[sortHelpingVariable(%d)] > 0: %s, %s\n", tokenArrayIndex, sortHelpingVariable, tokenArray[tokenArrayIndex], tokenArray[sortHelpingVariable]);
         temporaryVariable = tokenArray[tokenArrayIndex];
         printf("temporaryVariable: %s\n", temporaryVariable );
         tokenArray[tokenArrayIndex] = tokenArray[sortHelpingVariable];
         printf("tokenArray[tokenArrayIndex(%d)]%s\n",tokenArrayIndex, tokenArray[tokenArrayIndex]);
         tokenArray[sortHelpingVariable] = temporaryVariable;
         printf("tokenArray[sortHelpingVariable(%d)]: %s\n",sortHelpingVariable, tokenArray[sortHelpingVariable]);
         printf("Made to end of if\n");
       }
     }
  }
  printf("exit sort\n");

  printf("print out sorted tokens\n");
  int j = 0;
  for(j = 0; j < tokenCount; j++) {
    printf("%s\n", tokenArray[j]);
  }

  printf("start printing\n");
  
  //Print out all the words.
  for(tokenArrayIndex = 0; tokenArrayIndex < tokenCount; tokenArrayIndex++)
  {
    printf("%s\n", tokenArray[tokenArrayIndex]);
    printf("printed token\n");
  }
  printf("exit main\n");
  free(word);
  free(sentence);
  //free(temporaryVariable);
  return 0;
}