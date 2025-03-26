/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:24:36 by ebigotte          #+#    #+#             */
/*   Updated: 2024/11/08 14:44:44 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	va_putnbr(va_list *list)
{
	int	n;

	n = (long long)va_arg(*list, long long);
	ft_putnbr(n);
	return (ft_nblen(n));
}

int	va_putunsigned(va_list *list)
{
	unsigned int	n;

	n = (unsigned int)va_arg(*list, int);
	ft_putnbr(n);
	return (ft_nblen(n));
}

int	va_puthexa_low(va_list *list)
{
	unsigned int	n;

	n = (unsigned int)va_arg(*list, unsigned int);
	ft_putnbr_base(n, 16, 0);
	return (ft_nblen_base(n, 16));
}

int	va_puthexa_up(va_list *list)
{
	unsigned int	n;

	n = (unsigned int)va_arg(*list, unsigned int);
	ft_putnbr_base(n, 16, 1);
	return (ft_nblen_base(n, 16));
}
