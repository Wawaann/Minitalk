/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:47:56 by ebigotte          #+#    #+#             */
/*   Updated: 2025/03/26 16:08:28 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static bool	send_sig(pid_t pid, int sig)
{
	if (kill(pid, 0) == -1)
	{
		return (false);
	}
	kill(pid, sig);
	return (true);
}

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static unsigned char	acc = 0;
	static int				bit = 0;

	(void)context;
	if (signal == SIGUSR2)
		acc |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &acc, 1);
		if (acc == '\0')
		{
			write(1, "\n", 1);
			if (!send_sig(info->si_pid, SIGUSR2))
				ft_printf("Error: can't send end signal\n");
		}
		acc = 0;
		bit = 0;
	}
	send_sig(info->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	ft_printf("PID : %d\n", pid);
	while (1)
	{
		pause();
	}
	return (0);
}
