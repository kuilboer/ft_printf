/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests_main.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/25 13:55:55 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/06/01 16:11:49 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// File: tsts/test_main.c
#include <stdio.h>
#include "test_defs.h"

t_result run_char_format_tests(void);
t_result run_str_format_tests(void); // placeholder voor string tests
t_result run_ptr_format_tests(void);
t_result run_hex_format_tests(void);

void run_all_tests(void)
{
	t_result results[10];
	int num_categories = 0;

	results[num_categories++] = run_char_format_tests();
	results[num_categories++] = run_str_format_tests(); // voeg andere testgroepen toe
	results[num_categories++] = run_ptr_format_tests();
	results[num_categories++] = run_hex_format_tests();

	int grand_total = 0;
	int grand_passed = 0;

	printf("\n=== Test Summary ===\n");
	for (int i = 0; i < num_categories; i++)
	{
		printf("Category: %-15s -> %2d/%2d passed\n",
			results[i].category,
			results[i].passed,
			results[i].total);
		grand_total += results[i].total;
		grand_passed += results[i].passed;
	}

	printf("--------------------------\n");
	if (grand_passed == grand_total)
		printf("✅ ALL TESTS PASSED\n");
	else
		printf("❌ Some tests failed: %d/%d passed\n", grand_passed, grand_total);
}

int main(void)
{
	run_all_tests();
	return 0;
} 
