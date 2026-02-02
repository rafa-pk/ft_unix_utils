#include "ft_cp.h"

int	main(int ac, char *av[])
{
	if (input_error(ac, av))
		return (1);
	
	if (ac == 3)
	{
		if (!single_file_copy(ac, av))
			return (1);
	}
	else
	{
		if (!copy_to_dir(ac, av))
			return (1);
	}
	return (0);
}
