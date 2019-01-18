/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 23:28:43 by fcahill           #+#    #+#             */
/*   Updated: 2019/01/18 13:43:26 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		n;
	char	str[550];
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
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_error());
	if ((n = read(fd, str, 550)) <= 0 || n > 546)
		return (ft_error());
	str[n] = '\0';
	close(fd);
	if (ft_1validate(str) != 1)
		return (ft_error());
	ft_solving(map, str, z);
	free(map);
	return (0);
}
