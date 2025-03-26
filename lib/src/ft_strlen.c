/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:00:23 by ebigotte          #+#    #+#             */
/*   Updated: 2024/12/02 14:33:35 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (i);
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlen_to(const char *s, char c)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (i);
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

size_t	ft_tablen(char **tab)
{
	size_t	i;

	i = 0;
	if (tab == NULL)
		return (i);
	while (tab[i])
		i++;
	return (i);
}
