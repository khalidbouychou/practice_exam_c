/*
Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
*/
#include <unistd.h>

void ftolower(char *str)
{
    int i = 0;
    while(str[i])
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        i++;
    }
}
int	ft_atoi_base(const char *str, int str_base)
{
    int res = 0;
    int sign = 1 ;
    int i = 0;
    if(str[i] == '-')
        sign = -1;
    if(str[i] == '-' && str[i] == '+')
        i++;
    ftolower((char *)str);
    while(str[i])
    {
        res *= str_base;
        if(str[i] >= '0' && str[i] <= '9')
            res += str[i] - '0';
        else
            res += str[i] - 'W';
        i++;
    }
    return(res * sign);
}
#include <stdio.h>
int main()
{
    printf("%d\n",ft_atoi_base("b",16));
}