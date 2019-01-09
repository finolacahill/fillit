#ifndef FILLIT_H
# define FILLIT_H

#include "libft/libft.h"

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <stdio.h>

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

int ft_count_tmn(char *str);
int ft_1validate(char *str);
char **ft_save_tmn(char *str);
int	ft_moveup(char *str);
int	ft_moveleft(char *str);
t_point **ft_move_tmn(char *str);
char **ft_create_map(int size, char **map);
int	ft_minsize(int quantity);
int ft_check_map(char **map, char *str, int x, int y);
char **ft_place(char **map, char *str, int x, int y);
char	**ft_clean(char **str);
#endif
