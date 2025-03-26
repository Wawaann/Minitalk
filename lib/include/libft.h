/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:46:21 by ebigotte          #+#    #+#             */
/*   Updated: 2025/02/18 10:58:39 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <math.h>
# include <fcntl.h>

//		Printf function
int		ft_printf(const char *str, ...);
int		va_putchar(va_list *list);
int		va_puthexa_low(va_list *list);
int		va_puthexa_up(va_list *list);
int		va_putnbr(va_list *list);
int		va_putunsigned(va_list *list);
int		va_putpercent(va_list *list);
int		va_putptr(va_list *list);
int		va_putstr(va_list *list);

typedef int	(*t_fptr)(va_list *);

//		Gnl function
char	*get_next_line(int fd);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

//		Lib base function
int		ft_atoi(const char *str);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t size);
int		ft_straplha(char *str);
int		ft_strdigit(char *str);
int		ft_strncmp(const char *f, const char *s, size_t size);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_itoa(int num);
char	*ft_strchr(const char *str, char ch);
char	*ft_strdup(const char *src);
char	*ft_strjoin(const char *s1, const char *s2);
char	*gnl_strjoin(char *s1, char *s2);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
char	*ft_substr(const char *s, int start, size_t len);
char	*ft_strtrim(const char *s, const char *set);
char	*ft_strrchr(const char *str, char ch);
char	**ft_split(const char *s, char ch);
char	**ft_tabdup(char **tab);
void	ft_bzero(void *ptr, size_t size);
void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl(char *s);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr(int num);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putnbr_base(unsigned long long n, int base, int up);
void	ft_putnbr_base_fd(unsigned long long n, int base, int up, int fd);
void	ft_putstr(char *s);
void	ft_putstr_fd(char *s, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(const void *ptr, int ch, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t size);
void	*ft_memset(void *ptr, int value, size_t count);
size_t	ft_nblen(long long n);
size_t	ft_nblen_base(unsigned long long n, int base);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *s);
size_t	ft_strlen_to(const char *s, char c);
size_t	ft_tablen(char **tab);

#endif
