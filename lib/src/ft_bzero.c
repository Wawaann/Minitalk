/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:52:28 by ebigotte          #+#    #+#             */
/*   Updated: 2024/11/08 14:43:58 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_bzero(void *ptr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
}
/*
int main(void)
{
	//test la fonciton avec un char *
	char array [] = "Hello";
	size_t size = sizeof( int ) * 5;
	int length;

	for( length = 0; length < 5; length++) {
		printf( "%c ", array[ length ] );
	}
	printf( "\n" );

	ft_bzero( array, size );

	for( length = 0; length < 5; length++) {
		printf( "%c ", array[ length ] );
	}
	printf( "\n" );

	//test la fonction avec un int *
	int array2 [] = {1, 2, 3, 4, 5};
	size_t size2 = sizeof( int ) * 5;
	int length2;

	for( length2 = 0; length2 < 5; length2++) {
		printf( "%d ", array2[ length2 ] );
	}
	printf( "\n" );

	ft_bzero( array2, size2 );

	for( length2 = 0; length2 < 5; length2++) {
		printf( "%d ", array2[ length2 ] );
	}
	printf( "\n" );

	return (0);
}*/