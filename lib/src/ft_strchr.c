/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <bigotte.ewan@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 21:48:43 by ebigotte          #+#    #+#             */
/*   Updated: 2024/11/12 13:02:13 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strchr(const char *str, char ch)
{
	if (str == NULL)
		return (NULL);
	while (*str != ch)
	{
		if (!*str)
			return (NULL);
		str++;
	}
	return ((char *)str);
}
