/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:53:28 by ebigotte          #+#    #+#             */
/*   Updated: 2025/03/26 16:08:23 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	g_received_ack = 0;

static void	send_sig(pid_t pid, int sig)
{
	if (kill(pid, sig) == -1)
	{
		if (errno == ESRCH)
			ft_printf("Erreur : process with PID %d has stop\n", pid);
		else if (errno == EPERM)
		{
			ft_printf("Erreur : No more permissions to communicate");
			ft_printf(" with the PID %d\n", pid);
		}
		exit (0);
	}
}

void	send_char(pid_t pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_received_ack = 0;
		if (c & (1 << bit))
			send_sig(pid, SIGUSR2);
		else
			send_sig(pid, SIGUSR1);
		bit++;
		while (g_received_ack == 0)
			usleep(50);
	}
}

void	send_message(pid_t pid, char *str)
{
	int	i;

	i = 0;
	ft_printf("Message size: %d\n", ft_strlen(str));
	while (str[i])
	{
		send_char(pid, str[i]);
		i++;
	}
	send_char(pid, '\0');
}

void	handle_signal(int signal)
{
	if (signal == SIGUSR1)
	{
		g_received_ack = 1;
	}
	if (signal == SIGUSR2)
	{
		ft_printf("Message received by server\n");
		exit(0);
	}
}

int	main(int ac, char **av)
{
	pid_t				pid;
	struct sigaction	sa;

	if (ac != 3)
	{
		ft_printf("Usage: %s [PID] [MESSAGE]\n", av[0]);
		return (0);
	}
	if (ft_strdigit(av[1]) == 0)
	{
		ft_printf("Error: wrong PID\n");
		return (0);
	}
	pid = ft_atoi(av[1]);
	sa.sa_handler = handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	send_message(pid, av[2]);
	pause();
	return (0);
}
