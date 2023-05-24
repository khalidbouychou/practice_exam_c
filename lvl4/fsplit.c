/*
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);
*/
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
void fncpy(char *d , char *s , int len)
{
    int i = -1;
    while(++i < len && s[i])
        d[i] = s[i];
    d[i] = '\0';
}

char **ft_split(char *str)
{
    int i = 0;
    int w = 0;
    while(str[i])
    {
        while(str[i] && str[i] == 32)
            i++;
        while(str[i] && str[i] != 32)
            i++;
    }
    char **res = malloc(sizeof(char *) * 10000);
    int k = 0;
     i = 0;
    while(str[i])
    {
        while(str[i] && str[i] == 32)
            i++;
        int s = i;
        while(str[i] && str[i] != 32)
            i++;
        res[k] = malloc(sizeof(char) * 10000);
        fncpy(res[k++],&str[s],i - s);
        i++;       
    }
    res[k] = NULL;
    return res;
}
int main()
{
    char **r = ft_split(" haha hello world cv hani lomobfadikjbgdjskbgadjksbgjas");
    int i = 0;
    while(i < 6)
        printf("%s\n",r[i++]);
}