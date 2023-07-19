#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"




char **read_words(const char *input_filename, int *nPtr){
	
    char **word_list;        
    /*write your implementation here*/

    int i;

    FILE *myFile = fopen(input_filename, "r");
    fscanf(myFile, "%d", nPtr);

    word_list = (char**)malloc(*nPtr * sizeof(char*));

    for(i = 0; i < *nPtr; i++)
    {
        word_list[i] = (char*)calloc(20, sizeof(char));  // fill with NULL so to be safe
        fscanf(myFile, "%s", word_list[i]);        
    }

    fclose(myFile);

    return word_list;

}

void sort_words_Bubble(char **words, int size)
{   
	/*write your implementation here*/
    int i;    
    int done = 0;

    while(!done)
    {
        done = 1;       
        for(i = 0; i < size - 1; i++)
        { 
            // Swap two elements whenever current element value is larger than the value of the next element.
            if(my_strcmpOrder(words[i], words[i + 1]) == 1)   // when current string is ASCII-wise larger than next string, swap them!
            {
                swap(&words[i], &words[i + 1]);
                done = 0;
            }
        }
    }    
    
}

void swap(char **str1, char **str2)
{    
	/*this is a helper function that you can implement and use to facilitate your development*/
    char* tempStringAddr = *str1;
    *str1 = *str2;
    *str2 = tempStringAddr;
}

void delete_wordTable(char **word_list, int size)
{
    /*This is a helper function that you MUST IMPLEMENT and CALL at the end of every test case*/
    /*THINK ABOUT WHY!!!*/

    // implement your table deletion code here //
    int i;

    for(i = 0; i < size; i++)
        free(word_list[i]);

    free(word_list);
    
}

void sort_words_Selection(char **words, int size){

    // This is the second sorting method implemented in Selection Sort.
    // This implementation contains 2 semantic bugs

    // Fix the code, and document how you've found the bugs using GNU debugger.
    // Take screenshots of the debugger output at the instance where you've determined every bug.

    // You will be tested again at the cross exam.

    int i, j;    
    int min, minIndex;
    
    for(i = 0; i < size; i++)
    {
        minIndex = i;

        for(j = i + 1; j < size; j++)
        {
            // Error 1: Incorrect use of index
            if(my_strcmpOrder(words[i], words[j]) == 1)
            // if(my_strcmpOrder(words[minIndex], words[j]) == 1)
            {
                minIndex = j;
            }                        
        }
       
        // Error 2: Incorrect Check Target
        if(minIndex != j)
        // if(minIndex != i)
        {
            swap(&words[i], &words[minIndex]);
        }

    }
    
}

