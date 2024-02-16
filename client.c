/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbouguer <gbouguer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:01:48 by gbouguer          #+#    #+#             */
/*   Updated: 2024/02/16 19:02:38 by gbouguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

int		g_gotit;

void	caught(int sig, siginfo_t *sa, void *t)
{
	(void)t;
	(void)sa;
	if (sig == SIGUSR2)
		g_gotit = 1;
}

void	a_to_b(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		g_gotit = 0;
		if ((c >> bit) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit--;
		while (g_gotit == 0)
			pause();
	}
}

void	send_str(int pid, char *str)
{
	int	i;
	int	str_len;

	str_len = ft_strlen(str);
	i = 0;
	while (i < str_len)
	{
		a_to_b(pid, str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	g_gotit = 0;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = caught;
	sigaction(SIGUSR2, &sa, NULL);
	if (argc == 3)
	{
		ft_putstr_fd("sending ...\n", 1);
		send_str(ft_atoi(argv[1]), argv[2]);
		ft_putstr_fd("sent\n", 1);
		return (0);
	}
	else
	{
		ft_putstr_fd("ERROR SYNTAX\n", 1);
		ft_putstr_fd("Format : ./client 'PID' 'Your message'\n", 1);
	}
	return (0);
}
