#include "../ft_cp.h"

int	single_file_copy(int ac, char *av[])
{
	int		src_fd, dest_fd;
	int		bytes_read;
	char	buff[BUFF_SIZE];
		
	src_fd = open(av[1], O_RDONLY);
	if (src_fd < 0)
		return (printf("%s: %s: No such file or directory\n", av[0], av[1]), 0);
	if (stat(av[1], &file_metadata) < 0)
		return (printf("Failed to fetch parent file's permissions\n"), 0);
	dest_fd = open(av[2], O_CREAT | O_TRUNC | O_WRONLY, file_metadata.st_mode);
	if (dest_fd < 0)
		return (printf("Failed to create destination file"), 0);
	while ((bytes_read = read(src_fd, buff, BUFF_SIZE)) > 0)
		write(dest_fd, buff, bytes_read);
	return (1);
}
