#include "../../include/libft.h"

int	fd_is_valid(t_list **p, char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		if (p != NULL)
			ft_lstclear(p, ft_free);
		exit(errno);
	}
	return (fd);
}
