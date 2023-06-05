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
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	double	delta_x;
	double	delta_y;
	int		map_x;
	int		map_y;
	double	ray_x;
	double	ray_y;
	double	distance;
	int		hit;
	double	wall_dist;
	double	side_distx;
	double	side_disty;
	int		step_x;
	int		step_y;
	int		side;
	int		wall_h;
	int		wall_s;
	int		wall_e;
}				t_pro;

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
	int			fd;
	double	pos_x;
	double	pos_y;  //x and y start position
	int 	map_w;
	int 	map_h;
	char	dir;
	double	dir_x;
	double	dir_y; //initial direction vector
  	double	plane_x;
	double	plane_y; //the 2d raycaster version of camera plane
	double	time; //time of current frame
	double	old_time; //time of previous frame
}				t_vars;

char	**read_file(int fd);
void	make_window(char **map);
void	data_init(t_vars *vars, char **map);
//parse
int		parse_file(int fd, char ***file);
int		check_walls(char **file);
int		search_line(char *line, int c);
int		parse_full(char **file);
int		check_map(char *line, int f);
int		player_pos(char dir, int pos_col, int pos_row, t_vars *vars);
int		check_maps_start(char *line);

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
void	step_n_side(t_pro *ray, t_vars *vars);
void	dda_algo(t_pro *ray, t_vars *vars);
void	draw_line(t_pro *ray, t_vars *vars, int x);
void	pixel_put(t_img *img, int x, int y, int colour);
double	my_ternery(double a, double b, double yes, double no);

#endif