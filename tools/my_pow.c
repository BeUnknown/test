int	my_pow(int nb, int pow)
{
  if (pow == 0)
    return (1);
  else
    return (nb * my_pow(nb, pow - 1));
}
