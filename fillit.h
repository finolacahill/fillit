/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboudyaf <fboudyaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 13:53:11 by fcahill           #+#    #+#             */
/*   Updated: 2019/01/18 15:25:58 by fboudyaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;
void			ft_freearray(char **array, int limit);
int				ft_count_tmn(char *str);
int				ft_1validate(char *str);
char			**ft_create_map(int size, char **map);
int				ft_minsize(int quantity, char **table);
int				ft_check_map(char **map, char *str, t_point x, int limit);
char			**ft_place(char **map, char *str, int x, int y);
char			**ft_clean(char **str, int i);
t_point			ft_movepoints(int x, int y, int start, int end);
char			**ft_savetotable(char *str);
void			ft_solving(char **map, char *str, t_point z);
void			ft_printmap(char **map, int size);
char			**ft_backtracking(char **map, char **table, int i, t_point z);
int				ft_error(void);
#endif
