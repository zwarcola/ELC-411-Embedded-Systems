#include <stdio.h>
#include <stdlib.h>

int strlen(char* str)                   //Procedure to find string length
{
    int length = 0;
    while(str[length] != '\0')
    {
        length++;
    }
    return length;
}

int strcmp(char *s1, char *s2)          //Procedure to take in 2 strings and compare
{
    char *start1 = s1;                  //Define all necessary items
    char *start2 = s2;
    int length1 = strlen(s1);
    int length2 = strlen(s2);
    int lengthFinal;

    if(length1 > length2)               //Compare length of strings to determine how far to traverse
    {
        lengthFinal = length1;
    }
    else
    {
        lengthFinal = length2;
    }

    for(int i = 0; i <= lengthFinal; i++) //for loop to traverse through length of string
    {
        if((*start1 != *start2) && (*start1 < *start2)) //compare to check if first string has smaller value than second
        {
            return -1;
        }
        else if((*start1 != *start2) && (*start1 > *start2)) //compare to check if second string has smaller value than first
        {
            return 1;
        }
        else if((*start1 == '\0') && (*start2 == '\0')) //if both are null at the same time, we have reached the end and the strings are equal
        {
            return 0;
        }
        start1++; //shift pointer by 1 if all values are the same AND not null
        start2++;
    }
}

int main()
{
    char str1[] = "Hello";              //Define two strings to compare and call function
    char str2[] = "HelloOoOoOo";
    printf("%d", strcmp(str1, str2));
}
