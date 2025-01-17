
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == 0)
		write(fd, "0", 1);
	if (n > 0)
	{
		c = (n % 10) + '0';
		if (n / 10 != 0)
			ft_putnbr_fd(n / 10, fd);
		write(fd, &c, 1);
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		c = ((n % 10) * -1) + '0';
		if (n / 10 != 0)
			ft_putnbr_fd((n / 10) * -1, fd);
		write(fd, &c, 1);
	}
}
