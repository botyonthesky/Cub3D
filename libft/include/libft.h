#ifndef LIBFT_H
# define LIBFT_H

// Includes standard libraries
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// Includes custom libraries
# include "get_next_line.h"
# include "ft_printf.h"

// Macros
enum	e_dir
{
	FRONT,
	BACK
};

// Singly linked list
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_gc
{
	void			*content;
	char			*file;
	struct s_gc		*next;
}				t_gc;

typedef struct s_color
{
	int	c;
	int	a;
	int	r;
	int	g;
	int	b;
}				t_color;

// Display functions
void		close_fd(t_gc **p, int fd);
void		dup_error(t_gc **ptrs, int fd);
void		ft_close_fd(int fd);
int			fd_is_valid(t_list **p, char *file);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
void		reopen(t_gc **p, int *fd);
void		stdout_to_stderr(t_gc **gc);

//Graphic functions
t_color		ft_hex_to_rgb(int color);
int			ft_rgb_to_hex(t_color c);

// Linked list functions
void		ft_gcadd_back(t_gc **lst, t_gc *new);
void		ft_gcadd_front(t_gc **lst, t_gc *new);
void		ft_gcclear(t_gc **lst);
t_gc		*ft_gcdelfirst(t_gc *lst);
void		ft_gcdellast(t_gc *lst);
void		ft_gcdelone(t_gc **gc, void *p);
t_gc		*ft_gcfindone(t_gc **gc, void *p);
t_gc		*ft_gclast(t_gc *lst);
t_gc		*ft_gcnew(void *content);
int			ft_gcsize(t_gc *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void *));
t_list		*ft_lstdelfirst(t_list *lst, void (*del)(void *));
void		ft_lstdellast(t_list *lst, void (*del)(void *));
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);

// Math functions
int			ft_abs(int nb);
int			ft_find_next_prime(int nb);
int			ft_is_prime(int nb);
int			ft_max(int a, int b);
int			ft_min(int a, int b);
int			ft_mod(int a, int b);
void		ft_swap(int *a, int *b);

// Memory functions
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_free(void *p);
void		ft_freenull(void **p);
void		ft_memcheck(t_gc **ptrs, void *p, int side, char *file);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		ft_failloc(void *p);

// Predicate functions
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_islower(int c);
int			ft_isnumber(const char *nptr);
int			ft_isprint(int c);
int			ft_isspace(int c);
int			ft_isupper(int c);

// String functions
int			ft_atoi(const char *nptr);
long long	ft_atoll(const char *nptr);
char		*ft_c_to_s(char c);
int			count_tokens(char *str, char *sep);
char		*ft_itoa(int n);
char		*ft_ltoa(long n);
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *s, int c);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strdup(const char *s);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strpbrk(const char *s1, const char *s2);
char		*ft_strrchr(const char *s, int c);
char		*ft_strstr(const char *haystack, const char *needle);
int			ft_strtoi(const char *str, char **endptr);
char		*ft_strtok(char *str, const char *delim);
char		*ft_strtok_r(char *str, const char *delim, char **saveptr);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_tolower(int c);
int			ft_toupper(int c);
char		*ft_trimwhitespace(char *str, int side);

#endif
