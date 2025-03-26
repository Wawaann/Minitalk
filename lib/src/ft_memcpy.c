/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 22:15:53 by ebigotte          #+#    #+#             */
/*   Updated: 2024/11/08 14:43:58 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memcpy(void *dest, void const *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/*
int main()
{
	//tester la fonction avec un char *
	char array[] = "Hello";
	char array2[] = "World";
	size_t size = sizeof(int) * 5;
	int length;

	for (length = 0; length < 5; length++)
	{
		printf("%c ", array[length]);
	}
	printf("\n");

	ft_memcpy(array, array2, size);

	for (length = 0; length < 5; length++)
	{
		printf("%c ", array[length]);
	}
	printf("\n");

	//tester la fonction avec un int *
	int array3[] = {1, 2, 3, 4, 5};
	int array4[] = {6, 7, 8, 9, 10};
	size_t size2 = sizeof(int) * 5;
	int length2;

	for (length2 = 0; length2 < 5; length2++)
	{
		printf("%d ", array3[length2]);
	}
	printf("\n");

	ft_memcpy(array3, array4, size2);

	for (length2 = 0; length2 < 5; length2++)
	{
		printf("%d ", array3[length2]);
	}
	printf("\n");
	return 0;
}*/
