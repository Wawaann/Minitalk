/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:27:31 by ebigotte          #+#    #+#             */
/*   Updated: 2024/11/08 14:43:58 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putnbr_fd(int num, int fd)
{
	long int	nb;
	int			n;

	nb = num;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	if (nb > 9)
	{
		n = nb % 10;
		nb /= 10;
		ft_putnbr_fd(nb, fd);
		ft_putchar_fd(n + '0', fd);
	}
	else
		ft_putchar_fd(nb + '0', fd);
}

void	ft_putnbr_base_fd(unsigned long long n, int base, int up, int fd)
{
	char	*base_str;

	if (up == 1)
		base_str = "0123456789ABCDEF";
	else
		base_str = "0123456789abcdef";
	if (n >= (unsigned long long)base)
		ft_putnbr_base_fd(n / base, base, up, fd);
	ft_putchar_fd(base_str[n % base], fd);
}

void	ft_putnbr(int num)
{
	ft_putnbr_fd(num, 1);
}

void	ft_putnbr_base(unsigned long long n, int base, int up)
{
	ft_putnbr_base_fd(n, base, up, 1);
}
