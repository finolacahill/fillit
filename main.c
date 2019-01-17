/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 23:28:43 by fcahill           #+#    #+#             */
/*   Updated: 2019/01/17 13:08:12 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		n;
	char	str[1000];
	char	**map;
	t_point z;

	map = NULL;
	z.x = 0;
	z.y = 0;
	if (argc != 2)
	{
		ft_putstr("Usage: Fillit takes a single file as input\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	while ((n = read(fd, str, 1000)) > 0)
		str[n] = '\0';
	if (ft_1validate(str) != 1)
	{
		ft_putstr("error\n");
		return (0);
	}
	ft_solving(map, str, z);
	free(map);
	return (0);
}
