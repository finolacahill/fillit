/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_savetotable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:47:15 by fcahill           #+#    #+#             */
/*   Updated: 2019/01/17 13:47:24 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*ft_moveup(char *str)
{
	int		i;
	int		n;

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

static char	*ft_moveleft(char *str, int i, int t)
{
	int		j;

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

static char	**ft_convert(char **table, int len)
{
	int		t;
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	c = 'A';
	while (i < len)
	{
		t = 0;
		j = 0;
		while (t != 4)
		{
			if (table[i][j] == '#')
			{
				table[i][j] = c;
				++t;
			}
			++j;
		}
		++c;
		++i;
	}
	return (table);
}

static char	**ft_save_tmn(char *str, int len, char **table)
{
	int		i;
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (j < len)
	{
		i = 0;
		if (!(table[j] = (char*)malloc(sizeof(char) * 21)))
			return (NULL);
		while (i < 20)
		{
			table[j][i] = str[k];
			i++;
			k++;
		}
		table[j][20] = '\0';
		k++;
		j++;
	}
	table[len] = NULL;
	table = ft_convert(table, len);
	return (table);
}

char		**ft_savetotable(char *str)
{
	int		n;
	int		i;
	int		len;
	char	**table;

	n = 0;
	i = 0;
	len = ft_count_tmn(str);
	if (!(table = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	table = ft_save_tmn(str, len, table);
	if (table == NULL)
		return (NULL);
	len = 0;
	while (table[n])
	{
		table[n] = ft_moveup(table[n]);
		table[n] = ft_moveleft(table[n], i, len);
		n++;
	}
	ft_clean(table, i);
	return (table);
}
