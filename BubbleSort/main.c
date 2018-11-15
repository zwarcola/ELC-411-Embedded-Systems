#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#define NVIC_CPUID_BASE_ADDR 0xE000ED00;              //create definition of NVIC_CPUID_BASE_ADDR
                                                      //using memory address found in prelab pdf

void bubblesort(char name[])                          //algorithm to sort a string by ascending ascii values
{
    int temp;                                         //create temporary int and int to hold value of length
    int length = 0;
    
    while(name[length] != '\0')                       //find length by traversing through until string ends
    {
        length++;
    }
    
    for(int i = 0; i < length - 1; i++)               // Actual sorting of string
    {
        
        for(int j = 0; j < length - 1 - i; j++)       // For loop through the enitre length of the Array
        {
            if(name[j] > name[j+1])
            {
                temp = name[j];                       // Temp variable for character
                name[j] = name[j+1];                  // Swaps characters
                name[j+1] = temp;                     // Sets temp for next iteration
            }
        }
    }
}

int main(void)
{
    // 4.1 ACCESS REGISTER VIA ITS ADDRESS : 0xE000ED00
    // First create all necessary 32 bit numbers
    uint32_t implementer;
    uint32_t variant;
    uint32_t partno;
    uint32_t revision;
    uint32_t reg_val;
    uint32_t volatile * my_reg_ptr;                   // Declare a pointer to a volatile unsigned int
    my_reg_ptr = (uint32_t *) NVIC_CPUID_BASE_ADDR;   // Set pointer to point to our register
    reg_val = *my_reg_ptr;                            // Assign regval to where our pointer is pointing
    
    
    implementer = (reg_val >> 24) & 0xFF;             // Shift address so the rightmost bit for our desired
    variant = (reg_val >> 20) & 0xF;                  // bit string is right aligned, then tell the computer
    partno = (reg_val >> 4) & 0xFFF;                  // what amount of bits to use based on the length of
    revision = (reg_val >> 0) & 0xF;                  // the desired value, then assign to respective 32 bit int
    
    // 4.2 MANIPULATE A CHARACTER STRING
    
    char myname[] = "Zach Warcola and Paul Giordano"; // Create string to be sorted
    bubblesort(myname);                               // Call bubblesort to sort
    printf(myname);                                   // Print sorted string
    
    // Loop forever (do nothing, for this assignment)
    for(;;)
    {
    }
}
