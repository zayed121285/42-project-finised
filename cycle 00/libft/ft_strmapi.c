
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ret;

	if (s == NULL)
		return (NULL);
	i = ft_strlen(s);
	ret = malloc(i + 1);
	if (ret == NULL)
		return (NULL);
	ret[i] = '\0';
	while (i-- > 0)
		ret[i] = (*f)(i, s[i]);
	return (ret);
}
