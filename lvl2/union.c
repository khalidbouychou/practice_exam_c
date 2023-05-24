#include <unistd.h>


int f(int len , char c , char *str)
{
    int i = 0;
    while(str[i] && i < len)
    {
        if(str[i] == c)
            return (1);
        i++;
    }
    return 0;
}
void funion(char *dest ,char *src)
{
    int i = 0;
    while(dest[i])
        i++;
    int j = 0;
    while(src[j])
        dest[i++] = src[j++];
    dest[i] = '\0';
    i = 0;
    while(dest[i])
    {
        if(!f(i,dest[i],dest))
            write(1,&dest[i],1);
        i++;
    }
}
int main(int c , char **v)
{
    if(c == 3)
        funion(v[1],v[2]);
    write(1,"\n",1);
}
/*
Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/