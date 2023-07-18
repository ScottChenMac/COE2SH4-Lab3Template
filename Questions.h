#include <stdio.h>
#include <stdlib.h>

//Question 1 definitions and prototypes
int my_strlen(const char * const str1);
int my_strcmp(const char * const str1, const char * const str2);
int my_strcmpOrder(const char * const str1, const char * const str2);
char *my_strcat(const char * const str1, const char * const str2);


//Question 2 definitions and prototypes
char **read_words(const char *input_filename, int *nPtr);
void sort_words(char **words, int size);
void sort2_words(char **words, int size);

// The function below is an example of an utility function that you might need while implementing your sort..
// you do *NOT* have to implement them if you do not need to 
void swap(char **str1, char **str2);

