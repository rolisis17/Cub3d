#ifndef CUBE_H
# define CUBE_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include "mlx_linux/mlx.h"
#include <fcntl.h>
// # include <std

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_vars {
	void		*mlx;
	void		*win;
	// t_dotfile	*file;
	// t_data		*img;
	// t_calc		calc;
	int			fd;
}				t_vars;

char	**read_file(int fd);
int		check_walls(char **file);
int		filelen(char **file);
int		parse_file(int fd);
void	make_window(void);
//exit
int	close_win(t_vars *vars);
int	keys(int keycode, t_vars *vars);


#endif