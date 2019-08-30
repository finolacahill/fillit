/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:48:14 by fcahill           #+#    #+#             */
/*   Updated: 2019/01/17 19:56:50 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_valide_len(const char *str, int dot, int htg)
{
	int		i;

	i = 0;
	while (str[0] != '\n' && i < 546 && str[i])
	{
		dot = 0;
		htg = 0;
		while (str[i] && ((str[i] == '.' || str[i] == '#') || (str[i] == '\n'
				&& (str[i + 1] == '.' || str[i + 1] == '#'))))
		{
			if (str[i] == '#')
				htg++;
			else if (str[i] == '.')
				dot++;
			i++;
		}
		if (dot == 12 && htg == 4 && str[i + 1] == '\n')
			i++;
		else if (str[i + 1] == '\0' && dot == 12 && htg == 4)
			return (1);
		else
			return (-1);
	}
	return (-1);
}

static int	ft_next(int i, int x, const char *str)
{
	while (x < 20)
	{
		i++;
		x++;
	}
	if (str[i])
		i++;
	return (i);
}

static int	ft_valide_tmn(const char *str, int i, int htg, int x)
{
	while (str[i])
	{
		x = 0;
		htg = 1;
		while (x < 20 && htg < 4)
		{
			while (str[i] == '.' || str[i] == '\n')
			{
				i++;
				x++;
			}
			if (str[i + 1] == '#' && str[i + 5] == '#' && (x + 5) < 20)
				htg = htg + 2;
			else if (str[i + 1] == '#' || (str[i + 5] == '#' && x + 5 < 20))
				htg++;
			i++;
			x++;
		}
		if (htg != 4)
			return (-1);
		i = ft_next(i, x, str);
	}
	return (1);
}

int			ft_1validate(char *str)
{
	int		x;
	int		htg;
	int		i;

	x = 0;
	htg = 0;
	i = 0;
	if (ft_count_tmn(str) > 26 || ft_count_tmn(str) < 1)
		return (-1);
	if (ft_valide_len(str, i, htg) == 1 && ft_valide_tmn(str, i, htg, x) == 1)
		return (1);
	return (-1);
}
