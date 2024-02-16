/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbouguer <gbouguer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:43:28 by gbouguer          #+#    #+#             */
/*   Updated: 2024/02/16 19:11:55 by gbouguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (!ptr)
		return (malloc(size));
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(size);
	if (!new_ptr)
		return (NULL);
	ft_memcpy(new_ptr, ptr, size);
	return (new_ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*tab;

	if (!s1)
		s1 = ft_strdup("");
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	tab = malloc(len_s1 + len_s2 + 1);
	if (!tab)
		return (NULL);
	ft_memcpy(tab, s1, len_s1);
	ft_memcpy(tab + len_s1, s2, len_s2 + 1);
	free(s1);
	return (tab);
}

void	join(char *c)
{
	static char	*str = NULL;

	if (c)
	str = ft_strjoin(str, c);
	else
	{
		ft_putstr_fd("Your message : ", 1);
		ft_putstr_fd(str, 1);
		write(1, "\n", 1);
		free(str);
		str = NULL;
	}
}

void	bit_decrypt(int sig, siginfo_t *struct_sa, void *t)
{
	static int	i = 0;
	static char	c = 0;

	(void)t;
	if (sig == SIGUSR1)
		c = (c << 1) | 0;
	else if (sig == SIGUSR2)
		c = (c << 1) | 1;
	if (i < 8)
		i++;
	if (i > 7)
	{
		join(&c);
		i = 0;
		c = 0;
	}
	kill(struct_sa->si_pid, SIGUSR2);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argc;
	(void)argv;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = bit_decrypt;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	ft_putstr_fd("PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
