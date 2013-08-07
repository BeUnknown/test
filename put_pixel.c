#include "fdf.h"

int	put_pixel(t_mlx_data *mlx_data, int x, int y, unsigned int color)
{
  unsigned int *data;

  data = (unsigned int *)(mlx_data->data);
  data[y * IMG_WIDTH + x] = color;
  return (0);
}
