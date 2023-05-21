#include <unistd.h>

void rostring(char *str)
{
	int i = 0;
	while(str[i] && str[i] == 32)
		i++;
	int s = i;
	while(str[i] && str[i] != 32)
		i++;
	int e = i - 1;
	int flag = 0;
	while(str[i])
	{
		flag = 0;
		while(str[i] == 32 && str[i])
			i++;
		while(str[i] != 32 && str[i])
		{
			flag = 1;
			write(1,&str[i++],1);
		}
		if(flag)
			write(1," ",1);
	}
	while(s <= e)
		write(1,&str[s++],1);
}
int main(int c , char **v)
{
	if(c == 2)
		rostring(v[1]);
	else if(c > 2)
	{
			int i = 0;
			while(v[1][i])
				write(1,&v[1][i++],1);
	}
	write(1,"\n",1);
}
