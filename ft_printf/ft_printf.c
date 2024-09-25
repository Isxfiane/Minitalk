/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:48:03 by sben-rho          #+#    #+#             */
/*   Updated: 2023/12/13 11:01:02 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	string_function(int *cwrite, char *str)
{
	if (!str)
	{
		if (ft_putstr_fd("(null)", 1) == -1)
			return (-1);
		*cwrite = *cwrite + 6;
		return (0);
	}
	if (ft_putstr_fd(str, 1) == -1)
		return (-1);
	*cwrite = *cwrite + ft_strlen(str);
	return (0);
}

static size_t	writebase(const char *str, int *cwrite, unsigned int i)
{
	size_t	count;

	count = 0;
	while (str[i] != '\0' && str[i] != '%')
	{
		if (ft_putchar_fd(str[i], 1) == -1)
			return (-1);
		i++;
		count++;
	}
	*cwrite = *cwrite + count;
	return (count);
}

static int	after_sign(int *cwrite, va_list args, char c)
{
	int	temp;

	temp = 1;
	if (c == 'c')
		temp = ft_putchar_fd(va_arg(args, int), 1);
	if (c == 's')
		temp = string_function(cwrite, va_arg(args, char *));
	if (c == 'p')
		temp = print_address(va_arg(args, unsigned long long), cwrite);
	if (c == 'i' || c == 'd')
		temp = ft_putnbr_count(cwrite, (va_arg(args, int)));
	if (c == 'u')
		temp = ft_putunbr_count(cwrite, va_arg(args, unsigned int));
	if (c == 'x')
		temp = ft_putnbr_base(va_arg(args, unsigned int), 0, cwrite);
	if (c == 'X')
		temp = ft_putnbr_base(va_arg(args, unsigned int), 1, cwrite);
	if (c == '%')
		temp = ft_putchar_fd('%', 1);
	if (c == 'c' || c == '%')
		*cwrite = *cwrite + 1;
	if (temp == -1 || temp == 1)
		return (-1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int				cwrite;
	unsigned int	i;
	unsigned int	len;
	va_list			args;

	cwrite = 0;
	i = 0;
	len = ft_strlen(str);
	va_start(args, str);
	while (i < len)
	{
		i = i + writebase(str, &cwrite, i);
		if (i > len || i + 1 > len)
			break ;
		if (after_sign(&cwrite, args, str[i + 1]) == -1)
		{
			va_end(args);
			return (-1);
		}
		i = i + 2;
	}
	va_end(args);
	return (cwrite);
}
