#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*str;

	len1 = 0;
	while (s1[len1])
		len1++;
	len2 = 0;
	while (s2[len2])
		len2++;
	str = malloc(sizeof(char) * (len1 + len2 + 1));
	if (str == 0)
		return (0);
	i = -1;
	while (++i < len1)
		str[i] = s1[i];
	i--;
	while (++i < len1 + len2)
		str[i] = s2[i - len1];
	str[i + 1] = 0;
	return (str);
}
