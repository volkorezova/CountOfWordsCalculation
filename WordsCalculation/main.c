//
//  main.c
//  WordsCalculation
//
//  Created by Tatyana Volkorezova on 25.10.2017.
//  Copyright © 2017 shpp.com. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE_OF_INPUTED_STRING 1000000
#define SIZE_OF_ALPHABET 26
#define STATE_FALSE 0
#define STATE_TRUE 1

int main() {
    
    int wordsCounter = 0;
    int isItLetter = 0;
    int isItSymbol = 0;
    
    char* inputedString;
    inputedString = (char*) malloc(SIZE_OF_INPUTED_STRING * sizeof(char));
    
    printf("Pls enter any string. We will calculate count of words:\n");
    gets(inputedString);
    fpurge(stdin);
    
    int strLen = strlen(inputedString);
    for (int i = 0; i < strLen; i++){
        for (int j = 0; j < SIZE_OF_ALPHABET; j++){
            if (toupper(inputedString[i]) >= 'A' && toupper(inputedString[i]) <= 'Z'){
                
                isItSymbol = STATE_FALSE;
                isItLetter = STATE_TRUE;
                break;
            }
            else{
                isItSymbol = STATE_TRUE;
            }
        }
        
        if ((isItSymbol == STATE_TRUE) || (i == strLen-1)) {
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











