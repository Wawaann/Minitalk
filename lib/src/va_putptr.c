/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:31:05 by ebigotte          #+#    #+#             */
/*   Updated: 2024/11/08 14:44:44 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	va_putptr(va_list *list)
{
	unsigned long long	ptr;
	int					size;

	ptr = (unsigned long long)va_arg(*list, void *);
	size = 2;
	if (ptr == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	ft_putstr("0x");
	size += ft_nblen_base(ptr, 16);
	ft_putnbr_base(ptr, 16, 0);
	return (size);
}
