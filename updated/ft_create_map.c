/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:44:25 by fcahill           #+#    #+#             */
/*   Updated: 2019/01/11 17:37:41 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

int		ft_minsize(int quantity)
{
	int		i;

	i = 1;
	quantity = quantity * 4;
	while (quantity > (i * i))
		++i;
	return (i);
}

char	**ft_create_map(int size, char **map)
{
	int		i;
	int		j;

	j = 0;
	if (!(map = (char **)malloc((sizeof(char*) * size + 1))))
		return (NULL);
	while (j < size)
	{
		i = 0;
		map[j] = (char *)malloc((sizeof(char) * size + 1));
		while (i < size)
			map[j][i++] = '.';
		map[j][size] = '\0';
		j++;
	}
	map[size] = NULL;
	return (map);
}

//Checking if there are the necessary blank spaces on map
//
//Limit should be size of map minus 1 to take in account the /o and /n
int		ft_check_map(char **map, char *str, t_point x, int limit)
{
	int		i;
	int		start;

	start = x.y;
	i = 0;
	//	if (x.x == limit && x.y == limit)
	//		return (-1); these lines are necessary but they are in the main for now for length reasons. They can be in the solver function after. 
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && (i++ || 1))
		{
			if (x.x == limit)
				return (0);
			x.x++;
			x.y = start;
		}
		if (str[i] == '.' && (i++ || 1))
			x.y++;
		if ((str[i] >= 'A' && str[i] <= 'Z') && (i++ || 1))
		{
			if (map[x.x][x.y] == '.')
				x.y++;
			else
				return (0);
		}
	}
	return (1);
}

char	**ft_place(char **map, char *str, int x, int y)
{
	int		i;
	int		start;

	i = 0;
	start = y;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			++x;
			++i;
			y = start;
		}
		if ((str[i] >= 'A' && str[i] <= 'Z'))
			map[x][y] = str[i];
		++i;
		++y;
	}
	return (map);
}
