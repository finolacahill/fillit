char **ft_solved(char *str)
{
	int map_size;
	char **map;
	char **solved;
	t_point **saved;

	map_size = 0;
	map = ft_create_map(map_size);
	saved = ft_move_tmn(str);
	solved = ft_solve_it(saved, map_size, map, str);
	return (solved);
}
	
static char **ft_solve_it(t_point **saved, int map_size, char **map, char *str)
{
	
	int j;
	int i;

	j = 0;
	i = 0;
	if (map[j][i] == '.')
		j++;
	}
	return (solved);
}