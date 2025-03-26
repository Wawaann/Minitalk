/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:06:44 by ebigotte          #+#    #+#             */
/*   Updated: 2024/11/08 15:43:38 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	is_sep(char c, char sep)
{
	if (c == '\0' || c == sep)
		return (1);
	return (0);
}

size_t	count_word(const char *s, char ch)
{
	size_t	word;
	size_t	i;

	word = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && is_sep(s[i], ch) > 0)
			i++;
		if (is_sep(s[i], ch) < 1)
			word++;
		while (is_sep(s[i], ch) < 1)
			i++;
	}
	return (word);
}

void	get_word(char *word, const char *s, char ch)
{
	size_t	i;

	i = 0;
	while (is_sep(s[i], ch) < 1)
	{
		word[i] = s[i];
		i++;
	}
}

void	get_spilt(char **split, const char *s, char ch)
{
	size_t	i;
	size_t	j;
	size_t	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (is_sep(s[i], ch) < 1)
		{
			j = 0;
			while (is_sep(s[i + j], ch) < 1)
				j++;
			split[word] = (char *)ft_calloc(j + 1, sizeof(char));
			get_word(split[word], s + i, ch);
			i += j;
			word++;
		}
		else
			i++;
	}
}

char	**ft_split(const char *s, char ch)
{
	char	**split;
	size_t	word;

	word = count_word(s, ch);
	split = (char **)ft_calloc(word + 1, sizeof(char *));
	get_spilt(split, s, ch);
	return (split);
}
