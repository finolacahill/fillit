/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:48:25 by fcahill           #+#    #+#             */
/*   Updated: 2019/01/18 19:04:59 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_printmap(char **map, int size)
{
	int		n;

	n = 0;
	while (n < size)
	{
		ft_putstr(map[n]);
		ft_putchar('\n');
		++n;
	}
}

t_point		ft_movepoints(int x, int y, int start, int end)
{
	t_point	q;

	q.x = x;
	q.y = y;
	if (q.y != end)
		q.y++;
	if (q.y == end && q.x != end)
	{
		q.x++;
		q.y = start;
	}
	if (q.y == end && q.x == end)
	{
		q.x = -1;
		q.y = -1;
	}
	return (q);
}

static char	**ft_findnewline(char **str, int i, int j)
{
	int		search;

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

char		**ft_clean(char **str, int i)
{
	int		j;
	int		t;

	while (str[i])
	{
		j = 0;
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

int			ft_count_tmn(char *str)
{
	int		htg;
	int		tmn;
	int		i;

	htg = 0;
	tmn = 0;
	i = 0;
	if (!str)
		return (-1);
	while (str[i])
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

void	ft_freearray(char **array, int limit)
{
	int	i;

	i = 0;
	while (i <= limit)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int		ft_error(void)
{
	ft_putstr("error\n");
	return (0);
}
