#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mlx.h>
#include "fdf.h"

/* static void	color_image(t_mlx_data *mlx_data, unsigned int color) */
/* { */
/*   int	y; */
/*   int	x; */

/*   y = 0; */
/*   while (y < IMG_HEIGHT) */
/*     { */
/*       x = 0; */
/*       while (x < IMG_WIDTH) */
/* 	{ */
/* 	  put_pixel(mlx_data, x, y, color); */
/* 	  ++x; */
/* 	} */
/*       ++y; */
/*     } */
/* } */

/* static int		gere_key(int keycode, void *param) */
/* { */
/*   (void) param; */
/*   if (keycode == 65307) */
/*     { */
/*       printf("Fdf Exited\n"); */
/*       exit(EXIT_SUCCESS); */
/*     } */
/*   return (0); */
/* } */

/* static int		gere_expose(void *param) */
/* { */
/*   t_mlx_data	*mlx_data; */

/*   mlx_data = (t_mlx_data *)param; */
/*   mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_win, */
/* 			  mlx_data->mlx_img, IMG_COORDX, IMG_COORDY); */
/*   return (0); */
/* } */


/* static int	fdf(t_point_data **map) */
/* { */
/*   t_mlx_data	mlx_data; */
/*   (void)map; */

/*   mlx_data.mlx_ptr = mlx_init(); */
/*   mlx_data.mlx_win = mlx_new_window(mlx_data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FDF"); */
/*   mlx_data.mlx_img = mlx_new_image(mlx_data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT); */
/*   mlx_data.data = mlx_get_data_addr(mlx_data.mlx_img, &(mlx_data.bpp), */
/* 				    &(mlx_data.size_line), &(mlx_data.endian)); */
/*   color_image(&mlx_data, mlx_get_color_value(mlx_data.mlx_ptr, 0xFF00FF)); */
/*   mlx_put_image_to_window(mlx_data.mlx_ptr, mlx_data.mlx_win, */
/* 			  mlx_data.mlx_img, IMG_COORDX, IMG_COORDY); */
/*   mlx_key_hook(mlx_data.mlx_win, &gere_key, &mlx_data); */
/*   mlx_expose_hook(mlx_data.mlx_win, &gere_expose, &mlx_data); */
/*   mlx_loop(mlx_data.mlx_ptr); */
/*   return (0); */
/* } */

int		main(int ac, char **av)
{
  t_map_data		map_data;

  memset(&map_data, 0, sizeof(map_data));
  if (ac != 2 || !(av[1]) || (get_map(av[1], &map_data) == -1) /* || fdf(map) */)
    return (-1);
  /* free_map(&map_data); */
  return (0);
}
