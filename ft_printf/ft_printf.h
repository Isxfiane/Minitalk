/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:48:17 by sben-rho          #+#    #+#             */
/*   Updated: 2023/11/29 15:52:53 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		string_function(int *cwrite, char *str);
int		ft_putnbr_count(int *cwrite, int nb);
int		ft_putnbr_base(unsigned long long n, int i, int *cwrite);
int		print_address(unsigned long long add, int *cwrite);
int		ft_putunbr_count(int *cwrite, unsigned int nb);
ssize_t	ft_strlen(const char *s);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);

#endif