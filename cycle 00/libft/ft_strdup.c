
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*copy;

	len = ft_strlen(s1);
	copy = malloc(++len);
	if (copy == NULL)
		return (NULL);
	while (--len >= 0)
		copy[len] = s1[len];
	return (copy);
}
