/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:54:59 by sben-rho          #+#    #+#             */
/*   Updated: 2024/01/31 12:05:08 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*get_size(ssize_t nbr, int len, long long int abs_int, char *base)
{
	char	*nb;

	if (nbr < 0)
	{
		nb = (char *)malloc((sizeof(char) * len) + 3);
		if (!nb)
			return (NULL);
		len++;
		nb[0] = '-';
	}
	else
	{
		nb = (char *) malloc((sizeof(char) * len) + 2);
		if (!nb)
			return (NULL);
	}
	if (abs_int == 0)
		nb[0] = base[0];
	return (nb);
}

int	ft_len_int(ssize_t nbr, ssize_t len_base)
{
	int	i;

	i = 0;
	if (nbr == 10)
		return (3);
	while (nbr != 0)
	{
		i++;
		nbr = nbr / len_base;
	}
	if (i == 0)
		return (0);
	return (i - 1);
}

char	*ft_itoa_base(ssize_t nbr, char *base)
{
	int			len;
	int			i;
	ssize_t		len_base;
	char		*nb;
	long long	abs_int;

	len_base = ft_strlen(base);
	i = -1;
	len = ft_len_int(nbr, len_base);
	abs_int = nbr;
	if (nbr < 0)
		len++;
	if (nbr < 0)
		abs_int = abs_int * -1;
	nb = get_size(nbr, len, abs_int, base);
	if (nb == NULL)
		return (NULL);
	while (abs_int != 0)
	{
		nb[len - ++i] = base[abs_int % len_base];
		abs_int = abs_int / len_base;
	}
	nb[len + 1] = '\0';
	return (nb);
}

long int	ft_atol(const char *nptr)
{
	long int	nb;
	int			sign;
	int			i;

	sign = 1;
	i = 0;
	nb = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i = i + 1;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (nb * sign);
}
