/***********************************************************
* Author: Rebecca Lashua
* Email: lashuar@oregonstate.edu
* Date Created: 2/19/2020
* Filename: compare.c
*
* Solution description: Implementation of generic compare
* and print_type functions.
************************************************************/
#include <stdio.h>
#include <assert.h>
#include "bst.h"
#include "structs.h"


/*----------------------------------------------------------------------------
 very similar to the compareTo method in java or the strcmp function in c. it
 returns an integer to tell you if the left value is greater then, less then, or
 equal to the right value. you are comparing the number variable, letter is not
 used in the comparison.

 if left < right return -1
 if left > right return 1
 if left = right return 0
 */

 /*Define this function, type casting the value of void * to the desired type.
  The current definition of TYPE in bst.h is void*, which means that left and
  right are void pointers. To compare left and right, you should first cast
  left and right to the corresponding pointer type (struct data *), and then
  compare the values pointed by the casted pointers.

  DO NOT compare the addresses pointed by left and right, i.e. "if (left < right)",
  which is really wrong.
 */
int compare(TYPE left, TYPE right)
{
    struct data * data1;
    struct data * data2;
    data1 = (struct data *) left;
    data2 = (struct data *) right;
    if(data1->number < data2->number) {
        return -1;
    }
    else if (data1->number > data2->number) {
        return 1;
    }
    return 0;
}

/*Define this function, type casting the value of void * to the desired type*/
void print_type(TYPE curval)
{
    struct data * val;
    val = (struct data *) curval;

    printf("%i", val->number);
}


