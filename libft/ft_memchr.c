/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbouguer <gbouguer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:47:54 by gbouguer          #+#    #+#             */
/*   Updated: 2023/11/09 15:16:47 by gbouguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*inst;

	inst = (unsigned char *)s;
	while (n--)
	{
		if (*inst == (unsigned char)c)
			return (inst);
		inst++;
	}
	return (0);
}
