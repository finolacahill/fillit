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
