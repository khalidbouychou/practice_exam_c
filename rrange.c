#include <stdio.h>
#include <stdlib.h>
int *rrange(int s , int e)
{
    int i = 0;
    int len;
    if(s > e)
        len = s - e + 1 ;
    else
        len = e - s + 1;
    int *res = malloc(sizeof(int) * len);
    if(s == 0 && e == 0)
    {
        while(i < len)
        {
            res[i] = 0 ;
            i++;
        }
    }
    else
    {
        while (i <= len)
        {
            if(e > s)
            {
                res[i] = e;
                e--;
                i++;
            }
            else
            {
                res[i] = e;
                e++;
                i++;
            }
        }
    }
    return res;
}
int main()
{
    int i = 0;
    // int *p = rrange(1,3);
    // int *p = rrange(-1,2);
    // int *p = rrange(0,0);
    int *p = rrange(0,-3);

    while(i < 4)
    {
        printf("%d\t",p[i]);
        i++;
    }
}

/*
Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1 √
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.√
- With (0, 0) you will return an array containing 0.√
- With (0, -3) you will return an array containing -3, -2, -1 and 0.√
*/