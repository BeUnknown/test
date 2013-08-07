/*
** get_next_line.c for get_next_line in /home/ducani_m//igraph/p_igraph/fdf
** 
** Made by melanie ducani
** Login   <ducani_m@epitech.net>
** 
** Started on  Thu Dec  9 01:13:54 2010 melanie ducani
** Last update Thu Dec  9 07:14:23 2010 melanie ducani
*/

#include <stdlib.h>
#include <unistd.h>
#include "fdf.h"
#include <stdio.h>

int		sys_error(char *str)
{
  my_putstr(str, 2);
  exit (EXIT_FAILURE);
}

int		find_line(char *buffer, char *s, int fd, t_list *tmp)
{
  static int	y = 0;
  static int	i;
  int		j;
  int		ret;

  j = 0;
  while(buffer[i] != '\n' && j < STR_SIZE - 1)
    {
      s[j++] = buffer[i];
      buffer[i++] = '\0';
      if (buffer[i] == '\0')
	{
	  i = 0;
	  ret = read(fd, buffer, BUF_SIZE - 1);
	  if (ret == -1)
	    sys_error("Error read.\n");
	  else if (ret == 0)
	    {
	      s[j] = '\0';
	      return(-1);
	    }
	}
      if (buffer[i] == '\n')
	{
	  tmp->y = y++;
	  tmp->x = 0;
	}
    }
  s[j] = '\0';
  return (++i);
}

void	error_file(char *path)
{
  int	i;
  
  i = 0;
  while (path[i] != '\0' && path[i] != '.')
    ++i;
  if (path[i] == '\0' || path[i + 1] != 'f' ||
      path[i + 2] != 'd' || path[i + 3] != 'f')
    sys_error("This file is not a fdf file.\n");
}

char		*get_next_line(const int fd, t_list *tmp)
{
  static char	buffer[BUF_SIZE];
  static int	i;
  static int	ret;
  char		*s;
  
  s = malloc(STR_SIZE * sizeof(*s));
  if (s == NULL)
    sys_error("Error malloc.\n");
  buffer[BUF_SIZE - 1] = '\0';
  if (i == 0)
    {
      ret = read(fd, buffer, BUF_SIZE - 1);
      if (ret == -1)
	sys_error("Error read.\n");
      if (ret == 0)
	return (NULL);
    }
  i = find_line(buffer, s, fd, tmp);
  if (i == -1)
    {
      i = 0;
      ret = 0;
    }
    return (s);
}
