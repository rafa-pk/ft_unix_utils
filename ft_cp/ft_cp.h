#ifndef FT_CP_H
#define FT_CP_H

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUFF_SIZE 64

struct stat file_metadata;

int	input_error(int ac, char *av[]);
int	single_file_copy(int ac, char *av[]);
int	copy_to_dir(int ac, char *av[]);

#endif
