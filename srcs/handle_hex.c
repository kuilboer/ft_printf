/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_hex.c                                       :+:    :+:            */
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
 * @brief	Checks for valid pointer input and prints "(nil)" if *nbr == NULL. 
 * 			The error message will be properly aligned in accordance with the
 * 			ft_printf formatting string that was set.
 * @param	nbr pointer to be checked.abort
 * @param	fmt pointer to struct storing state and formatting flags for the 
 * 				argument at hand.
 * @return	0 when FALSE proper pointer input was received;
 * @return	1 when TRUE NULL input was received;
 */
// static int	null_input_error(int nbr, t_format *fmt)
// {
// 	if (!nbr)
// 	{
// 		char 	*error;
// 		size_t 	error_len;

// 		error = "(nil)";
// 		error_len = 5;
// 		if (fmt->width > error_len)
// 			fmt->width_padding_len = fmt->width - error_len; 
// 		if (fmt->flag_minus)
// 		{
// 			fmt->prt_count += write(1, error, error_len);
// 			//fmt->prt_count += pad_residual_width(fmt);
// 		}
// 		else
// 		{
// 			fmt->prt_count += pad_residual_width(fmt);
// 			fmt->prt_count += write(1, "(nil)", 5);
// 		}
// 		return (1);
// 	}
// 	return (0);
// }

static void	write_hexadec_value_left_aligned(t_format *fmt)
{
	if (fmt->flag_hash && fmt->hex_input_nbr != 0)
		fmt->prt_count += write(1, fmt->num_prefix_str, 2);
	if (fmt->hex_precise_padding_str)
		fmt->prt_count += write(1, fmt->hex_precise_padding_str, \
			fmt->hex_precise_padding_len);
	fmt->prt_count += write(1, fmt->hex_string, fmt->hex_string_len);
	fmt->prt_count += write(1, fmt->width_padding_str, \
		fmt->width_padding_len);
	return ;
}

/**
 * @brief 	Private helper function for pointer conversion. It writes out a 
 * 			hex number representing a pointer address with '0x' prefixed to it.
 * 			the output if properly formatted following the flags found in the 
 * 			ft_printf() formatting string.
 * @param 	nbr hexadecimal value to be writen.
 * @param	fmt pointer to struct storing state and formatting flags for the 
 * 				argument at hand.
 * @details
 * format processing order: alignment['+' / ' ']prefix['-' / '0']hex/NIL
 */
static void	write_hexadec_value_right_aligned(t_format *fmt)
{
	if (fmt->width_padding_len && fmt->width_padding_chr == '0')
	{
		if (fmt->flag_hash && fmt->hex_input_nbr != 0)
			fmt->prt_count += write(1, fmt->num_prefix_str, \
				ft_strlen(fmt->num_prefix_str));
		if (fmt->width_padding_len)
			fmt->prt_count += write(1, fmt->width_padding_str, \
				fmt->width_padding_len);
	}
	else
	{
		fmt->prt_count += write(1, fmt->width_padding_str, \
			fmt->width_padding_len);
		if (fmt->flag_hash && fmt->hex_input_nbr != 0)
			fmt->prt_count += write(1, fmt->num_prefix_str, 2);
		if (fmt->hex_precise_padding_str && fmt->hex_precise_padding_len)
			fmt->prt_count += write(1, fmt->hex_precise_padding_str, \
				fmt->hex_precise_padding_len);
	}
	if (!(fmt->precision && fmt->hex_input_nbr == 0))
		fmt->prt_count += write(1, fmt->hex_string, ft_strlen(fmt->hex_string));
	return ;
}

/**
 * @brief Hexadecimal conversion formatting handler.
 * @param fmt struct storing ft_printf() formatting data and processing state.
 * @param args va_list holding the actual pointer to translate to stdout.
 * @details
 * format processing order: alignment['+' / ' ']prefix['-' / '0']hex/NIL
 */
void	fn_handle_hexadec_conversion(va_list args, t_format *fmt)
{
	int	nbr;

	nbr = va_arg(args, int);
	format_hex_output_parameters(nbr, fmt);
	if (fmt->flag_minus)
		write_hexadec_value_left_aligned(fmt);
	else
		write_hexadec_value_right_aligned(fmt);
	return ;
}
