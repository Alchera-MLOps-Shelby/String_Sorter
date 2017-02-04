#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>

//Identity: every string inputted is outputted
//Uniqueness: each distinct string is outputted

// To append character by character until a token is hit & then terminate to a string
void append(char* s, char c)
{
  int len = strlen(s);
  s[len] = c;
  s[len + 1] = '\0';
}

int main(int argc, char* argv[]) // argc = # args on command line //argv[] values at locations 
{
  int index = 1;                 // For iterating through command line arguments
  char *sentence = NULL;         // To store a whole string at each argv[index]
  char *word = NULL;             // To store each word separated by tokens
  char *letter = NULL;           // To go letter by letter through a sentence until a token is hit, then terminate into a word & sort in linked list
  char *tokenArray = 
  int length = 0;                // to get length of argv[index]
  int iterateStr = 0;            // To iterate through a "sentence"
  int tokenFound = 1;            // True = 0, False = 1 // Boolean to tell if a token has been found
 
  if(argc != 2) {
    printf("False input. Correct format: ./pointersorter \"<input>\"\n");
    return 0;
  }

 for(index = 1; index < argv[1]; index++)               // Iterate through each element on command line
 {
   length = strlen(argv[index]);                    // Get Length of each input
   sentence = (char*) malloc(sizeof(argv[index]));  // Allocate the memory for the size of a sentence at "index"
   strcpy(sentence, argv[index]);                   // Copy the command line string into a char array named "sentence"
   word = (char*)malloc(sizeof(sentence));          // Allocate enough memory in case the sentence is one word   
   
   while(iterateStr < length)                       // Iterate through the sentence & concatenate each letter until a token is found, then sort it. If no Token found then sort & move on to next sentence at top of for loop
   {
    letter = sentence[iterateStr];                  // Iterate string char by char until token found and store in letter
    tokenFound = isalpha(letter);                   // Test letter by letter whether it is alphabetic
    if(tokenFound == 0)                             // Is a token
    {
      free(word);                                   // Free allocated memory
      word = (char*)malloc(sizeof(sentence));       // Allocate memory for next word
    }
    else                                            // Is a letter
    {
     append(word, letter);                          // Add each letter to the word until a token is hit or the end of the sentence is reached
    }
   
    iterateStr++;                                   // Go to next letter in sentence
   }
   printf("%s\n", word);                            // JUST TO SEE HOW IT'S WORKING SO FAR************// "COMMENT"
   iterateStr = 0;                                  // New sentence: reset to 0
  }
}

