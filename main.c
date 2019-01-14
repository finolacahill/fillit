/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 23:28:43 by fcahill           #+#    #+#             */
/*   Updated: 2019/01/14 20:03:09 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
//This is very much just a test main. It's a giant mess but it's a workign mess. To be cleaned up.
//this function belongs in the solver, just hanging out here for now. 

int		main(int argc, char **argv)
{
	int		fd;
	int		n;
	char	str[1000]; 
	char 	**map;
	int		i;
	t_point z;

	i = 0;
	map = NULL;
	if (argc != 2)
		{
			ft_putstr("Usage error: Fillit takes a single file as input\n");
			return (0);
		}
	fd = open(argv[1], O_RDONLY);
	while ((n = read(fd, str, 1000)) > 0)
		str[n] = '\0';
	if (ft_1validate(str) != 1)
	{
		ft_putstr("input error");
		return (0);
	}
	ft_solving(map, str, z, i);
	return (0);
	}
