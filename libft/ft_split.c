/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbouguer <gbouguer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:23:26 by gbouguer          #+#    #+#             */
/*   Updated: 2023/11/18 00:34:07 by gbouguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

// static size_t	count_words(char const *s, char c)
// {
// 	size_t	words;
// 	size_t	i;

// 	words = 0;
// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
// 			words++;
// 		i++;
// 	}
// 	return (words);
// }

// static void	fill_tab(char *new, char const *s, char c)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i] && s[i] != c)d 2015
// 	{
// 		new[i] = s[i];
// 		i++;
// 	}
// 	new[i] = '\0';
// }

// static void	set_mem(char **tab, char const *s, char c)
// {
// 	size_t	count;
// 	size_t	index;
// 	size_t	i;

// 	index = 0;
// 	i = 0;
// 	while (s[index])
// 	{
// 		count = 0;
// 		while (s[index + count] && s[index + count] != c)
// 			count++;
// 		if (count > 0)
// 		{
// 			tab[i] = malloc(sizeof(char) * (count + 1));
// 			if (!tab[i])
// 				return ;
// 			fill_tab(tab[i], (s + index), c);
// 			i++;
// 			index = index + count;
// 		}
// 		else
// 			index++;
// 	}
// 	tab[i] = 0;
// }

// char	**ft_split(char const *s, char c)
// {
// 	size_t	words;
// 	char	**tab;
// 	size_t	i;

// 	if (!s)
// 		return (NULL);
// 	words = count_words(s, c);
// 	tab = malloc(sizeof(char *) * (words + 1));
// 	if (!tab)
// 		return (NULL);
// 	set_mem(tab, s, c);
// 	if (!tab)
// 	{
// 		i = 0;
// 		while (i < words)
// 		{
// 			free(tab[i]);
// 			i++;
// 		}
// 		free(tab);
// 		return (NULL);
// 	}
// 	return (tab);
// }

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static void	fill_tab(char *new, char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
}

void	free_tab(char **ret)
{
	int	i;

	i = 0;
	while (ret[i])
		free(ret[i++]);
	free(ret);
}

static char	**set_mem(char **tab, char const *s, char c)
{
	size_t	count;
	size_t	index;
	size_t	i;

	index = 0;
	i = 0;
	while (s[index])
	{
		count = 0;
		while (s[index + count] && s[index + count] != c)
			count++;
		if (count > 0)
		{
				tab[i] = malloc(sizeof(char) * (count + 1));
			if (!tab[i])
				return (free_tab(tab), NULL);
			fill_tab(tab[i], (s + index), c);
			i++;
			index = index + count;
		}
		else
			index++;
	}
	tab[i] = 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**tab;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	return (set_mem(tab, s, c));
}
