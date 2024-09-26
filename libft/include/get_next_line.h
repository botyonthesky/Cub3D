#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct s_buf
{
	char			*buf;
	struct s_buf	*next;
}				t_buf;

char	*get_next_line(int fd, int clean);
t_buf	*ft_read_to_node(int fd);
char	*ft_read_to_buf(int fd, size_t *bytes_read);
void	*ft_free_buf(char	**buf);
size_t	ft_line_length(int fd, t_buf **head_node);
char	*ft_fill_line(t_buf *current_node, size_t len);
void	*ft_free_node(t_buf **head_node);
void	*ft_align_line_node(t_buf	**head_node);
void	*ft_align_buf_to_node(t_buf **head_node, size_t start, size_t end);
void	clean_get_next_line(int fd);

#endif