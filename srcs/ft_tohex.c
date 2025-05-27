/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itohex.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/26 22:21:44 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/27 16:43:44 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "libft.h"

/**
 * @brief Convert unsigned int to char * representing the value as hexadecimal.
 * @param n unsigned long (size_t) number to convert.
 * @param uppercase boolean value that indicates alphachars in the result
 * 					to show in lowercase (0 = false), or uppercase (!0 = true).
 */
char *ft_utohex_raw(size_t n, int uppercase)
{
	char *str;
	const char *digits;
	int i;

	i = 2 * sizeof(size_t);
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	if (uppercase)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	str[i] = '\0';
	while (i > 0) 
	{
		str[--i] = digits[n&0xF];
		n >>= 4;
	}
	return (str);
}

/**
 * @brief Convert unsigned int to char * representing the value as hexadecimal.
 * 		  leading 0 (zeroes) removed.
 * @param n unsigned long (size_t) number to convert.
 * @param uppercase boolean value that indicates alphachars in the result
 * 					to show in lowercase (0 = false), or uppercase (!0 = true).
 */
char *ft_utohex_trim(size_t n, int uppercase)
{
	char	*raw;
	char	*cln;
	int		len;
	int 	i;
	
	raw = ft_itohex_raw(n, uppercase);
	i = 0;
	while (raw && raw[i] == '0')
		i++;
	len = ft_strlen(&raw[i]) + 1;
	cln = malloc(len);
	if (!cln)
	{
		free(raw);
		return (NULL);
	}
	ft_strlcpy(cln, &raw[i], len);
	return (cln);
}
