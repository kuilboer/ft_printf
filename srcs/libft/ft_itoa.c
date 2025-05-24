/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/17 09:26:10 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/19 15:23:35 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// Returm the number of digits in an int.
static int	digit_count(int n)
{
	int	d_count;
	int	result;

	d_count = 0;
	if (n == 0)
		return (1);
	result = n;
	while (result)
	{
		result /= 10;
		d_count++;
	}
	return (d_count);
}

// Convert integer to character string and return a pointer to that string.
static char	*int_to_char(int n, char *s_nbr, size_t nbr_len)
{
	long long	l_nbr;
	char		sign;
	int			i;

	sign = 0;
	l_nbr = n;
	if (n < 0)
	{
		l_nbr *= -1;
		sign = '-';
	}
	i = nbr_len;
	s_nbr[i] = '\0';
	while (1)
	{
		s_nbr[--i] = l_nbr % 10 + '0';
		l_nbr /= 10;
		if (l_nbr == 0)
			break ;
	}
	if (sign)
		s_nbr[0] = sign;
	return (s_nbr);
}

/*
Allocates memory (using malloc(3)) and returns
a string representing the integer received as an
argument. Negative numbers must be handled
Return value:
	- The string representing the integer.
	- NULL if the allocation fails.
*/
char	*ft_itoa(int n)
{
	char	*digits;
	size_t	str_len;

	str_len = digit_count(n);
	if (n < 0)
		str_len += 1;
	digits = malloc(str_len + 1);
	if (!digits)
		return (NULL);
	digits = int_to_char(n, digits, str_len);
	if (n < 0)
		digits[0] = '-';
	return (digits);
}
