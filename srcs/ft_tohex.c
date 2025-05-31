/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tohex.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/26 22:21:44 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/31 10:25:29 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

/**
 * @brief Convert unsigned int to char * representing the value as hexadecimal.
 * @param n unsigned long (size_t) number to convert.
 * @param uppercase boolean value that indicates alphachars in the result
 * 					to show in lowercase (0 = false), or uppercase (!0 = true).
 * @return a pointer to the string containing the hex representaion of n, or 
 * @return a (NULL) pointer if memory allocation fails;
 * @details 
 * ft_utohex_raw takes size_t value 'n', converts it to a string representing
 * the value of 'n' in a hexadecimal format.
 * alphabetical digits can be presented in upper- or lower case depending on
 * the value that is passed through the 'uppercase' boolean parameter. 
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
 * @returns
 * @return a pointer to the string containing the hex representaion of n, or 
 * @return a (NULL) pointer if memory allocation fails.
 * @details for details on the process see ft_utohex_raw() which handles most 
 * of the actual conversion for this ft_utohex_trim().
 */
char *ft_utohex_trim(size_t n, int uppercase)
{
	char	*raw;
	char	*cln;
	int		len;
	int 	i;
	
	raw = ft_utohex_raw(n, uppercase);
	i = 0;
	while (raw && raw[i] == '0')
		i++;
	len = ft_strlen(&raw[i]);
	cln = malloc(len + 1);
	if (!cln)
	{
		free(raw);
		return (NULL);
	}
	ft_strlcpy(cln, &raw[i], len + 1);
	free(raw);
	return (cln);
}
