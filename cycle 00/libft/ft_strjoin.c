
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	len = ft_strlen(s2);
	ret = malloc(i + ++len);
	if (ret == NULL)
		return (NULL);
	while (--len >= 0)
		ret[i + len] = s2[len];
	while (--i >= 0)
		ret[i] = s1[i];
	return (ret);
}
