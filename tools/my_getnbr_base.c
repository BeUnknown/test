#include "string_tools.h"

static int	is_base(char c, char *base)
{
  int		i;

  i = 0;
  while (base[i])
  {
    if (base[i] == c)
      return (1);
    i++;
  }
  return (0);
}

static int	is_neg(char *nb, char *base, int *p, int *i)
{
  int		j;
  int		neg;

  neg = 0;
  j = 0;
  while (nb[j] && !is_base(nb[j], base))
  {
    if (nb[j] == '-')
      neg++;
    ++j;
  }
  *p = j;
  while (nb[j])
  {
    ++j;
    *i += 1;
  }
  return (neg % 2);
}

int	my_getnbr_base(char *nb, char *base)
{
  int	i;
  int	p;
  int	res;
  int	b;
  int	neg;

  i = 0;
  p = 0;
  res = 0;
  neg = is_neg(nb, base, &p, &i);
  while (i > 0)
  {
    b = 0;
    while (base[b] && (base[b] != nb[p]))
      ++b;
    res += b * my_pow(my_strlen(base), i - 1);
    ++p;
    --i;
  }
  if (neg)
    res *= -1;
  return (res);
}
