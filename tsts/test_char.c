/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_char.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/25 13:58:00 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/06/09 18:29:43 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// File: tsts/test_char.c
#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"
#include "test_defs.h"

typedef struct s_testcase
{
	const char 		*label;
	const char 		*format;
	const char 		*arg_str; // voor %s
	char			arg_chr;         // voor %c
} t_testcase;

static int test_char_format(const char *label, const char *fmt, char c)
{
	int ret_sys, ret_ft;

	//printf("\n=== Test: %s ===\n", label);
	ret_sys = printf("System printf  : ");
	ret_sys += printf(fmt, c);
	printf("\n");

	ret_ft = ft_printf("Your ft_printf : ");
	ret_ft += ft_printf(fmt, c);
	ft_printf("\n");

	if (ret_sys != ret_ft)
	{
		printf("❌ FAIL: %s\n", label);
		printf("   Format: %s\n", fmt);
		printf("   Arg: '%c'\n", c ? c : ' ');
		printf("   printf() = %d, ft_printf() = %d\n", ret_sys, ret_ft);
		return 0;
	}
	return 1;
}

t_result run_char_format_tests(void)
{
	t_result result = {"Char Format", 0, 0};

	t_testcase tests[] = {
		{"Erroneous format string input 3 x percent", "%%%", NULL, 0},
		{"Plain string", "This is a conversion-less string.", NULL, 0},
		{"Single percent", "This string will output a single %% sign.", NULL, 0},
		{"Simple char", "%c", NULL, 'A'},
		{"Right-aligned", "%5c", NULL, 'B'},
		{"Left-aligned", "%-5c", NULL, 'C'},
		{"Null char", "%c", NULL, '\0'},
		{"Width + NUL", "%5c", NULL, '\0'},
		{"Char in sentence", "[%c] is first", NULL, 'X'},
		{"Double chars", "%c %c", NULL, 'Y'},
		{NULL, NULL, NULL, 0}
	};

	// std_ret =	printf("2): %%%\n");
	// ft_ret = ft_printf("2): %%%\n");

	for (int i = 0; tests[i].label; i++)
	{
		result.total++;
		if (test_char_format(tests[i].label, tests[i].format, tests[i].arg_chr))
			result.passed++;
	}
	return result;
} 

