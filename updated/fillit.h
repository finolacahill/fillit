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
typedef struct	s_position
{
	t_point previous;
	t_point current;
}				t_position;
int ft_count_tmn(char *str);
int ft_1validate(char *str);
char **ft_save_tmn(char *str);
char	*ft_moveup(char *str);
char	*ft_moveleft(char *str);
t_point **ft_move_tmn(char *str);
char **ft_create_map(int size, char **map);
int	ft_minsize(int quantity);
int ft_check_map(char **map, char *str, t_point x, int limit);
char **ft_place(char **map, char *str, int x, int y);
char	**ft_clean(char **str);
t_point	ft_movepoints(int x, int y, int start, int end);
char **ft_savetotable(char *str);
t_point	ft_basicsolver(char **map, char *str, t_point x, int size);
char **ft_backtracking(char **map, char **table, int i, t_position x);
char **ft_solving(char **map, char **table, t_position z, int i);
void	ft_printmap(char **map, int size);

#endif
