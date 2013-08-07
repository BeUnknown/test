#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "fdf.h"
#include "tools/string_tools.h"

static int	get_ordmax(const char *buff)
{
  int		i;
  int		ymax;

  i = 0;
  ymax = 0;
  while (buff[i])
  {
    if (buff[i] == '\n')
      ++ymax;
    ++i;
  }
  if (!ymax || (buff[i - 1] != '\n'))
  {
    fprintf(stderr, "FDF: Error: %s\n", ERROR_LINE);
    return (-1);
  }
  return (ymax);
}

static int	get_absmax(const char *buff)
{
  int		i;
  int		xmax;

  i = 0;
  xmax = 0;
  while (buff[i] && buff[i] != '\n')
  {
    if (buff[i] == ' ')
      ++i;
    else
    {
      xmax += 1;
      while (buff[i] && buff[i] != '\n' && buff[i] != ' ')
	++i;
    }
  }
  if (!xmax)
  {
    fprintf(stderr, "FDF: Error : No values in config file.\n");
    return (-1);
  }
  return (xmax);
}

/* static t_point_data	**allocate_memory(int xmax, int ymax) */
/* { */
/*   int		i; */
/*   t_point_data	**map; */

/*   i = 0; */
/*   if (!(map = malloc((ymax + 1) * sizeof(*map)))) */
/*   { */
/*     perror("malloc"); */
/*     return (NULL); */
/*   } */
/*   while (i < ymax) */
/*   { */
/*     if (!(map[i] = malloc(xmax * sizeof(**map)))) */
/*     { */
/*       perror("malloc"); */
/*       return (NULL); */
/*     } */
/*     ++i; */
/*   } */
/*   map[i] = NULL; */
/*   return (map); */
/* } */

/* static int	fill_map(const char *buff, t_point_data **map, int xmax) */
/* { */
/*   char		*line; */

/*   while ((line = get_line(buff))) */
/*   { */
/*     parse_line(); */
/*   } */

/*   while (buff[i]) */
/*   { */
/*     x = 0; */
/*     while (buff[i] && buff[i] != '\n' && x < xmax) */
/*     { */
/*       if (buff[i] != '\t' && buff[i] != ' ') */
/*       { */
/* 	x++; */
/* 	j = i; */
/* 	while (buff[i] && buff[i] != '\n' && buff[i] != '\t' && buff[i] != ' ') */
/* 	  i++; */
/* 	if (!(value = malloc((i - j + 1) * sizeof(*value)))) */
/* 	  return (-1); */
/* 	my_strncpy(value, buff[j], i - j); */
/* 	parse_value(map, value, x, y); */
/*       } */
/*     } */
/*     ++i; */
/*     ++y; */
/*   } */
/*   return (0); */
/* } */

/* static t_point_data	**create_map(const char *buff, int xmax, int ymax) */
/* { */
/*   t_point_data	**map; */

/*   if (!(map = allocate_memory(xmax, ymax))) */
/*     return (NULL); */
/*   if (fill_map(buff, map, xmax) == -1) */
/*     return (NULL); */
/*   return (map); */
/* } */

static char	**convert_buf(char *buf, int ymax)
{
  char		**tab;
  int		i;
  int		y;

  i = 0;
  y = 1;
  if (!(tab = malloc((ymax + 1) * sizeof(*tab))))
    return (NULL);
  tab[0] = &(buf[0]);
  while (buf[i])
  {
    while (buf[i] && buf[i] != '\n')
      ++i;
    if (buf[i] == '\n')
    {
      printf("dans le while\n");
      while (buf[i] == '\n')
	buf[i++] = '\0';
      if (buf[i])
	tab[y++] = &(buf[i]);
    }
  }
  tab[y] = NULL;
  return (tab);
}

int		get_map(const char *path, t_map_data *map_data)
{
  char		*buf;
  char		**tab;
  int		i;

  if (!(buf = file_get_contents(path)))
  {
    fprintf(stderr, "FDF: Error loading file.\n");
    return (-1);
  }
  if ((map_data->ymax = get_ordmax(buf)) == -1)
    return (-1);
  if ((map_data->xmax = get_absmax(buf)) == -1)
    return (-1);
  if (!(tab = convert_buf(buf, map_data->ymax)))
    return (-1);
  printf("buf = \n%s\n----------------------\n", buf);
  for (i = 0; tab[i]; i += 1)
    printf("tab[%d] : %s\n", i, tab[i]);
  /* map_data->map = create_map(buf, map_data->xmax, map_data->ymax); */
  free(buf);
  free(tab);
  return (0);
}
