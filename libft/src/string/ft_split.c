#include "../../include/libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i++] != '\0')
		if ((s[i] == c || s[i] == '\0') && s[i - 1] != c)
			words++;
	return (words);
}

static void	*ft_free_dict(char **dict, int i)
{
	while (i--)
		free(dict[i]);
	free(dict);
	dict = NULL;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**dict;
	int		words;
	int		i;
	size_t	len;

	words = ft_count_words(s, c);
	dict = ft_calloc(words + 1, sizeof(*dict));
	if (dict == NULL)
		return (NULL);
	i = -1;
	while (++i < words)
	{
		len = 0;
		while (*s == c)
			s++;
		while (s[len] != c && s[len] != '\0')
			len++;
		dict[i] = ft_calloc(len + 1, sizeof(**dict));
		if (dict[i] == NULL)
			return (ft_free_dict(dict, i));
		ft_strlcpy(dict[i], s, len + 1);
		s += len;
	}
	return (dict);
}
