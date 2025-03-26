/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 22:01:51 by ebigotte          #+#    #+#             */
/*   Updated: 2024/11/08 14:43:58 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strncmp(const char *f, const char *s, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (0);
	while (f[i] && f[i] == s[i] && i < size - 1)
		i++;
	return (f[i] - s[i]);
}
