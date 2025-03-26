/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:16:59 by ebigotte          #+#    #+#             */
/*   Updated: 2024/11/08 14:43:58 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	is_sub(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (s2[i] != s1[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*s2)
		return ((char *)s1);
	while (s1[i])
	{
		j = 0;
		while (s1[i] && s1[i] == s2[j] && i < size)
		{
			i++;
			j++;
		}
		if (!s2[j])
			return ((char *)&s1[i - j]);
		i = (i - j) + 1;
	}
	return (NULL);
}
