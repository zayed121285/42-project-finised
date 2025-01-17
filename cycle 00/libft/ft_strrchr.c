
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		if (*s == (char) c && i == 0)
			i = 1;
		s++;
	}
	if (*s == (char) c && i == 0)
		i = 1;
	while (i != 0)
	{
		if (*s == (char) c)
			return ((char *) s);
		s--;
	}
	return (NULL);
}
