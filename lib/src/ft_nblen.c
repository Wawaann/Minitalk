/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:20:19 by ebigotte          #+#    #+#             */
/*   Updated: 2024/11/08 13:30:38 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_nblen(long long n)
{
	size_t	len;

	if (n == LLONG_MIN)
		return (20);
	len = 1;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

size_t	ft_nblen_base(unsigned long long n, int base)
{
	size_t	len;

	len = 1;
	while (n >= (unsigned long long)base)
	{
		n /= base;
		len++;
	}
	return (len);
}
