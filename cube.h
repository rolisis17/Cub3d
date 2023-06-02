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
void	make_window(void);

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


#endif