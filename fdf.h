#ifndef FDF_H_
# define FDF_H_

# define TITLE		"FDF"

# define WIN_HEIGHT	500
# define WIN_WIDTH	700
# define IMG_HEIGHT	500
# define IMG_WIDTH	700
# define IMG_COORDX	0
# define IMG_COORDY	0

# define ERROR_EMPTY	"Config file is empty."
# define ERROR_LINE	"Config file must have at least 1 line ending by '\\n'."

typedef struct	s_mlx_data
{
  void		*mlx_ptr;
  void		*mlx_win;
  void		*mlx_img;
  void		*data;
  int		bpp;
  int		size_line;
  int		endian;
}		t_mlx_data;

typedef struct	s_point_data
{
  int		z;
  int		color;
}		t_point_data;

typedef struct	s_map_data
{
  int		xmax;
  int		ymax;
  t_point_data	**map;
}		t_map_data;

/* put_pixel.c */
int		put_pixel(t_mlx_data *mlx_data, int x, int y, unsigned int color);

/* get_files.c */
int		get_map(const char *path, t_map_data *map_data);

/* file_get_contents.c */
char		*file_get_contents(const char *path);

/* free_map.c */
void		free_map(t_map_data *map_data);

#endif /* !FDF_H_ */
