#include "../../include/get_next_line.h"

char	*ft_read_to_buf(int fd, size_t *bytes_read)
{
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	*bytes_read = read(fd, buf, BUFFER_SIZE);
	if (*bytes_read <= 0 || *bytes_read > BUFFER_SIZE)
		return (ft_free_buf(&buf));
	buf[*bytes_read] = '\0';
	return (buf);
}

t_buf	*ft_read_to_node(int fd)
{
	t_buf	*new_node;
	char	*buf;
	size_t	bytes_read;

	bytes_read = 0;
	buf = ft_read_to_buf(fd, &bytes_read);
	if (buf == NULL)
		return (NULL);
	new_node = malloc(sizeof(*new_node));
	if (new_node == NULL)
		return (ft_free_buf(&buf));
	new_node->buf = malloc(bytes_read + 1);
	if (new_node->buf == NULL)
	{
		free(new_node);
		return (ft_free_buf(&buf));
	}
	bytes_read = 0;
	new_node->buf[bytes_read] = buf[bytes_read];
	while (buf[bytes_read++] != '\0')
		new_node->buf[bytes_read] = buf[bytes_read];
	new_node->next = NULL;
	ft_free_buf(&buf);
	return (new_node);
}

size_t	ft_line_length(int fd, t_buf **head_node)
{
	size_t	len;
	size_t	i;
	t_buf	*current_node;

	current_node = *head_node;
	len = 0;
	i = 0;
	while (current_node->buf[i] != '\n')
	{
		len++;
		i++;
		if (current_node->buf[i] == '\0')
		{
			i = 0;
			current_node->next = ft_read_to_node(fd);
			if (current_node->next == NULL)
				return (len);
			current_node = current_node->next;
		}
	}
	if (current_node->buf[i] == '\n')
		len++;
	return (len);
}

char	*ft_fill_line(t_buf *current_node, size_t len)
{
	char	*line;
	size_t	i;
	size_t	j;

	line = malloc(len + 1);
	if (line == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len)
	{
		line[i] = current_node->buf[j];
		i++;
		j++;
		if (current_node->buf[j] == '\0')
		{
			current_node = current_node->next;
			j = 0;
		}
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd, int clean)
{
	static t_buf	*line_node[1024] = {NULL};
	char			*line;
	size_t			len;

	if (clean == 1)
	{
		if (line_node[fd] != NULL)
		{
			free(line_node[fd]->buf);
			free(line_node[fd]);
		}
		return (NULL);
	}
	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	if (line_node[fd] == NULL)
		line_node[fd] = ft_read_to_node(fd);
	if (line_node[fd] == NULL)
		return (NULL);
	len = ft_line_length(fd, &line_node[fd]);
	line = ft_fill_line(line_node[fd], len);
	ft_free_node(&line_node[fd]);
	ft_align_line_node(&line_node[fd]);
	return (line);
}
