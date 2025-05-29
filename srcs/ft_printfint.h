/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printfint.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/20 22:33:10 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/29 20:19:32 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_FINT_H

# define FT_PRINT_FINT_H

# include <stdarg.h>
# include "libft.h"
# include "ft_printf.h"
# include <stdio.h>

/**	Type definitions */

/**
 * @brief Struct that holds formatting state for a single conversion in
 * ft_printf.
 * 
 * This struct is filled during format string parsing and used by handler functions
 * to apply formatting like field width, padding, and alignment.
 */
typedef struct s_format
{
	/** True if '-' flag is set: left-align the output within the given field width. */
	int		flag_minus;
	/** True if '0' pad numeric output with zeroes instead of spaces. */
	int		flag_zero;
	/** True if ' ' (space) flag is set: prepend a space before positive numbers. */
	int		flag_space;
	/** True if '#' flag is set: use alternate form (e.g., '0x' for hex, '0' for octal). */
	int		flag_hash;
	/** True if '+' flag is set: always show sign for numeric output. */
	int		flag_plus;
	/** Minimum field width for the formatted output. Zero means no width specified. */
	size_t	width;
	/** True if '.' flag is set: apply precision_len to output.
	 * 	if no numerical precision follows after the flag '.', ".0" is assumed*/
	char	precision;
	/** Only used if percision char is set to '.'
	 * Precision length specifies the minimum characters returned for numeric-
	 * al values. For string values it specifies the max. characters printed.*/
	size_t	precision_len;
	/** Conversion specifier character (e.g., 'd', 's', 'x', etc.). */
	char    conv_spec;
	size_t	prt_count;
	size_t  read_index;
	char    *num_prefix_str;
	char    *hex_string;
	char    *hex_precise_padding_str;
	int     hex_upper;
	char    num_sign;
	/// @brief calculated number of characters to print before width-padding.
	size_t	chars_to_print;
	char	width_padding_chr;
	/// @brief Calculated remaining field width to be padded.
	size_t	width_padding_len;
	/// @brief Preformatted padding string with proper char and len.
	char	*width_padding_str;
}	t_format;

/* 
* typedef that returns a ptr2func. 
* and takes a va_list and format table as input;
*/
typedef void	(*t_handler)(va_list args, t_format *fmt);

/*
* formatter function lookup table definition
*/
typedef struct s_convrs_handler
{
	char		specifier;
	t_handler	handler;
}	t_convrs_handler;

/**
 * Internal conversion helper functions for ft_printf().
 */
void	fn_handle_string_conversion(va_list args, t_format *fmt);
void	fn_handle_character_conversion(va_list args, t_format *fmt);
void	fn_handle_pointer_conversion(va_list args, t_format *fmt);
void	fn_handle_hexadec_conversion(va_list args, t_format *fmt);

void	format_hex_output_parameters(size_t nbr, t_format *fmt);
int		pad_residual_width(t_format *fmt);
char	*ft_utohex_raw(size_t n, int uppercase);
char	*ft_utohex_trim(size_t n, int uppercase);

/**
 * Iternal formatting parameter parsing helper functions for ft_printf().  
 */
int	parse_fmt_flags(char const *format, t_format *fmt);
int	parse_fmt_width(char const *format, t_format *fmt);
int	parse_fmt_prcis(char const *format, t_format *fmt);


#endif
