/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:48:42 by rrouille          #+#    #+#             */
/*   Updated: 2022/10/04 12:48:42 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYLIB_H
# define MYLIB_H

# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

// struct
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// is
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

// mem
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memset(void *b, int c, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);

// str
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s1, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(const char *s1, const char *set);
char	**ft_split(const char *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

// to
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
char	*ft_unsigned_itoa(unsigned int num);

// put
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);

// print
int		print_hex(unsigned int num, const char conversion);
int		print_nbr(int num);
int		print_ptr(unsigned long long ptr);
int		print_str(char *str);
int		print_unsigned(unsigned int num);

// math
int		ft_fibonacci(int index);
int		ft_find_next_prime(int nb);
int		ft_is_prime(int nb);
int		ft_factorial(int nb);
int		ft_power(int nb, int power);
int		ft_sqrt(int nb);

// lst
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
