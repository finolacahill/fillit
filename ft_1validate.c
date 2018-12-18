#include "fillit.h"
//We also need to verify how many newlines are in the file. One at the end of each line but also one between each tetrimonos except the last. We can also maybe count how many tertimonos we have, will make save stage easier??
static int ft_valide_len(const char *str)
{
	int i;
	int dot;
	int htg;

	i = 0;
	while (i < 546 && str[i])
	{
		dot = 0;
		htg = 0;
		while (str[i] != '\n' || (str[i] == '\n' && (str[i + 1] == '.' || str[i + 1] == '#')))
		{
			if (str[i] == '#')
				htg++;
			else if (str[i] == '.')
				dot++;
			i++;
		}
		if (dot == 12 && htg == 4 && str[i + 1] == '\n')
			i++;
		else if (str[i + 1] == '\0' && dot == 12 && htg == 4)
			return (1);
		else
		{
			return (-1);
			ft_putstr("file not ok");
		}
	}
	ft_putstr("file not ok");
	return (-1);
}
//
// I don't think this checker will work for all shapes. It needs the first hashtag to immediately touch a hashtag beside it, and it's not always the case. I tried it out on paper, will try it out with code later. Shapes such as
// ....
// ..#.
// ..#.
// .##. 
//
// or
//
// ....
// ..#.
// ..##
// ...#
static int ft_valide_tmn(const char *str)
{
	int i;
	int htg;
	int x;

	i = 0;
	while (str[i])
	{
		x = 0;
		htg = 1;
		while (x < 20 && htg < 4)
		{
			while (str[i] == '.' || str[i] == '\n')
			{
				i++;
				x++;
			}
			if (str[i + 1] == '#' && str[i + 5] == '#' && (x + 5) < 20)
				htg = htg + 2;
			else if (str[i + 1] == '#' || (str[i + 5] == '#' && x + 5 < 20))
				htg++;
			i++;
			x++;
		}
		if (htg != 4)
			return (-1);
		while (x < 20)
		{
			x++;
			i++;
		}
		if (str[i])
			i++;
	}
	return (1);
}

int ft_1validate(char *str)
{
	if (ft_valide_len(str) == 1 && ft_valide_tmn(str) == 1)
	{
		return(1);
	}
	return (-1);
	ft_putstr("file not ok");
}
