/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 02:58:26 by pyago-ra          #+#    #+#             */
/*   Updated: 2022/03/09 12:03:26 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

# ifndef TRUE
#  define TRUE 1
# endif
# ifndef FALSE
#  define FALSE 0
# endif
# ifndef LOWER_UPPER_DIFF
#  define LOWER_UPPER_DIFF 32
# endif
# ifndef INT_SIZE_MAX
#  define INT_SIZE_MAX 2147483647
# endif
# ifndef INT_SIZE_MIN
#  define INT_SIZE_MIN -2147483648
# endif

typedef struct sstring
{
	unsigned char	*prt;
	unsigned long	len;
}	t_string;

char	*ft_itoa(int n);
int		ft_islower(int c);
int		ft_isupper(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
int		ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);
char	ft_strcmp(char *s1, char *s2);
size_t	ft_count_matrix(void **matrix);
void	ft_clear_matrix(void ***matrix);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	**ft_split(char const *s, char c);
void	**ft_creatematrix(size_t __sizeof);
char	*ft_strcatchr(char *src, char new);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_substrstr(char *start, char *end);
void	**ft_addmatrix(void **matrix, void *line);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_replace(char *src, char *old, char *new);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_nreplace(char *_src, char *_old, char *_new, size_t steps);

#endif