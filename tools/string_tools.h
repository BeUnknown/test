#ifndef STRING_TOOLS_H_
# define STRING_TOOLS_H_

# include <string.h>

char	*my_strncpy(char *dest, const char *src, size_t n);
int	my_getnbr_base(char *nb, char *base);
int	my_strlen(char *str);
int	my_pow(int nb, int pow);

#endif /* !STRING_TOOLS_H_ */
