#ifndef CUBE_H
# define CUBE_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include "mlx_linux/mlx.h"
#include <fcntl.h>
// # include <std

char	**read_file(int fd);
int		check_walls(char **file);
int		filelen(char **file);
int		parse_file(int fd);


#endif