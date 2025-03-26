/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <bigotte.ewan@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:02:36 by ebigotte          #+#    #+#             */
/*   Updated: 2024/11/29 16:01:00 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	is_set(char c, const char *set)
{
	if (c == '\0')
		return (0);
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *s, const char *set)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s);
	while (is_set(s[start], set))
		start++;
	while (end > start && is_set(s[end - 1], set))
		end--;
	str = ft_calloc(end - start + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s[start++];
	return (str);
}
/*
int main()
{
	char *s = "";
	char *set = " ";
	char *str = ft_strtrim(s, set);
	printf("str: %s\n", str);
	return (0);
}*/
