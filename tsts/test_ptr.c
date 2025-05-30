/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ptr.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/25 13:58:00 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/30 17:32:51 by okuilboe      ########   odam.nl         */
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
	const char 		*arg_str; // voor %s

} t_testcase;

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
		{"Basic pointer", "%p", "hello"},
		{"Right-aligned (width 20)", "%20p", "aligned"},
		{"Left-aligned (width 20)", "%-20p", "left"},
		{"Precision ignored", "%.5p", "precise"},
		{"Zero-padding ignored", "%020p", "zpad"},
		{"Pointer with space + width", "% 20p", "test"},
		{"Pointer with left align", "%-20p", "test"},
		{"Pointer with space + left align", "% -20p", "test"},
		{"NULL pointer with space", "% 20p", NULL},
		{"NULL pointer", "%p", NULL},
		{"With plus flag", "%+p", "hello"},
		{"Plus with width", "%+20p", "world"},
		{"Plus with left-align", "%+-20p", "test"},
		{"Plus with zero-pad", "%+020p", "pluszero"},
		{"Zero-pad, width, left-align", "%0-20p", "ptr"},
		{"Plus with precision", "%+.2p", "precise"},
		{"Precision padded pointer", "%.16p", "ptr"},
		{"Precision + width", "%30.0p", "ptr"},
		{"Left-alighned + Precision + width", "%-30.16p", "ptr"},
		{"Plus and space", "%+ p", "combo"},
		{"NULL with plus", "%+p", NULL},

		{NULL, NULL, NULL}
};


	for (int i = 0; tests[i].label; i++)
	{
		result.total++;
		if (test_ptr_format(tests[i].label, tests[i].format, (void *)tests[i].arg_str))
			result.passed++;
	}
	return result;
} 

