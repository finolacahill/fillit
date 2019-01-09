#include "fillit.h"

int		ft_moveleft(char *str)
{
	int i;

	i = 0;
	if (str[0] == '.' && str[5] == '.' && 
			str[10] == '.' && str[15] == '.')
	{
		while(i < 18)
		{
			if (str[i + 1] != '\n')
				str[i] = str[i + 1];
			else
			{	
				str[i] = str[i + 2];
				++i;
			}
			++i;
		}
		str[18] = '.';
		return (1);
	}
	return (0);
}


int		ft_moveup(char *str)
{
	int i;

	i = 0;

	if (str[0] == '.' && str[1] == '.' &&
			str[2] == '.' && str[3] == '.')
	{	
		while (i < 15)
		{
			if (str[i] != '\n')
				str[i] = str[i + 5];
			++i;
		}
		while (str[i] != '\n')
		{
			str[i] = '.';
			++i;
		}
		return (1);
	}
	return (0);

}


char	**ft_save_tmn(char *str)
{
	int i;
	int j;
	int k;
	char **save;
	char c = 'A';

	i = 0;
	j = 0;
	int len; 
	len = ft_count_tmn(str);
	save = (char **)malloc(sizeof(char *) * len + 1);
	while (j < len)
	{
		k = 0;
		if (!(save[j] = (char *)malloc(sizeof(char) * 25)))
			return (NULL);
		while (k < 20)
		{
			if (str[i] == '#')
				str[i] = c;
			save[j][k] = str[i];
			++k;
			++i;
		}
		save[j][k + 1] = '\0';
		++j;
		++i;
		c = c + 1;	
	}
	save[len] = NULL;
	return (save);
}

char	**ft_clean(char **str)
{
	int i; 
	int j;
	int t;
	int search;

	i = 0;
	search = 0;
	while (str[i])
	{
		j  = 0;
		t = 0;
		while (t != 4)
		{
			while (str[i][j] > 'Z' || str[i][j] < 'A')
			++j;
			while (str[i][j] >= 'A' && str[i][j] <= 'Z')
			{
				j++;
				t++;
			}
			if (t != 4)
			{	
				while (str[i][j] != '\n')
				{	
					search = j;
					while (str[i][search + 1] != '\0')
					{
						str[i][search] = str[i][search + 1];
						++search;
					}
				}		
			}		
			else
				str[i][j] = '\0';
		}
		i++;
	}
	return (str);
}
