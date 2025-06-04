/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/03 12:58:40 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/06/04 19:41:38 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief required number of digits to store n;
 * @param n unsigned int to analyse.
 * @details ALways returns at least 1, to cover the n = 0 case.
 */
static int	digit_count(unsigned int n)
{
	size_t	i;

	i = 1;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

/**
 * @brief convert unsigned int to string.asm
 * @param n unsigned int to convert
 * @returns string version of n.
 */
char	*ft_utoa(unsigned int n)
{
	char	*digits;
	size_t	len;

	len = digit_count(n);
	digits = malloc(len + 1);
	if (!digits)
		return (NULL);
	digits[len] = '\0';
	while (len > 0)
	{
		digits[--len] = '0' + (n % 10);
		n /= 10;
	}
	return (digits);
}
