#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<stdlib.h>

char		*file_get_contents(const char *path)
{
  int		fd;
  int		size;
  char		*buf;
  int		ret;

  buf = NULL;
  fd = open(path, O_RDONLY);
  if (fd != -1)
  {
    size = lseek(fd, 0, SEEK_END);
    if (size != -1 && lseek(fd, 0, SEEK_SET) != -1)
      if ((buf = malloc(size + 1)))
      {
	ret = read(fd, buf, size);
	if (ret != -1)
	  buf[ret] = '\0';
	else {
	  free(buf);
	  buf = NULL;
	}
      }
    close(fd);
  }
  return (buf);
}
