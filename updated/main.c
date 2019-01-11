/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 23:28:43 by fcahill           #+#    #+#             */
/*   Updated: 2019/01/11 22:59:39 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
//This is very much just a test main. It's a giant mess but it's a workign mess. To be cleaned up.
//this function belongs in the solver, just hanging out here for now. 

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

int		main(void)
{
	int		fd;
	int		n;
	char str[5000]; 
	char **table;
	char **map;
	int size;
	int count;
	int i;
	t_position z;
	fd = open("valide_26", O_RDONLY);
	while ((n = read(fd, str, 5000)) > 0)
		str[n] = '\0';
	count = ft_count_tmn(str);
	if (ft_1validate(str) != 1)
	{
		ft_putstr("input error");
		return (0);
	}
	n = 0;
	table = ft_savetotable(str); 


	size = ft_minsize(count); 
	map = ft_create_map(size, map);
	i = 0;
	map = ft_solving(map, table, z, i);
	ft_printmap(map, size);
	return (0);

	}
