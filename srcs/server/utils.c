/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:44:00 by sben-rho          #+#    #+#             */
/*   Updated: 2024/01/23 14:42:58 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	ft_strstr(const char *str, const char *tofind)
{
	int	i;
	int	f;
	int	k;

	i = 0;
	while (str[i] != '\0')
	{
		f = 0;
		k = 0;
		while (tofind[f] != '\0')
		{
			if (str[i + f] == tofind[k])
				k++;
			else
				break ;
			f++;
			if (k == ft_strlen(tofind))
				return (i);
		}
		i++;
	}
	return (-1);
}

char	int_to_char(int a)
{
	if (a == 1)
		return ('1');
	else
		return ('0');
}

int	get_index(char c, const char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	i;
	int	nb;

	sign = 1;
	i = 0;
	nb = 0;
	while ((str[i] <= 13 && str[i] >= 9) || (str[i] == 32))
		i++;
	while ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (get_index(str[i], base) != -1)
	{
		nb = nb * ft_strlen(base) + get_index(str[i], base);
		i++;
	}
	return (sign * nb);
}
