#include "fillit.h"

#define INIT_1 int i; int j; int k; char **save; char c; int len
#define INIT_2 int i; int j; int t;

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

char	**ft_save_tmn(char *str)
{
	INIT_1; 
	c = 'A';
	i = 0;
	j = 0;
	len = ft_count_tmn(str);
	save = (char **)malloc(sizeof(char *) * len + 1);
	while (j < len)
	{
		k = 0;
		if (!(save[j] = (char *)malloc(sizeof(char) * 20)))  // why 25 and not 20
			return (NULL);
		while (k < 20)
		{
			if (str[i] == '#')
				str[i] = c;
			save[j][k++] = str[i++];
		}
		save[j++][k + 1] = '\0';
		++i;
		c++;
	}
	save[len] = NULL;
	return (save);
}

char	**ft_findnewline(char **str, int i, int j)
{
	int search;

	search = 0;
	while (str[i][j] != '\n')
	{
		search = j;
		while (str[i][search + 1] != '\0')
		{
			str[i][search] = str[i][search + 1];
			++search;
		}
	}
	return (str);
}

char	**ft_clean(char **str)
{
	INIT_2

	i = 0;
	while (str[i])
	{
		j  = 0;
		t = 0;
		while (t != 4)
		{
			while (str[i][j] > 'Z' || str[i][j] < 'A')
				j++;
			while (str[i][j] >= 'A' && str[i][j] <= 'Z')
			{
				j++;
				t++;
			}
			if (t != 4)
				str = ft_findnewline(str, i, j);
			else
				str[i][j] = '\0';
		}
		i++;
	}
	return (str);
}

char **ft_savetotable(char *str)
{
	int n = 0;
	char **table = ft_save_tmn(str); 
	while (table[n])
	{
		while (ft_moveup(table[n]) == 1);
		while (ft_moveleft(table[n]) == 1);
		n++;
	}
	ft_clean(table);
	return(table);
}
