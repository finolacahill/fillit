#include "fillit.h"

#define INIT int k; int j; int tmn_nb
#define INIT_2 t_point **save; t_point position


t_point **ft_save_tmn(char *str)
{
	INIT;
	INIT_2;

	tmn_nb = ft_count_tmn(str);
	j = -1;
	position.y = 0;
	// do we need this malloc / struct? Could it just be *save[tmn_nb] ?? or even save[tmn_nb][16] (we know size of tetrimos) 
	if (!(save = (t_point **)malloc(sizeof(t_point *) * tmn_nb + 1)))
		return (NULL);
	while(++j < tmn_nb)
	{
		k = 0;
		save[j] = (t_point *)malloc(sizeof(t_point) * 4);
		while (k < 4)
		{
			position.x = 0;
			while (*str != '\n')
			{
				if (*str == '#')
					save[j][k++] = position;
				position.x++;
				str++;
			}
			str++;
			position.y++;
		}
	}
	save[j] = NULL;
	return (save);
}

t_point **ft_save(char *str)
{
	t_point **save;

	if (ft_1validate(str) == 1)
	{
		save = ft_save_tmn(str);
		return (save);
	}
	ft_putendl("Error");
	exit (0);
}
