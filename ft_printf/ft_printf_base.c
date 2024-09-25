/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:25:36 by sben-rho          #+#    #+#             */
/*   Updated: 2023/11/21 11:34:08 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_putchar_fd(char c, int fd)
{
	if (write(fd, &c, 1) == -1)
		return (-1);
	return (0);
}

int	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (ft_putchar_fd(s[i], fd) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		if (write(fd, "-2147483648", 11) == -1)
			return (-1);
		return (0);
	}
	if (n < 0)
	{
		n = n * -1;
		if (ft_putchar_fd('-', fd) == -1)
			return (-1);
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		if (ft_putchar_fd(n + '0', fd) == -1)
			return (-1);
	return (0);
}
