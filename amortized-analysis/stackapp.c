/**********************************************************
* Author: Rebecca Lashua
* Date: 1/23/2019
***********************************************************/
/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string

*/
char nextChar(char* s)
{
	static int i = -1;
	char c;
	++i;
	c = *(s+i);
	if ( c == '\0' )
		return '\0';
	else
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string
	pre:
	post:
*/

int isBalanced(char* s)
{
	/* FIXME: You will write this function */

	/* Create the stack */
	DynArr *brackets;
    brackets = newDynArr(100);
    char ch = nextChar(s);

	/* Iterate over string */
	while(ch != '\0')
    {
        /* If Opening bracket is found, push to stack */
        if(ch == '(' || ch == '{' || ch == '[')
        {
            pushDynArr(brackets, ch);
        }
        else if(ch == ')' || ch == '}' || ch == ']')
        {
            /* If the stack is empty, return 0 because it's unbalanced */
            if(isEmptyDynArr(brackets))
            {
                return 0; // Unbalanced if no opening bracket preceded it
            }
            else
            {
                /* If Closing bracket is found, look at the top of stack */
                char openingChar = topDynArr(brackets);
                if((openingChar == '(' && ch == ')')
                    || (openingChar == '{' && ch == '}')
                    || (openingChar == '[' && ch == ']'))
                {
                    /* If it is a matching bracket, pop the top element off stack */
                    popDynArr(brackets);
                }
            }
        }

        ch = nextChar(s);
    }

    /* If stack size isn't empty at this point, return not balanced */
    if(!isEmptyDynArr(brackets))
    {
        return 0;
    }

    /* Free stack memory */
    deleteDynArr(brackets);
    /* If the function hasn't returned 0 at this point, it is balanced */
    return 1;
}

int main(int argc, char* argv[]){

	char* s=argv[1];

	int res;

	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else
		printf("The string %s is not balanced\n",s);

	return 0;
}

