#include "../../include/libft.h"

void	stdout_to_stderr(t_gc **gc)
{
	static int	stdout = -1;

	if (stdout == -1)
	{
		stdout = dup(STDOUT_FILENO);
		dup_error(gc, stdout);
		dup_error(gc, dup2(STDERR_FILENO, STDOUT_FILENO));
	}
	else
	{
		dup_error(gc, dup2(stdout, STDOUT_FILENO));
		close(stdout);
		stdout = -1;
	}
}
