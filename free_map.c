#include <stdlib.h>
#include "fdf.h"

void	free_map(t_map_data *map_data)
{
  int	i;

  i = 0;
  while (i < map_data->ymax)
  {
    free(map_data->map[i]);
    ++i;
  }
  free(map_data->map);
}
