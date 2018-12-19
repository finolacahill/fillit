/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 23:28:43 by fcahill           #+#    #+#             */
/*   Updated: 2018/12/19 03:30:18 by fcahill          ###   ########.fr       */
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
	int i;

	fd = open("valide_4", O_RDONLY);
	while ((n = read(fd, str, 5000)) > 0)
			str[n] = '\0';

	size = ft_count_tmn(str);
	if (ft_1validate(str) != 1)
	{
		ft_putstr("input error");
		return (0);
	}
	n = 0;
	table = ft_save_tmn(str); //sving everything into a 2darray
	while (table[n]) //moving all the pieces to top left corner
	{
		while (ft_moveup(table[n]) == 1);
		while (ft_moveleft(table[n]) == 1);
		++n;
	}
	n = ft_minsize(size + 5); // This function finds the smallest possible size of square for the tetrimos. that five is just to try and fit all the pieces on the board, without space optimisation, will take away later
	map = ft_create_map(n);
	int p = 0;
	int q = 0;
	i = 0;
//	for the the ft_place only works accurately when placing one piece on the map. Having issues with linebreaks and differing map sizes. All the stupid 5's are for the overly large map, normally we'd just compare to size.  
//	{
		if ((n = ft_check_map(map, table[i], p, q)) == 1)
	//	{
			map = ft_place(map, table[i], p, q);
	//		i++;
	//		p = 0;
	//		q = -1;
	//	}
	//	if (q != size + 5)
	//		q++;
	//	 if (q == size + 5 && p != size + 5)
	//	{
	//		p++;
	//		q = 0;
	//	}
	//	if ((p == size + 5) && (q == size + 5))
	//	{
	//		write(1, "impossible\n", 11);
		//	break;
	//	}
		
		
//	}
	n = 0;
	while (map[n])
	{
		printf("%s\n", map[n]);
		++n;
	}
	

}

	


