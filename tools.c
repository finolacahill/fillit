/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:48:25 by fcahill           #+#    #+#             */
/*   Updated: 2019/01/14 20:03:14 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

#define INIT_2 int i; int j; int t;

void	ft_printmap(char **map, int size)
{
	int n;
	n = 0;
	while (n < size)
	{
		ft_putstr(map[n]);
		ft_putchar('\n');
		++n;
	}
}

t_point	ft_movepoints(int x, int y, int start, int end)
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
