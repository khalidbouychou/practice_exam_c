/*
Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
*/

#include <stdio.h>
#include <unistd.h>
void last_word(char *str)
{
  int i = 0;
  while(str[i])
    i++;
  i--;
  while(str[i] == 32)
    i--;
  int e = i;
  while(str[i] != 32)
    i--;
   int s = i + 1;
   while(s <= e)
        write(1,&str[s++],1); 
}
int main(int c , char **v)
{
    if(c == 2)
        last_word(v[1]);
    printf("\n");
}