/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkikuchi <kkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 00:33:12 by kkikuchi          #+#    #+#             */
/*   Updated: 2020/07/15 10:09:49 by kkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_abs(int n)
{
	unsigned int nbr;

	if (n < 0)
		nbr = (unsigned int)-n;
	else
		nbr = n;
	return (nbr);
}

static size_t		calc_degit(unsigned int n)
{
	if (n >= 10)
		return (1 + calc_degit(n / 10));
	return (1);
}

char				*ft_itoa(int n)
{
	char			*ans;
	size_t			len;
	size_t			is_minus;
	size_t			nb;

	is_minus = (n < 0) ? 1 : 0;
	nb = ft_abs(n);
	len = calc_degit(nb) + is_minus;
	if (!(ans = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	ans[len] = '\0';
	while (len-- > is_minus)
	{
		ans[len] = nb % 10 + '0';
		nb /= 10;
	}
	if (is_minus)
		ans[len] = '-';
	return (ans);
}
