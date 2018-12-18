#include "fillit.h"

#define INIT_1 int i; int j; int move_y
#define INIT_2 int i; int j; int k; int f

static t_point **ft_move_up(char *str)
{
	t_point **saved;

	INIT_1;
	i = 0;
	saved = ft_1validate(str);
	while (saved[i])
	{
		move_y = saved[i][0].y;
		j = 0;
		while (j < 4)
		{
			saved[i][j].y = saved[i][j].y - move_y;
			j++;
		}
		i++;
	}
	return (saved);
}

t_point **ft_move_tmn(char *str)
{
	t_point **saved;

	INIT_2;
	i = 0;
	saved = ft_move_up(str);
	while (saved[i])
	{
		f = -1;
		while (++f < 4)
		{
			k = 0;
			while (k < 4 && saved[i][k].x != 0)
					k++;
			j = -1;
			if (k == 4)
			{
				while (++j < 4)
					saved[i][j].x = saved[i][j].x - 1;
			}
		}
		i++;
	}
	return (saved);
}
