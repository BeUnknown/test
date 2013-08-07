#include <string.h>

char		*my_strncpy(char *dest, const char *src, size_t n)
{
  size_t	i;

  i = 0;
  while (i < n)
  {
    dest[i] = src[i];
    ++i;
  }
  dest[i] = '\0';
  return (dest);
}
