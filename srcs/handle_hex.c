/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_hex.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/22 17:11:20 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/29 07:36:07 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfint.h"
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
static int	null_input_error(char *nbr, t_format *fmt)
{
	if (!nbr)
	{
		char 	*error;
		size_t 	error_len;

		error = "(nil)";
		error_len = 5;
		if (fmt->width > error_len)
			fmt->pad_size = fmt->width - error_len; 
		if (fmt->flag_minus)
		{
			fmt->prt_count += write(1, error, error_len);
			//fmt->prt_count += pad_residual_width(fmt);
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
 * @param 	nbr hexadecimal value to be writen.
 * @param	fmt pointer to struct storing state and formatting flags for the 
 * 				argument at hand.
 * @details
 * format processing order: alignment['+' / ' ']prefix['-' / '0']hex/NIL
 */
static void	write_hexadec_value(char *nbr, t_format *fmt)
{
	if (fmt->flag_minus)
	{
		fmt->prt_count += write(1, "0x", 2);
		if (fmt->flag_zero)
			fmt->prt_count += pad_residual_width(fmt);
		fmt->prt_count += write(1, nbr, fmt->chars_to_print);
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
		fmt->prt_count += write(1, nbr, fmt->chars_to_print);
	}
	return ;
}

static void	format_hex_precision_padding(t_format *fmt)
{
	size_t	hex_len;
	char	*hex_precision_str;
	size_t	hex_precision_len;
	size_t	i;

	hex_len = strlen(fmt->hex_string);
	hex_precision_len = fmt->precision_len - hex_len);
	if (fmt->precision && (fmt->precision_len > hex_len))
	{
		hex_precision_str = malloc(sizeof(char) * hex_precision_len + 1);
		if (!hex_precision_str)
			return (NULL);
		i =0;
		while (i < (fmt->precision_len - hex_len))
			hex_precision[i++] = '0';
		hex_precision[i] = '\0';
		ft_strlcpy(fmt->hex_precise_padding_str, hex_precision_str, hex_precision_len + 1);
		return ;
	}
}

/**
 * @brief	Convert *nbr to hex.
 * 			If required copy create a new streng with the length specified  by
 * 			fmt->precision_len. Copy hex to hex_precision right alligned 
 * 			pad the residual space left with '0'.
 * @param	nbr	pointer for which to get the hex address.
 * @param 	fmt	struct that tracks formatting settings and process state.
 * @return	hex	string containing the hex representation of *nbr address.
 * @return	hex_precision	string containing reformatted value of hex. 
 */
static void	format_hex_string(void *nbr, t_format *fmt)
{
	char	*hex;
	size_t	hex_len;
	
	hex = ft_utohex_trim((size_t)nbr, fmt->hex_upper);
	hex_len = ft_strlen(hex);
	ft_strlcpy(fmt->hex_string, hex, hex_len + 1);
	free(hex);
	return ;
}

static void format_hex_prefix(t_format *fmt)
{
if (fmt->flag_hash && fmt->conv_spec == 'X')
	{
		fmt->hex_upper = 1;
		fmt->hex_prefix = "0X";
	}
	else if (fmt->flag_hash)
		fmt->hex_prefix = "0x";
return;
}

static void	configure_hex_output_parameters(size_t nbr, t_format *fmt)
{
	char *hex;

	format_hex_prefix(fmt);
	format_hex_string(nbr, fmt);
	format_hex_precision_padding(fmt);
	// format_hex_signage;
	write_hexadec_value(hex, fmt);
}

/**
 * @brief Pointer conversion formatting handler.
 * @param fmt struct storing ft_printf() formatting data and processing state.
 * @param args va_list holding the actual pointer to translate to stdout.
 * @details
 * format processing order: alignment['+' / ' ']prefix['-' / '0']hex/NIL
 */
void	fn_handle_hexadec_conversion(va_list args, t_format *fmt)
{
	unsigned int	*nbr;
	char			*hex;
	int				prefix_len;
	int				signage_len;
	
	nbr = va_arg(args, void *);
	if (!null_input_error(nbr, fmt))
	{
		configure_hex_output_parameters(nbr, fmt);
		print_hex_output(fmt);
	}
	return ;
}
