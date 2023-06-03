#ifndef CUBE_H
# define CUBE_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include "mlx_linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>

# define WIDTH 1080
# define HEIGHT 640

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		edn;
}				t_img;

typedef struct s_projection
{
	float	pos_x;
	float	pos_y;  //x and y start position
	float	dir_x;
	float	dir_y; //initial direction vector
  	float	plane_x;
	float	plane_y; //the 2d raycaster version of camera plane
	float	time; //time of current frame
	float	old_time; //time of previous frame
	float	camera_x;
	int 	map_w;
	int 	map_h;
}				t_pro;

typedef struct s_raycasting
{
	float	ray_x;
	float	ray_y;
	float	raydir_x;
	float	raydir_y;
	float	distance;
	int		hit;
}				t_ray;

typedef struct s_walls
{
	int	wall_h;
	int wall_s;
	int wall_e;
}				t_wall;

struct	s_line
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	endx;
	int	endy;
	int	e;
	int	err;
};

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	char		**map;
	t_img		*img;
	// t_dotfile	*file;
	// t_data		*img;
	// t_calc		calc;
	t_pro		*data;
	int			fd;
}				t_vars;

char	**read_file(int fd);
void	make_window(char **map);
void	data_init(t_vars *vars);
//parse
int		parse_file(int fd, char ***file);
int		check_walls(char **file);
int		search_line(char *line, int c);
//update map
char	*strpp(char *line, int len, int c);
char	*make_new_line(char *line, int max_len);
int		find_max_len(char **file);
char	**make_new_map(char **file, int max_len);
int		check_nl(char *line);

//exit
int	close_win(t_vars *vars);
int	keys(int keycode, t_vars *vars);
//projection
void	projection(t_vars *vars);
void	raycast(float ray_angle, t_vars *vars);
void	draw_wall(float distance, t_vars *vars, float x);
void	draw_line(t_img *img, float x, int start, int end);
struct s_line	draw_line_two(float x, int start, int end);
void	pixel_put(t_img *img, int x, int y, int colour);
int	my_ternery(int a, int b, int yes, int no);

#endif