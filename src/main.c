#include <stdio.h>
#include "espl_lib.h"
#define UINT_MAX 65535 // Specifed by 2 bits memory allocation for unsigned int type: 2^(2*8) - 1 

int clear_stdin(void)
{
    int garbage;
    while ( (garbage = getchar()) != '\n' && garbage != EOF ) { };
    return 0;
}

// Entry point
int main (void)
{
    char exit_flag;
    unsigned int dec_number;
    do {       
        printf ("Enter the number in range 0..%u: ", UINT_MAX);
        while(scanf("%u", &dec_number) != 1 || (dec_number > UINT_MAX)) {
            clear_stdin();
            printf("Invalid input. Please, try again. Enter the number in range 0..%u: ", UINT_MAX);
        }
        printf("User input: %u\n", dec_number);
        clear_stdin();

        printf("Result in words: %s \n", num_to_words(dec_number));

        printf("Do you want to enter another number?: y/n ");
        while(scanf("%c", &exit_flag) != 1 || (exit_flag != 'y' && exit_flag != 'n')) {
            clear_stdin();
            printf("Please type ONLY y or n : ");
        }
        clear_stdin();
        } 
    while (exit_flag != 'n');
    return 0;
}
