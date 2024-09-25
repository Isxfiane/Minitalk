/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:21:18 by sben-rho          #+#    #+#             */
/*   Updated: 2024/01/31 13:54:08 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	g_signal_result[2];

void	handle_usr(int signo, siginfo_t *info, void *context)
{
	(void)context;
	g_signal_result[1] = info->si_pid;
	if (signo == SIGUSR1)
		g_signal_result[0] = 0;
	else if (signo == SIGUSR2)
		g_signal_result[0] = 1;
	else if (signo == SIGINT || signo == SIGQUIT)
		g_signal_result[0] = -2;
	else
		g_signal_result[0] = -1;
}

void	fill(int x, char *buffer, char *result, int n)
{
	int	count;

	count = 0;
	while (g_signal_result[0] != -2)
	{
		if (g_signal_result[0] == 1 || g_signal_result[0] == 0)
		{
			buffer[++x] = int_to_char(g_signal_result[0]);
			if (buffer[x] == '0')
				count++;
			else
				count = 0;
			buffer[x + 1] = '\0';
			g_signal_result[0] = 2;
			if (count == 8)
			{
				result = copyandclear(buffer, &n, result);
				if (result == NULL && n == 2)
					return ;
				x = -1;
				count = 0;
			}
			kill(g_signal_result[1], SIGUSR1);
		}
	}
}

void	freeall(char *result, char *buffer)
{
	free(result);
	free(buffer);
}

int	main(void)
{
	int					x;
	struct sigaction	sa;
	char				*buffer;
	char				*result;
	int					n;

	x = getpid();
	n = 0;
	ft_printf("\t%d\n", x);
	buffer = malloc(sizeof(char) * 40);
	if (!buffer)
		return (1);
	result = NULL;
	g_signal_result[0] = 2;
	sa.sa_sigaction = &handle_usr;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_mask = (sigset_t){0};
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
	x = -1;
	fill(x, buffer, result, n);
	freeall(result, buffer);
	return (0);
}
