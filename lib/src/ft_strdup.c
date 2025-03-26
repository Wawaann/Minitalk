/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:02:51 by ebigotte          #+#    #+#             */
/*   Updated: 2024/12/02 17:20:29 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *src)
{
	size_t	i;
	char	*cpy;

	i = 0;
	cpy = ft_calloc(ft_strlen(src) + 1, sizeof(char));
	if (!cpy)
		return (NULL);
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	return (cpy);
}

void	ft_tabfree(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**ft_tabdup(char **tab)
{
	size_t	i;
	char	**cpy;

	i = 0;
	cpy = ft_calloc(ft_tablen(tab) + 1, sizeof(char *));
	if (!cpy)
		return (NULL);
	while (tab[i])
	{
		cpy[i] = ft_strdup(tab[i]);
		if (!cpy[i])
		{
			ft_tabfree(cpy);
			return (NULL);
		}
		i++;
	}
	return (cpy);
}
