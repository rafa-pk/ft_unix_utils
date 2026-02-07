#include "ft_mv.h"

int	main(int ac, char *av[])
{
	if (ac < 2)
		return (printf("usage: ft_mv source target\n       ft_mv source ... directory"), 1);
	if (ac == 3)
	{
		if (rename(av[1], av[2]) < 0)
		{
			if (errno == ENOENT)
				return (printf("%s: %s: %s\n", av[0], av[1], strerror(errno)), 1);
			else
				return (printf("%s: failed to change filename\n", av[0]), 1);
		}
	}
	else
	{
		if (!mv_to_dir(ac, av))
			return (1);
	}
	return (0);
}
