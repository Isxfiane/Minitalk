/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:40:58 by sben-rho          #+#    #+#             */
/*   Updated: 2024/01/25 11:02:38 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>

# include "ft_printf.h"

char		*ft_itoa_base(ssize_t nbr, char *base);
int			ft_strstr(const char *str, const char *tofind);
char		int_to_char(int a);
int			ft_atoi_base(char *str, char *base);
char		*copyandclear(char *buffer, int *n, char *result);
long int	ft_atol(const char *nptr);
void		send_bin(const char *str, long int pid);

#endif