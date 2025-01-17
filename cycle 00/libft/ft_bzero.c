
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*st;

	st = s;
	while (n-- > 0)
	{
		*st = '\0';
		st++;
	}
}
