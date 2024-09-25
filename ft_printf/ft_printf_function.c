/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:11:30 by sben-rho          #+#    #+#             */
/*   Updated: 2023/11/29 15:56:06 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_size(int nb)
{
	int				i;
	unsigned int	abs;

	if (nb < 0)
		abs = nb * -1;
	else
		abs = nb;
	i = 1;
	while (abs > 9)
	{
		abs = abs / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr_count(int *cwrite, int nb)
{
	int	len;

	len = get_size(nb);
	if (ft_putnbr_fd(nb, 1) == -1)
		return (-1);
	if (nb >= 0)
		*cwrite = *cwrite + len;
	else
		*cwrite = *cwrite + len + 1 ;
	return (0);
}

int	ft_putnbr_base(unsigned long long n, int i, int *cwrite)
{
	unsigned int	k;
	char			*base;

	if (i == 1)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	k = ft_strlen(base);
	if (n >= k)
	{
		ft_putnbr_base(n / k, i, cwrite);
		ft_putnbr_base(n % k, i, cwrite);
	}
	else
	{
		if (ft_putchar_fd(base[n], 1) == -1)
			return (-1);
		*cwrite = *cwrite + 1;
	}
	return (0);
}

int	print_address(unsigned long long add, int *cwrite)
{
	if (add == 0)
	{
		if (string_function(cwrite, "(nil)") == -1)
			return (-1);
		return (0);
	}
	if (ft_putstr_fd("0x", 1) == -1)
		return (-1);
	*cwrite = *cwrite + 2;
	if (ft_putnbr_base(add, 0, cwrite) == -1)
		return (-1);
	return (0);
}

int	ft_putunbr_count(int *cwrite, unsigned int nb)
{
	if (nb > 9)
	{
		ft_putunbr_count(cwrite, nb / 10);
		ft_putunbr_count(cwrite, nb % 10);
	}
	else
	{
		if (ft_putchar_fd(nb + '0', 1) == -1)
			return (-1);
		*cwrite = *cwrite + 1;
	}
	return (0);
}
