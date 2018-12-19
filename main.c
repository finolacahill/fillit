/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 23:28:43 by fcahill           #+#    #+#             */
/*   Updated: 2018/12/19 00:46:40 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

int		main(void)
{
	int		fd;
	int		n;
	char str[5000]; 
	char **table;
	char **map;
	int size;

	fd = open("valide_4", O_RDONLY);
	while ((n = read(fd, str, 5000)) > 0)
			str[n] = '\0';

	size = ft_count_tmn(str);
	if (ft_1validate(str) != 1)
	{
		ft_putstr("input error");
		return (0);
	}
//	printf("%s\n", str);
	n = 0;
	table = ft_save_tmn(str);
	while (table[n])
	{
		while (ft_moveup(table[n]) == 1);
		while (ft_moveleft(table[n]) == 1);
		++n;
	}
	n = 0;
	while (table[n])
	{
		printf("%s",table[n]);
		ft_putchar('\n');
		++n;
	}
	n = ft_minsize(size);
	map = ft_create_map(n);
	n = 0;
	while (map[n])
	{	
		printf("%s\n", map[n]);
		++n;
	}
}

	


