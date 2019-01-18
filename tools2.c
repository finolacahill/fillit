/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:53:06 by fcahill           #+#    #+#             */
/*   Updated: 2019/01/18 13:48:35 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
