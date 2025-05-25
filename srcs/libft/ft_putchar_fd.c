/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/17 19:41:17 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/25 13:33:21 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*
Outputs the character ’c’ to the specified file descriptor. for fd it takes:
	1 = standard output (stdout)
	2 = standard error (stderr)
	0 = standard input (not typically written to)
Parameters:
	- c: The character to output.
	- fd: The file descriptor on which to write.
Return:
	-
*/
void	ft_putchar_fd(const char c, int fd)
{
	write(fd, &c, 1);
	return ;
}
