/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_defs.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: okuilboe <okuilboe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/25 13:57:12 by okuilboe      #+#    #+#                 */
/*   Updated: 2025/05/25 13:57:40 by okuilboe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


// File: tsts/test_defs.h
#ifndef TEST_DEFS_H
#define TEST_DEFS_H

typedef struct s_testcase
{
	const char *label;
	const char *format;
	const char *arg_str; // voor %s
	char arg_chr;         // voor %c
} t_testcase;

typedef struct s_result
{
	const char *category;
	int total;
	int passed;
} t_result;

#endif

