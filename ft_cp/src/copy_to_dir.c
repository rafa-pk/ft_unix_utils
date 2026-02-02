#include "../ft_cp.h"

int	copy_to_dir(int ac, char *av[])
{
	int		src_fd, dir_fd, dest_fd;
	int		i, bytes_read;
	char	buff[BUFF_SIZE];
	
	for (int i = 1; i < ac - 1; i++)
	{
		src_fd = open(av[i], O_RDONLY);
		if (src_fd < 0)
			return (printf("%s: %s: No such file or directory\n", av[0], av[i]), 0);
		if (stat(av[i], &file_metadata) < 0)
			return (printf("Failed to fetch parent file's permissions\n"), 0);
		dir_fd = open(av[ac - 1], O_RDONLY);
		if (dir_fd < 0)
			return (printf("%s: %s is not a directory\n", av[0], av[ac - 1]), 0);
		dest_fd = openat(dir_fd, av[i], O_CREAT | O_TRUNC | O_WRONLY, file_metadata.st_mode);
		if (dest_fd < 0)
			return (printf("Could not add %s to %s directory", av[i], av[ac - 1]), 0);
		while ((bytes_read = read(src_fd, buff, BUFF_SIZE)) > 0)
			write(dest_fd, buff, bytes_read);
	}
	return (1);
}
