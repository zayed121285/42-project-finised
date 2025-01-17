
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*j;

	i = 0;
	j = b;
	while (i < len)
		j[i++] = c;
	return (b);
}
int main ()
{
	printf("%s",ft_memset("sdkjedkjnd",'4',7));

}