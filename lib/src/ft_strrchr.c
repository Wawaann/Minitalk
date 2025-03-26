/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 21:51:26 by ebigotte          #+#    #+#             */
/*   Updated: 2024/11/08 14:43:58 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *str, char ch)
{
	char	*occ;

	occ = NULL;
	if (ch == '\0')
		return ((char *)str + ft_strlen(str));
	while (*str)
	{
		if (*str == (char)ch)
			occ = (char *)str;
		str++;
	}
	return (occ);
}
