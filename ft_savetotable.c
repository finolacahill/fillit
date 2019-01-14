#include "fillit.h"

#define INIT_1 int i; int j; int k; char **save; char c; int len
#define INIT_2 int i; int j; int t;

char	*ft_moveup(char *str)
{
	int i;
	int n;

	n = 19;
	while ((str[0] == '.' && str[1] == '.' &&
				str[2] == '.' && str[3] == '.'))
	{
		i = 0;
		n = n - 5;
		while (i < n)
		{
			str[i] = str[i + 5];
			++i;
		}
		str[n] = '\0';
	}
	return (str);

}

char	*ft_moveleft(char *str)
{
	INIT_2

	j = 1;
	while (str[0] == '.' && j == 1)
	{ 
		i = 0;
		t = 0;
		while (str[i])
		{
			if (str[i] == '\n' && (str[i + 1] != '.' && str[i + 1] != '\0'))
					j = 0;
			i++;
		}
		i = 0;
		while (j == 1 && (t != 4))
		{
			if ((++i || 1) && ft_isalpha(str[i]) == 1)
			{
				str[i - 1] = str[i];
				str[i] = '.';
				t++;
			}
		}

	}
	return (str);
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
		if (!(save[j] = (char *)malloc(sizeof(char) * 21)))  // why 25 and not 20
			return (NULL);
		while (k < 20)
		{
			if (str[i] == '#')
				str[i] = c;
			save[j][k++] = str[i++];
		}
		save[j++][20] = '\0';
		++i;
		c++;
	}
	save[len] = NULL;
	return (save);
}


char **ft_savetotable(char *str)
{
	int n = 0;
	char **table = ft_save_tmn(str); 
	while (table[n])
	{
		table[n] = ft_moveup(table[n]);
		table[n] = ft_moveleft(table[n]);
		n++;
	}
	ft_clean(table);
	return(table);
}
