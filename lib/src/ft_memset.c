/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:04:29 by ebigotte          #+#    #+#             */
/*   Updated: 2024/11/08 14:43:58 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memset(void *ptr, int value, size_t count)
{
	size_t	i;

	if (!ptr)
		return (NULL);
	i = 0;
	while (i < count)
	{
		((unsigned char *)ptr)[i] = (unsigned char)value;
		i++;
	}
	return (ptr);
}
/*
#include <stdlib.h>
#include <string.h>

int main()
{
    // tester la fonction avec un char *
    char array[] = "Hello";
    size_t size = sizeof(int) * 5;
    int length;

    for (length = 0; length < 5; length++)
    {
        printf("%c ", array[length]);
    }
    printf("\n");

    ft_memset(array, 67, size);

    for (length = 0; length < 5; length++)
    {
        printf("%c ", array[length]);
    }
    printf("\n");
    return 0;
}*/