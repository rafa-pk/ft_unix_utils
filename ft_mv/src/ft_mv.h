#ifndef FT_MV_H
#define FT_MV_H

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

struct stat metadata;

int	mv_to_dir(int ac, char *av[]);

#endif
