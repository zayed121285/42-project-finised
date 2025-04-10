/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsid-ele <zsid-ele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 12:07:48 by zsid-ele          #+#    #+#             */
/*   Updated: 2025/01/26 12:52:07 by zsid-ele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

void	ft_putchar(char c, int *ret_val);
void	ft_putstr(char *str, int *ret_val);
void	ft_putnbr(int num, int *ret_val);
void	ft_putptr(unsigned long num, int *ret_val);
void	ft_putunbr(unsigned int num, int *ret_val);
size_t	ft_strlen(const char *str);
char	*ft_convert(size_t num, char *repres);
int		ft_printf(const char *str, ...);

#endif
