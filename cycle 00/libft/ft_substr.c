
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			actlen;
	unsigned int	i;
	char			*substr;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	if (len > ft_strlen(s) - (int) start)
		substr = ft_calloc(ft_strlen(s) - (int) start + 1, 1);
	else
		substr = ft_calloc(len + 1, 1);
	if (substr == NULL)
		return (NULL);
	i = start;
	actlen = 0;
	while (s[i] != '\0' && actlen < len)
		substr[actlen++] = (char) s[i++];
	return (substr);
}
