/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:47:35 by ebigotte          #+#    #+#             */
/*   Updated: 2024/11/08 14:43:58 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	c;
	size_t	d;

	c = ft_strlen(dest);
	d = 0;
	if (size <= c)
		return (size + ft_strlen(src));
	while (src[d] != '\0' && c < size - 1)
	{
		dest[c] = src[d];
		c++;
		d++;
	}
	dest[c] = '\0';
	return (ft_strlen(dest) + ft_strlen(&src[d]));
}
/*
int main()
{
    char dest[] = "Ban";  // Destination avec de l'espace
    char src[] = "anasplit";
    unsigned int size = 4;  // Taille totale du buffer de dest

    printf("Avant ft_strlcat : '%s'\n", dest);

    // Appel de la fonction ft_strlcat
    unsigned int result = ft_strlcat(dest, src, size);

    printf("Après ft_strlcat : '%s'\n", dest);
    printf("Longueur totale après concaténation : %u\n", result);

    return 0;
}*/