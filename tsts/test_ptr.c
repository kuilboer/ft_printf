/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ptr.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/25 13:58:00 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/28 19:21:11 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// File: tsts/test_ptr.c
#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"
#include "test_defs.h"

static int test_ptr_format(const char *label, const char *fmt, void *p)
{
	int ret_sys, ret_ft;

	//printf("\n=== Test: %s ===\n", label);
	ret_sys = printf("System printf  : ");
	ret_sys += printf(fmt, p);
	printf("\n");

	ret_ft = ft_printf("Your ft_printf : ");
	ret_ft += ft_printf(fmt, p);
	ft_printf("\n");

	if (ret_sys != ret_ft)
	{
		printf("❌ FAIL: %s\n", label);
		printf("   Format: %s\n", fmt);
		printf("   Arg: '%p'\n", p ? p : "(nil)");
		printf("   printf() = %d, ft_printf() = %d\n", ret_sys, ret_ft);
		return 0;
	}
	return 1;
}

t_result run_ptr_format_tests(void)
{
	t_result result = {"Pointer Format", 0, 0};

	t_testcase tests[] = {
		{"Basic pointer", "%p", "hello", 0},
		{"Right-aligned (width 20)", "%20p", "aligned", 0},
		{"Left-aligned (width 20)", "%-20p", "left", 0},
		{"Precision ignored", "%.5p", "precise", 0},
		{"Zero-padding ignored", "%020p", "zpad", 0},
		{"Pointer with space + width", "% 20p", "test", 0},
		{"Pointer with left align", "%-20p", "test", 0},
		{"Pointer with space + left align", "% -20p", "test", 0},
		{"NULL pointer with space", "% 20p", NULL, 0},
		{"NULL pointer", "%p", NULL, 0},
		{"With plus flag", "%+p", "hello", 0},
		{"Plus with width", "%+20p", "world", 0},
		{"Plus with left-align", "%+-20p", "test", 0},
		{"Plus with zero-pad", "%+020p", "pluszero", 0},
		{"Zero-pad, width, left-align", "%0-20p", "ptr", 0},
		{"Plus with precision", "%+.2p", "precise", 0},
		{"Precision padded pointer", "%.16p", "ptr", 0},
		{"Precision + width", "%30.0p", "ptr", 0},
		{"Left-alighned + Precision + width", "%-30.16p", "ptr", 0},
		{"Plus and space", "%+ p", "combo", 0},
		{"NULL with plus", "%+p", NULL, 0},

		{NULL, NULL, NULL, 0}
};


	for (int i = 0; tests[i].label; i++)
	{
		result.total++;
		if (test_ptr_format(tests[i].label, tests[i].format, (void *)tests[i].arg_str))
			result.passed++;
	}
	return result;
} 

