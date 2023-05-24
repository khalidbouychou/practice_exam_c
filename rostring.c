
/*
Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
zLKIJz#,#23y#AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>
*/
#include <unistd.h>
#include <unistd.h>
void rostring(char *str)
{
   int i = 0;
   int e = 0;
   int s = 0;
   int flag = 0;
   while(str[i] == 32)
        i++;
   s = i;
   while(str[i] != 32)
        i++;
    e = i - 1;
    while(str[i])
    {
        while(str[i] == 32 && str[i])
            i++;
        while(str[i] != 32 && str[i])
        {
            write(1,&str[i],1);
            i++;
            flag = 1;
        }
        if(flag)
            write(1,"#",1);
    }
    while(s <= e)
        write(1,&str[s++],1);
}
int main(int c , char **v)
{
    if(c == 2)
        rostring(v[1]);
    else if (c > 2)
    {
        int i = 0;
        while (v[1][i] && v[1][i] != 32) {
        write(1,&v[1][i++],1);
        }
    }
    write(1,"\n",1);
}