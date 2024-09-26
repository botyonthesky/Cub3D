#include "../../include/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lstnew;

	lstnew = ft_calloc(1, sizeof(*lstnew));
	if (lstnew == NULL)
		return (NULL);
	lstnew->content = content;
	lstnew->next = NULL;
	return (lstnew);
}
