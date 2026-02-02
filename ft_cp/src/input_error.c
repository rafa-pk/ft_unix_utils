#include "../ft_cp.h"

int	input_error(int ac, char *av[])
{
	if (ac < 3)
		return(printf("usage:  cp source_file target_file\n\tcp source_file <...> target_directory\n"), 1);
	return (0);
}
