/**
 *   Name: 	Sigint.c
 *   Author: 	Charles Kann
 *   Date:  	August 22, 2002
 *
 *   Purpose:	This program shows how to override the interrupt handler
 *		for a SIGINT (CTRL-C).
 */

#include <stdio.h>
#include <signal.h>

int counter = 0;
/** 
 *  Define the method to be called when CTRL-C is pressed.
 */
void programInterrupted(int i) 
{
    printf("In the signal interrupt routine\n");
}

void processAlarm(int i) 
{
    counter += 15;
}
/**
 *   Main method, shows how to map another function over the CTRL-C
 */
int main() 
{
    int i;
    /*  The sigset sets the interrupt to another vector (method address).
     *  In this case the SIGNT interrupt is set to call the 
     *  programInterrupted function defined above.
     */
    sigset(SIGALRM, processAlarm);
    ualarm(1, 15);
    /*  Now just go into a loop for a few seconds to show what happens when
     *  CTRL-C is pressed.  Press Control C while this is running and you
     *  will see that the interrpts are turned off and are going to the 
     *  interrup method and printing out an error.
     */
    for (i = 30; i < 45; i++) {
        counter = 0;
        printf("fib(%d) = %d\n", i, fib(i));
        printf("Time: %d\n", counter);
    }
}

int fib(int n) 
{
    if (n <= 1)
	return 1;
    return (fib(n-1) + fib(n-2));
}