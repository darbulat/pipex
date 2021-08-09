#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*str;

	i = -1;
	str = malloc((len + 1) * sizeof(*str));
	if (0 == str)
		return (0);
	while (s[start + ++i] && i < (int)len)
		str[i] = s[start + i];
	str[i + 1] = 0;
	return (str);
}
