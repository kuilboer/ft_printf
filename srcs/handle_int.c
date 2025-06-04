/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_int.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/02 17:29:47 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/06/04 20:15:51 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"
#include <unistd.h>
#include "libft.h"

static void	write_integer_value_left_aligned(t_format *fmt)
{
	if (fmt->num_sign && fmt->conv_spec != 'u' && fmt->input_nbr != INT_MIN)
		fmt->prt_count += write(1, &fmt->num_sign, 1);
	if (fmt->num_precise_padding_str)
		fmt->prt_count += write(1, fmt->num_precise_padding_str, \
			fmt->num_precise_padding_len);
	fmt->prt_count += write(1, fmt->num_string, fmt->num_string_len);
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
static void	write_integer_value_right_aligned(t_format *fmt)
{
	if (fmt->width_padding_len && fmt->width_padding_chr == '0')
	{
		if (fmt->num_sign && fmt->conv_spec != 'u' && fmt->input_nbr != INT_MIN)
			fmt->prt_count += write(1, &fmt->num_sign, 1);
		if (fmt->width_padding_len)
			fmt->prt_count += write(1, fmt->width_padding_str, \
				fmt->width_padding_len);
	}
	else
	{
		fmt->prt_count += write(1, fmt->width_padding_str, \
			fmt->width_padding_len);
		if (fmt->num_sign && fmt->conv_spec != 'u' && fmt->input_nbr != INT_MIN)
			fmt->prt_count += write(1, &fmt->num_sign, 1);
		if (fmt->num_precise_padding_str && fmt->num_precise_padding_len)
			fmt->prt_count += write(1, fmt->num_precise_padding_str, \
				fmt->num_precise_padding_len);
	}
	if (!(fmt->precision && fmt->input_nbr == 0))
		fmt->prt_count += write(1, fmt->num_string, ft_strlen(fmt->num_string));
}

/**
 * @brief Unsigned int conversion formatting handler.
 * @param fmt struct to store ft_printf() formatting data and processing state.
 * @param args va_list holding the actual unsigned int to translate to stdout.
 * @details
 */
void	fn_handle_int_conversion(va_list args, t_format *fmt)
{
	long	nbr;

	nbr = va_arg(args, int);
	fmt->input_nbr = nbr;
	if (!(nbr == 0 && fmt->precision))
	{
		if (nbr < 0)
			nbr *= -1;
		fmt->num_string = ft_itoa((int)nbr);
		fmt->num_string_len = ft_strlen(fmt->num_string);
	}
	else
		fmt->num_string_len = 0;
	format_int_output_parameters(fmt);
	if (fmt->flag_minus)
		write_integer_value_left_aligned(fmt);
	else
		write_integer_value_right_aligned(fmt);
	return ;
}

/**
 * @brief Unsigned int conversion formatting handler.
 * @param fmt struct to store ft_printf() formatting data and processing state.
 * @param args va_list holding the actual unsigned int to translate to stdout.
 * @details
 */
void	fn_handle_uint_conversion(va_list args, t_format *fmt)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	fmt->input_nbr = nbr;
	if (!(nbr == 0 && fmt->precision))
	{
		fmt->num_string = ft_utoa((unsigned int)nbr);
		fmt->num_string_len = ft_strlen(fmt->num_string);
	}
	else
		fmt->num_string_len = 0;
	format_int_output_parameters(fmt);
	if (fmt->flag_minus)
		write_integer_value_left_aligned(fmt);
	else
		write_integer_value_right_aligned(fmt);
	return ;
}
