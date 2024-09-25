/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:50:04 by sben-rho          #+#    #+#             */
/*   Updated: 2024/01/25 15:56:38 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	g_sigact;

void	handle_usr1(int signo)
{
	if (signo == SIGUSR1)
		g_sigact = 1;
}

int	check_args(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_printf("I need a PID !\n");
		return (1);
	}
	else if (argc > 3)
	{
		ft_printf("Too much args for me\n");
		return (1);
	}
	if (argv[2] == NULL)
	{
		ft_printf("Invalid Args\n");
		return (1);
	}
	else
		return (0);
}

void	send_bin(const char *str, long int pid)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		g_sigact = 0;
		if (str[i] == '0')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		while (g_sigact == 0)
			continue ;
	}
}

void	send_all(char **argv, long int pid)
{
	char	*temp;
	int		i;

	i = -1;
	temp = ft_itoa_base(ft_strlen(argv[2]), "01");
	if (temp == NULL)
		return ;
	send_bin(temp, pid);
	free(temp);
	send_bin("100000000", pid);
	while (argv[2][++i] != '\0')
	{
		temp = ft_itoa_base((unsigned char)argv[2][i], "01");
		send_bin(temp, pid);
		free(temp);
		send_bin("100000000", pid);
	}
	send_bin("100000000", pid);
}

int	main(int argc, char **argv)
{
	long int			pid;
	struct sigaction	sa;

	if (check_args(argc, argv) == 1)
		return (1);
	pid = ft_atol(argv[1]);
	if (pid <= 0 || pid > 4194304)
	{
		ft_printf("Invalid PID !\n");
		return (1);
	}
	sa.sa_handler = &handle_usr1;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	send_all(argv, pid);
	return (0);
}
