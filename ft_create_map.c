#include "fillit.h"
#include "libft/libft.h"


int	ft_minsize(int quantity)
{
	int i;

	i = 1;
	quantity = quantity * 5;
	while (quantity > (i * i))
		++i;
	return (i);
}

char **ft_create_map(int size)
{
	char **map;
	int i;
	int j;

	j = 0;
	if (!(map = (char **)malloc((sizeof(char*) * size))))
		return (NULL);
	while (j < size)
	{
		int i = 0;
		map[j] = (char *)malloc((sizeof(char) * size));
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

	i = 0;

	//	if (x > 3 || y > 3)
	//	{
	//		write(1, "Coordinate error\n", 17);
	//	return (0);
	//	} depends on size of map
	while (str[i] != '\0')
	{
		if (str[i] == '\n' || map[x][y] == '\0')
		{
			x++;
			y = 0;
		}
		if ((str[i] == '.') || (str[i] == '\n') || ((str[i] != '\n'
						&& str[i] != '.') && map[x][y] == '.'))
		{
			++i;
			++y;
		}
		if ((map[x][y] != '.' && map[x][y] != '\n') && 
				((str[i] != '.' && str[i] != '\n' && str[i] != '\0')))
			return (0);
		++i;
	}
	return (1);
}

char **ft_place(char **map, char *str, int x, int y)
{
	int i;

	i = 0;
	//	if (x > 3 || y > 3)
	//	{
	//		write(1, "Coordinate error\n", 17);
	//		return (0);
	//	} // depends on size of map
	while (str[i] != '\0')
	{		
		if (str[i] == '\n' || map[x][y] == '\0')
		{	
			++x;
			y = 0;
		}
		if (str[i] == '\n')
			++i;
		if ((str[i] >= 'A' && str[i] <= 'Z'))	
			map[x][y] = str[i];
		++i;
		++y;
}
return (map);
}


