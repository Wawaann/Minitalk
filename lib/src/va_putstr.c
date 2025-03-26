/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:55:09 by ebigotte          #+#    #+#             */
/*   Updated: 2024/11/08 14:43:58 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/../include/libft.h"

int	va_putstr(va_list *list)
{
	int		i;
	char	*s;

	i = 0;
	s = (char *)va_arg(*list, char *);
	if (s == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}
