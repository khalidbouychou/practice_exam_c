/*
Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/
#include <stdlib.h>
#include <stdio.h>
int *ft_range(int s , int e)
{
    int *res;
    int len; 
    int i = 0; 
    if(s > e)
        len = s - e;
    else
        len = e - s;
    res = malloc(sizeof(int) * len);
    while(i <= len)
    {
        if(s < e)
        {
            res[i] = s;
            s++;
            i++;
        }
        else {
            res[i] = s;
            s--;
            i++;
        }
    }
    return res;
}

int main()
{
    int i = 0;
    // int *ptr = ft_range(1,3);
    // int *ptr = ft_range(-1,2);
    // int *ptr = ft_range(0,0);
    int *ptr = ft_range(0,-3);
    while (i < 4) {
        printf("%d\t",ptr[i]);
        i++;
    }
}