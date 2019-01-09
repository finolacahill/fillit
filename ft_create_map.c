#include "fillit.h"
#include "libft/libft.h"


int	ft_minsize(int quantity)
{
	int i;

	i = 1;
	quantity = quantity * 5;
	while (quantity > (i * i))
		++i;
	return (i - 1);
}

char **ft_create_map(int size, char **map)
{
	int i;
	int j;

	j = 0;
	if (!(map = (char **)malloc((sizeof(char*) * size + 1))))
		return (NULL);
	while (j < size)
	{
		int i = 0;
		map[j] = (char *)malloc((sizeof(char) * size + 1));
		while(i < size)
			map[j][i++] = '.';
		map[j][size] = '\0'; 
		j++;
		}
	map[size] = NULL;
	return (map);
}
//Checking if there are the necessary blank spaces on map
int		ft_check_map(char **map, char *str, int x, int y)
{
	int i;
	int flag;
	int limit;
	
	flag = y;
	i = 0;
	limit = 0;
	while (map[limit])
		++limit;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			if (x == limit - 1)
				return (0);
			x++;
			++i;
			y = flag;
		}
		if (map[x][y] == '\0' || str[i] == '\n')
			return (0);
		if (str[i] == '.')
		{
			i++;
			y++;
		}	
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (map[x][y] == '.')
			{
				i++;
				y++;
			}
		}
		if ((map[x][y] >= 'A' && map[x][y] <= 'Z' && str[i] >= 'A' 
			&& str[i] <= 'Z'))
			return (0);
	}
	return (1);
}

char **ft_place(char **map, char *str, int x, int y)
{
	int i;
	int flag;

	i = 0;
	flag = y;
	//	if (x > 3 || y > 3)
	//	{
	//		write(1, "Coordinate error\n", 17);
	//		return (0);
	//	} // depends on size of map
	while (str[i] != '\0')
	{	
		if (str[i] == '\n')
		{
			x++;
			++i;
			y = flag;
		}
		if ((str[i] >= 'A' && str[i] <= 'Z'))	
			map[x][y] = str[i];
		++i;
		++y;
}
return (map);
}


