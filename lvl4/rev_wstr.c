#include <endian.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ftlen(char *str)
{
    int len = 0;
    while (str[len] == 32)
        len++;
    return len;
}
void rev_wstr(char *str)
{
    int i = 0;
    int s = 0;
    int e = 0;
    int x = ftlen(str);
    while (str[i])
        i++;
    while (i >= 0)
    {
        while(i && str[i] == 32)
            i--;
        int e = i;
        while(i && str[i] != 32)
            i--;
        int s = i + 1;
        int flag = 0;
        while(s <= e)
        {
            write(1,&str[s],1);
            s++;
            flag = 1;
        }
        if(flag && i > x)
            write(1,"#",1);
        i--;
    }
}
int main(int c , char **v)
{
	if(c == 2)
		rev_wstr(v[1]);
	write(1,"\n",1);
	return 0;
}

/*
Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the
begin/end of the string.

If the number of parameters is different from 1, the program will display
'\n'.

In the parameters that are going to be tested, there won't be any "additional"
spaces (meaning that there won't be additionnal spaces at the beginning or at
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$>
*/