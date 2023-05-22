// primes.c

/* Enzo Ferber : <enzo@veloxmail.com.br>
 *
 * Decompose into Prime Factors a given number
 *
 * march 27 2009
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define START 2

// used by the main() function to print the factors
int control;

/* decom ( num )
 *
 * @ num: number to decompose
 *
 * @ Return: return an int* containing all the prime factors
 */
int *decom ( int num )
{
    // ...
    register int i;
    int *primes = (int *) malloc ( sizeof (int) );

    // Houston, we have a problem!
    if ( !primes ) exit (0);

    // set control variable
    control = 1;

    // START represents the first prime number, 2
    for ( i = START; i <= num || num != 1 ; i++ )
    {
        // ensures just an exact division
        while ( (num % i) == 0)
        {
            // I WANT MORE MEMORY, BITCH!!!
            primes = (int *) realloc ( primes, control * sizeof (int));

            // Houston, we have a problem!
            if ( !primes) exit (0);

            // put the current prime factor into the list
            primes[control - 1] = i;
            control++;

            // set new number to be divided next
            num = num / i;
        }
    }

    // return the prime list
    return primes;
}

int main ( int argc, char **argv )
{
    int num;
    do{
        printf("\nEntre com um numero inteiro positivo maior que zero: ");
        scanf("%d", &num);
    }while(num<0);


    // check for the correct argument
    if ( num != 2 )
    {
        // HowTo use a very complex program...
        printf ( "Usage: %s <number>\n", argv[0] );
        return 0;
    }

    // begin the program if the arguments are correct
    register int i;

    // call the function to decompose into prime factors
    int *primes = decom ( atoi(argv[1]) );

    // print prime list
    for ( i = 0; i < control - 1; i++ )
        printf ( "%3d: %d\n", i + 1, primes[i] );

    // free the memory
    free ( primes );


    return 0;
}
