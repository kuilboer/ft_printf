/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/27 18:11:11 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/07 11:38:59 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
cast c as an unsigned char to handle negative input edge case
catch c == -1; EOF edge case.
*/
int	ft_toupper(int c)
{
	unsigned char	uc;

	uc = (unsigned char) c;
	if (c == -1)
		return (-1);
	if (uc >= 'a' && uc <= 'z')
		return (uc - 32);
	return (uc);
}
