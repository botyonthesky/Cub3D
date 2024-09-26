#include "../../include/libft.h"

t_gc	*ft_gcnew(void *content)
{
	t_gc	*lstnew;

	lstnew = ft_calloc(1, sizeof(*lstnew));
	if (lstnew == NULL)
		return (NULL);
	lstnew->content = content;
	lstnew->next = NULL;
	return (lstnew);
}
