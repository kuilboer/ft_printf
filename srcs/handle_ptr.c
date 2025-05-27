/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_ptr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/22 17:11:20 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/27 18:54:18 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfint.h"
#include <unistd.h>
#include "libft.h"

/**
 * @brief Private helper function for pointer conversion. It writes out a 
 * hex number representing a pointer address with '0x' prefixxed to it.
 * @param ptr hexadecimal value to be writen.
 */
static int	write_pointer_address(char *ptr, size_t len)
{
	int count;

	count = 0;
	count += write(1, "0x", 2);
	count += write(1, ptr, len);
	return (count);
}

/**
 * @brief Pointer conversion formatting handler.
 * @param fmt struct storing ft_printf() formatting data and processing state.
 * @param args va_list holding the actual pointer to translate to stdout.
 */
void	fn_handle_pointer_conversion(va_list args, t_format *fmt)
{
	void	*ptr;
	char	*hex;

	ptr = va_arg(args, void *);
	if (!ptr)
	{
		fmt->prt_count += write(1, "(nil)", 5);
		return ;
	}
	hex = ft_utohex_raw((size_t)ptr, 0);
	fmt->chars_to_print = ft_strlen(hex);
	if(fmt->width > fmt->chars_to_print + 2)
		fmt->pad_size = fmt->width - fmt->chars_to_print - 2;
	if (fmt->flag_minus)
	{
		fmt->prt_count += write_pointer_address(hex, fmt->chars_to_print);
		fmt->prt_count += pad_residual_width(fmt);
	}
	else
	{
		fmt->prt_count += pad_residual_width(fmt);
		fmt->prt_count += write_pointer_address(hex, fmt->chars_to_print);
	}
	free(hex);
	return ;
}
