/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbouguer <gbouguer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:25:58 by gbouguer          #+#    #+#             */
/*   Updated: 2023/11/16 19:14:11 by gbouguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	index;
	size_t	i;
	size_t	k;

	if (size == 0)
		return (ft_strlen(src));
	dst_len = ft_strlen(dst);
	if (size <= dst_len)
		return (ft_strlen(src) + size);
	index = 0;
	k = size;
	while (dst[index] && k-- != 0)
		index++;
	i = 0;
	while (src[i] && (i + index + 1) < (size))
	{
		dst[index + i] = src[i];
		i++;
	}
	if (i < size)
		dst[index + i] = '\0';
	return (ft_strlen(src) + dst_len);
}
