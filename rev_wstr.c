#include <unistd.h>

void rev_wstr(char *str)
{
	int i = 0;
	int s = 0;
	int e = 0;
	while(str[i])
		i++;
	while(i >= 0)
	{
		int flag = 0;
		while(str[i] && str[i] == 32)
			i--;
		e = i;
		while(str[i] && str[i] != 32)
			i--;
		s = i + 1;
		while(s <= e && str[i])
		{
			write(1,&str[s],1);
			s++;
			flag = 1;
		}
		if(flag && i >= 0)
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
