#include "ft_mv.h"

int	mv_to_dir(int ac, char *av[])
{
	int	fd_to_move, srcdir_fd;

	srcdir_fd = open(av[ac - 1], O_RDONLY);
	if (srcdir_fd < 0)
		return (printf("%s: %s is not a directory\n", av[0], av[ac - 1]), 0);
	if (stat(av[ac - 1], &metadata) < 0)
		return (printf("%s: failed to fetch directory's metadata\n", av[0]), 0);
	for (int i = 1; i < ac - 1; i++)
	{
		fd_to_move = open(av[i], O_RDONLY);
		if (linkat(AT_FDCWD, av[i], srcdir_fd, av[i], 0) < 0)
			return (printf("%s: rename %s to %s/%s: No such file or directory",
					av[0], av[i], av[ac - 1], av[i]), 0);
		if (unlink(av[i]) < 0)
			return (printf("%s: rename %s to %s/%s: Failed to unlink working_dir/%s\n",
					av[0], av[i], av[ac - 1], av[i], av[i]), 0);
	}
	return (1);
}
