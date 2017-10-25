//
//  main.c
//  WordsCalculation
//
//  Created by Tatyana Volkorezova on 25.10.2017.
//  Copyright © 2017 shpp.com. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define SIZE_OF_INPUTED_STRING 1000000
#define ASCII_CODE_UPPER_LETTER_A 65
#define ASCII_CODE_LOWER_LETTER_A 97
#define SIZE_OF_ALPHABET 26
#define STATE_FALSE 0
#define STATE_TRUE 1

int main() {
    
    int wordsCounter = 0;
    int isItLetter = 0;
    int isItSymbol = 0;
    
    char* inputedString;
    inputedString = (char*)malloc(SIZE_OF_INPUTED_STRING * sizeof(char));
    
    printf("Pls enter any string. We will calculate count of words:\n");
    gets(inputedString);
    fpurge(stdin);

    for (int indexOfStringArray = 0; indexOfStringArray < strlen(inputedString); indexOfStringArray++){
        
        for (int indexOfAlphabetArray = 0; indexOfAlphabetArray < SIZE_OF_ALPHABET; indexOfAlphabetArray++){
            if ((inputedString[indexOfStringArray] == indexOfAlphabetArray + ASCII_CODE_UPPER_LETTER_A) || (inputedString[indexOfStringArray] == indexOfAlphabetArray + ASCII_CODE_LOWER_LETTER_A)){
                
                isItSymbol = STATE_FALSE;
                isItLetter = STATE_TRUE;
                break;
            }
            else{
                isItSymbol = STATE_TRUE;
            }
        }
        
        if ((isItSymbol == STATE_TRUE) || (indexOfStringArray == strlen(inputedString)-1)) {
            if (isItLetter == STATE_TRUE){
                wordsCounter++;
                isItLetter = STATE_FALSE;
                isItSymbol = STATE_FALSE;
            }
        }
    }
    
    printf("Count of words is: %d\n", wordsCounter);
    free(inputedString);
    return 0;
}
