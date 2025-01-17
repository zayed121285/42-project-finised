
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dst;
	char	*sr;

	i = 0;
	dst = dest;
	sr = (void *) src;
	while (n-- > 0 && dest != src)
	{
		dst[i] = sr[i];
		i++;
	}
	return (dest);
}
