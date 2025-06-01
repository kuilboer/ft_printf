/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_ptr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/22 17:11:20 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/06/01 16:41:57 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"
#include <unistd.h>
#include "libft.h"

/**
 * @brief	Checks for valid pointer input and prints "(nil)" if *ptr == NULL. 
 * 			The error message will be properly aligned in accordance with the
 * 			ft_printf formatting string that was set.
 * @param	ptr pointer to be checked.abort
 * @param	fmt pointer to struct storing state and formatting flags for the 
 * 				argument at hand.
 * @return	0 when FALSE proper pointer input was received;
 * @return	1 when TRUE NULL input was received;
 */
static int	null_input_error(char *ptr, t_format *fmt)
{
	char	*error;
	size_t	error_len;

	if (!ptr)
	{
		error = "(nil)";
		error_len = 5;
		if (fmt->width > error_len)
			fmt->width_padding_len = fmt->width - error_len;
		if (fmt->flag_minus)
		{
			fmt->prt_count += write(1, error, error_len);
		}
		else
		{
			fmt->prt_count += pad_residual_width(fmt);
			fmt->prt_count += write(1, "(nil)", 5);
		}
		return (1);
	}
	return (0);
}

/**
 * @brief 	Private helper function for pointer conversion. It writes out a 
 * 			hex number representing a pointer address with '0x' prefixed to it.
 * 			the output if properly formatted following the flags found in the 
 * 			ft_printf() formatting string.
 * @param 	ptr hexadecimal value to be writen.
 * @param	fmt pointer to struct storing state and formatting flags for the 
 * 				argument at hand.
 * @details
 * format processing order: alignment['+' / ' ']prefix['-' / '0']hex/NIL
 */
static void	write_pointer_address(char *ptr, t_format *fmt)
{
	if (fmt->flag_minus)
	{
		fmt->prt_count += write(1, "0x", 2);
		if (fmt->flag_zero)
			fmt->prt_count += pad_residual_width(fmt);
		fmt->prt_count += write(1, ptr, fmt->chars_to_print);
		if (!fmt->flag_minus)
			fmt->prt_count += pad_residual_width(fmt);
	}
	else
	{
		if (fmt->flag_zero)
		{
			fmt->prt_count += write(1, "0x", 2);
			fmt->prt_count += pad_residual_width(fmt);
		}
		else
		{
			fmt->prt_count += pad_residual_width(fmt);
			fmt->prt_count += write(1, "0x", 2);
		}
		fmt->prt_count += write(1, ptr, fmt->chars_to_print);
	}
	return ;
}

/**
 * @brief	Convert *ptr to hex.
 * 			If required copy create a new streng with the length specified  by
 * 			fmt->precision_len. Copy hex to hex_precision right alligned 
 * 			pad the residual space left with '0'.
 * @param	ptr	pointer for which to get the hex address.
 * @param 	fmt	struct that tracks formatting settings and process state.
 * @return	hex	string containing the hex representation of *ptr address.
 * @return	hex_precision	string containing reformatted value of hex. 
 */
static char	*format_hexadecimal(void *ptr, t_format *fmt)
{
	char	*hex;
	size_t	hex_len;
	char	*hex_precision;
	size_t	i;

	hex = ft_utohex_trim((size_t)ptr, 0);
	hex_len = ft_strlen(hex);
	if (fmt->precision && (fmt->precision_len > hex_len))
	{
		hex_precision = malloc(sizeof(char) * fmt->precision_len + 1);
		if (!hex_precision)
		{
			free(hex);
			return (NULL);
		}
		i = 0;
		while (fmt->precision_len - i > hex_len)
			hex_precision[i++] = '0';
		ft_strlcpy(&hex_precision[i], hex, hex_len +1);
		free(hex);
		return (hex_precision);
	}
	return (hex);
}

/**
 * @brief Pointer conversion formatting handler.
 * @param fmt struct storing ft_printf() formatting data and processing state.
 * @param args va_list holding the actual pointer to translate to stdout.
 * @details
 * format processing order: alignment['+' / ' ']prefix['-' / '0']hex/NIL
 */
void	fn_handle_pointer_conversion(va_list args, t_format *fmt)
{
	void	*ptr;
	char	*hex;
	int		prefix_len;
	int		signage_len;

	signage_len = 0;
	prefix_len = 2;
	ptr = va_arg(args, void *);
	if (!null_input_error(ptr, fmt))
	{
		hex = format_hexadecimal(ptr, fmt);
		fmt->chars_to_print = ft_strlen(hex);
		if (fmt->width > fmt->chars_to_print + prefix_len + signage_len)
			fmt->width_padding_len = fmt->width - fmt->chars_to_print - 2;
		write_pointer_address(hex, fmt);
	}
	else
		return ;
	free(hex);
	return ;
}
