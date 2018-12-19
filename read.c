#include "fillit.h"

#define BUF_SIZE 4200

int main ()
{
	int fd;
	int bytes;
	static char buf[BUF_SIZE + 1];
	int i = 0;
	int j;
	t_point **position;

	fd = open("valide_26", O_RDONLY);
	bytes = read(fd, buf, BUF_SIZE);
	buf[bytes] = '\0';

	ft_putnbr(bytes);
	ft_putstr(buf);
	ft_putchar('\n');


	// int size = sizeof(buf);

	// position = ft_move_tmn(buf);
	// while (position[i])
	// {
	// 	j = 0;
	// 	while(j < 4)
	// 	{
	// 		printf("x = %i, y = %i\n", position[i][j].x, position[i][j].y);
	// 		j++;
	// 	}
	// 	i++;
	// }

	// int map_size;
	// map_size = 2; // map_size = le output du problem solved
	// int k = 0;
	// char **map = ft_create_map(map_size);
	// while (k < map_size)
	// {
	// 	printf("%s\n", map[k]);
	// 	k++;
	// }
	return(0);
}
