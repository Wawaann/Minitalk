/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:25:35 by ebigotte          #+#    #+#             */
/*   Updated: 2024/11/08 14:43:58 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	unsigned char	*to;
	unsigned char	*from;

	to = (unsigned char *)dest;
	from = (unsigned char *)src;
	if (from == to || size == 0)
		return (dest);
	if (to > from && to < from + (int)size)
	{
		to += size;
		from += size;
		while (size--)
			*--to = *--from;
		return (dest);
	}
	if (from > to && from < to + (int)size)
	{
		while (size--)
			*to++ = *from++;
		return (dest);
	}
	ft_memcpy(dest, src, size);
	return (dest);
}
/*
#define ELEMENT_COUNT 10
#include <string.h>

int main()
{
	int		data[] = {20, 30, 40, 50, 60, 70, 80, 90, 100, 0};
	void	*source = (void *) data;
	void	*destination = (void *) (data + 1);
	size_t	size = (ELEMENT_COUNT - 1) * sizeof(int);

	for(int i = 0; i < ELEMENT_COUNT; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");

	ft_memmove(destination, source, size);

	data[0] = 10;

	for(int i = 0; i < ELEMENT_COUNT; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
	return 0;
}
int main()
{
	char str[] = "1234567890";
	char dest[] = "0000000000";
	size_t size = 10;

	printf("Before memmove: %s\n", str);
	ft_memmove(dest, str, size);
	printf("After memmove: %s\n", str);
	return 0;
}*/
