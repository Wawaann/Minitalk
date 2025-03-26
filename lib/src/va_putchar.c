/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:55:51 by ebigotte          #+#    #+#             */
/*   Updated: 2024/11/08 14:44:44 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	va_putchar(va_list *list)
{
	ft_putchar((char)va_arg(*list, int));
	return (1);
}

int	va_putpercent(va_list *list)
{
	(void)list;
	ft_putchar('%');
	return (1);
}
