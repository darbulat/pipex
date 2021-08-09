#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*(little) == 0)
		return ((char *)big);
	while (big[i] && (i < len))
	{
		j = 0;
		while ((i + j) < len)
		{
			if (little[j] == 0)
				return ((char *)big + i);
			if (big[i + j] == 0)
				return (0);
			if (big[i + j] == little[j])
				j++;
			else
				break ;
		}
		i++;
	}
	return (0);
}
