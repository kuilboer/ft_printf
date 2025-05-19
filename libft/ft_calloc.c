/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/05 23:45:01 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/10 12:46:03 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The calloc() function allocates memory for an array of nmemb elements of size
bytes each and returns a pointer to the allocated memory.  The memory is set to 
zero.
If nmemb or size is 0, then calloc() returns a unique pointer value that can
later be successfully passed to free().

If  the  multiplication  of nmemb and size would result in integer overflow,
then calloc() returns an error.  By contrast, an integer overflow would not be
detected in the following call to malloc(), with the result that an incorrectly
sized block of memory would be allocated:

           malloc(nmemb * size);
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = malloc (nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
