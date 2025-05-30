/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_hex.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/25 13:58:00 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/30 23:03:58 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// File: tsts/test_ptr.c
#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"
#include "test_defs.h"

typedef struct s_testcase
{
	const char 		*label;
	const char 		*format;
	unsigned int	arg_uint; // voor hex and pointer
} t_testcase;

static int test_hex_format(const char *label, const char *fmt, unsigned int hex)
{
	int ret_sys, ret_ft;

	//printf("\n=== Test: %s ===\n", label);
	ret_sys = printf("System printf  : ");
	ret_sys += printf(fmt, hex);
	printf("\n");

	ret_ft = ft_printf("Your ft_printf : ");
	ret_ft += ft_printf(fmt, hex);
	ft_printf("\n");

	if (ret_sys != ret_ft)
	{
		printf("❌ FAIL: %s\n", label);
		printf("   Format: %s\n", fmt);
		printf("   Arg: '%u'\n", hex ? hex : 0);
		printf("   printf() = %d, ft_printf() = %d\n", ret_sys, ret_ft);
		return 0;
	}
	return 1;
}

t_result run_hex_format_tests(void)
{
	t_result result = {"Pointer Format", 0, 0};

	t_testcase tests[] = {
		{"Basic lowercase hex", "[%x]", 255},
		{"Basic uppercase hex", "[%X]", 255},
		{"Zero value", "[%x]", 0},
		{"Width 5", "[%5x]", 255},
		{"Zero-padding width 5", "[%05x]", 255},
		{"Precision 3", "[%.3x]", 255},
		{"Width 8, precision 5", "[%8.5x]", 255},
		{"Hash flag", "[%#x]", 255},
		{"Hash + width", "[%#8x]", 255},
		{"Hash + zero-padding", "[%#08x]", 255},
		{"Hash + left align", "[%-#8x]", 255},
		{"Hash + width + precision", "[%#8.5x]", 255},
		{"Hash + zero + precision", "[%#08.5x]", 255},
		{"0-padding + precision (should ignore 0)", "[%05.3x]", 42},
		{"0-padding + precision (should ignore 0)", "[%08.5X]", 0x7F},
		{"Plus flag ignored", "[%+x]", 123},
		{"Space flag ignored", "[% x]", 123},
		{"Width < value length", "[%2x]", 0x1234},
		{"Width smaller than precision", "[%4.8x]", 123},
		{"Precision zero + value zero (prints nothing)", "[%.0x]", 0},
		{"Precision zero + width (prints spaces)", "[%5.0x]", 0},
		{"Hash + precision zero + value zero", "[%#5.0x]", 0},
		{"Hash + value zero (no prefix)", "[%#x]", 0},
		{"Hash + zero padding with value zero", "[%#08x]", 0},
		{"Prefix + large value (no trunc)", "[%#4x]", 0xABCDEF },
		{NULL, NULL, 0}
};


	for (int i = 0; tests[i].label; i++)
	{
		result.total++;
		printf("HEX_TEST [%2d] - %s - %s \n", i, tests[i].format, tests[i].label);
		if (test_hex_format(tests[i].label, tests[i].format, tests[i].arg_uint))
			result.passed++;
	}
	return result;
} 

