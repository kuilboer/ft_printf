/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/05 17:11:48 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/07 13:31:28 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_isspace(char c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

static int	ft_issign(char c)
{
	if ((c == '+' || c == '-'))
		return (1);
	return (0);
}

// ft_getnumber abstracts the digits from the string.
// keeping an eye on their sizes to protect from under and overflow.
static int	ft_getnumber(const char *nptr, int sign)
{
	long long	nbr;
	int			digit;

	nbr = 0;
	while (*nptr && ft_isdigit(*nptr))
	{
		digit = *nptr - '0';
		if (sign == 1 && nbr > (INT_MAX - digit) / 10)
			return (0);
		if (sign == -1 && nbr > ((long long)INT_MAX + 1 - digit) / 10)
			return (0);
		nbr = nbr * 10 + digit;
		nptr++;
	}
	return (nbr * sign);
}

int	ft_atoi(const char *nptr)
{
	int	sign;

	sign = 1;
	while (ft_isspace(*nptr) && *nptr)
		nptr++;
	if (!(ft_issign(*nptr) || ft_isdigit(*nptr)) || !*nptr)
		return (0);
	else if (ft_issign(*nptr))
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	if (!ft_isdigit(*nptr))
		return (0);
	return (ft_getnumber(nptr, sign));
}
