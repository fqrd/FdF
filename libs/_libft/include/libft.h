/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaquard <fcaquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 18:05:46 by fcaquard          #+#    #+#             */
/*   Updated: 2021/08/26 14:28:01 by fcaquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <limits.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "ft_printf.h"
# include "get_next_line.h"

// ascii
int		ft_isspace(int c);
int		ft_isalnum(int c);
int		ft_isalpha(int c );
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

// char change
int		ft_tolower(int c);
int		ft_toupper(int c);

// type change
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
int		ft_atoi_hex(char *str);

// print
void	ft_putnbr(long long nb);
int		ft_putchar(unsigned char c);
int		ft_putstr(char *s);

// sizes/counters
size_t	ft_strlen(const char *str);
size_t	ft_intlen(long long d);
size_t	ft_arrlen(char **array);
size_t	ft_countchar(char *str, char c);
size_t	ft_charpos(char *str, char c);

// math
int		ft_power(int nb, int power);

// strings
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

// memory
void	*ft_calloc(size_t nmemb, size_t size);

#endif