/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 22:52:35 by ebigotte          #+#    #+#             */
/*   Updated: 2024/11/08 14:50:35 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	get_flag(char c)
{
	size_t	i;
	char	*flags;

	i = 0;
	flags = "cspdiuxX%";
	while (flags[i])
	{
		if (flags[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	init_f_array(t_fptr *f_array)
{
	f_array[0] = va_putchar;
	f_array[1] = va_putstr;
	f_array[2] = va_putptr;
	f_array[3] = va_putnbr;
	f_array[4] = va_putnbr;
	f_array[5] = va_putunsigned;
	f_array[6] = va_puthexa_low;
	f_array[7] = va_puthexa_up;
	f_array[8] = va_putpercent;
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	va_list	list;
	t_fptr	f_array[9];
	int		size;

	i = 0;
	size = 0;
	va_start(list, str);
	init_f_array(f_array);
	while (str[i])
	{
		if (str[i] == '%' && get_flag(str[i + 1]) != -1)
		{
			size += f_array[get_flag(str[++i])](&list);
		}
		else
		{
			ft_putchar(str[i]);
			size++;
		}
		i++;
	}
	va_end(list);
	return (size);
}
