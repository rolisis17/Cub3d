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

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	// t_dotfile	*file;
	// t_data		*img;
	// t_calc		calc;
	t_pro		*data;
	int			fd;
}				t_vars;

typedef struct s_projection
{
	double	pos_x;
	double	pos_y;  //x and y start position
	double	dir_x;
	double	dir_y; //initial direction vector
  	double	plane_x;
	double	plane_y; //the 2d raycaster version of camera plane
	double	time; //time of current frame
	double	old_time; //time of previous frame
	double	camera_x;
	double	rayDir_x;
	double	rayDir_y;

}				t_pro;

char	**read_file(int fd);
int		check_walls(char **file);
int		filelen(char **file);
int		parse_file(int fd);
void	make_window(void);
//exit
int	close_win(t_vars *vars);
int	keys(int keycode, t_vars *vars);
//projection
void	projection(t_vars *vars);

#endif