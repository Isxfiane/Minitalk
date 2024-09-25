/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_manage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:43:50 by sben-rho          #+#    #+#             */
/*   Updated: 2024/01/31 13:59:13 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*createbuff(char *buffer, ssize_t len, int *n)
{
	int	i;

	i = 0;
	buffer = malloc(sizeof(char) * (len + 1));
	if (!buffer)
	{
		*n = 2;
		return (NULL);
	}
	while (i < len)
	{
		buffer[i] = 1;
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

char	*savechar(char *result, int c, int *n)
{
	int	i;

	i = 0;
	if (c == 0)
	{
		ft_printf("%s\n", result);
		free(result);
		*n = 0;
		return (NULL);
	}
	while (result[i] != 1)
		i++;
	if (result[i] != '\0')
		result[i] = c;
	return (result);
}

char	*cleanbuffer(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		buffer[i] = '2';
		i++;
	}
	return (buffer);
}

char	*copyandclear(char *buffer, int *n, char *result)
{
	ssize_t		i;
	char		*str;
	int			pos;

	pos = ft_strstr(buffer, "100000000");
	if (pos == 0)
		return (savechar(result, 0, n));
	str = malloc(sizeof(char) * (pos + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < pos)
		str[i] = buffer[i];
	str[i] = '\0';
	if (*n == 0)
	{
		i = ft_atoi_base(str, "01");
		result = createbuff(result, i, n);
		*n = 1;
	}
	else
		savechar(result, ft_atoi_base(str, "01"), n);
	buffer = cleanbuffer(buffer);
	free(str);
	return (result);
}
