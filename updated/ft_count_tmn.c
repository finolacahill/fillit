#include "fillit.h"

int ft_count_tmn(char *str)
{
	int htg;
	int tmn;
	int i;

	htg = 0;
	tmn = 0;
	i = 0;
	if (!str)
		return (-1);
	while(str[i])
	{
		while (str[i] == '#')
		{
			htg++;
			i++;
		}
		i++;
	}
	tmn = htg / 4;
	return (tmn);
}
