/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkikuchi <kkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 13:02:08 by kkikuchi          #+#    #+#             */
/*   Updated: 2020/07/16 22:26:04 by kkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char				**ft_clear(char ***ans)
{
	unsigned int	i;

	i = 0;
	while (*ans[i])
		free(*ans[i++]);
	free(*ans);
	return (NULL);
}

static size_t			calc_target_world(const char *s, char c)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (s[i])
	{
		if (!i && s[i] != c)
			len++;
		if (i && s[i] == c && s[i + 1] != c)
			len++;
		i++;
	}
	return (len);
}

static void				ft_scpy(char *str1, char *str2, char *until)
{
	while (str2 < until)
		*(str1++) = *(str2++);
	*str1 = 0;
}

char					**ft_split(const char *s, char c)
{
	char	**ans;
	int		i;
	char	*temp;

	i = 0;
	if (!s)
		return (NULL);
	if (!(ans = ft_calloc(calc_target_world(s, c) + 1, sizeof(char*))))
		return (NULL);
	while (*s)
	{
		if (!(c == *s))
		{
			temp = (char*)s;
			while (*s && !(c == *s))
				s++;
			if (!(ans[i] = ft_calloc(s - temp + 1, sizeof(char))))
				return (ft_clear(&ans));
			ft_scpy(ans[i++], temp, (char*)s--);
		}
		s++;
	}
	ans[i] = NULL;
	return (ans);
}
