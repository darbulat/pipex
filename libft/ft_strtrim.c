#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;

	str = ft_strdup(s1);
	while (str[0] != 0 && ft_strchr(set, str[0]) != 0)
	{
		ft_memmove(&str[0], &str[1], ft_strlen(str));
	}
	i = (int)ft_strlen(str) - 1;
	while (i >= 0 && ft_strchr(set, str[i]) != 0)
	{
		str[i] = 0;
		i--;
	}
	return (str);
}
