/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:57:16 by smenard           #+#    #+#             */
/*   Updated: 2025/12/03 13:56:52 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
# include <limits.h>

int	main(void)
{
	int	lib_return;
	int	ft_return;

	void *null;
	void **ptr_to_null;

	null = NULL;
	ptr_to_null = &null;
	char *empty_str = malloc(1);
	empty_str[0] = '\0';
	printf("===== PTR TO NULL =====\n");
	lib_return = printf("lib |%p|\n", ptr_to_null);
	ft_return = ft_printf("ft  |%p|\n", ptr_to_null);
	printf("-----------------------\nLib return: %d, ft return: %d \n", lib_return, ft_return);
	printf("===== NULL PTR =====\n");
	lib_return = printf("lib |%p|\n", NULL);
	ft_return = ft_printf("ft  |%p|\n", NULL);
	printf("-----------------------\nLib return: %d, ft return: %d \n", lib_return, ft_return);
	printf("===== NULL STRING =====\n");
	lib_return = printf("lib |%s|\n",(char *) NULL);
	ft_return = ft_printf("ft  |%s|\n",(char *) NULL);
	printf("-----------------------\nLib return: %d, ft return: %d \n", lib_return, ft_return);
	printf("===== EMPTY STRING =====\n");
	lib_return = printf("lib |%s|\n", empty_str);
	ft_return = ft_printf("ft  |%s|\n",empty_str);
	printf("-----------------------\nLib return: %d, ft return: %d \n", lib_return, ft_return);
	printf("===== -42 INT =====\n");
	lib_return = printf("lib |%d|\n", -42);
	ft_return = ft_printf("ft  |%d|\n", -42);
	printf("-----------------------\nLib return: %d, ft return: %d \n", lib_return, ft_return);
	printf("===== -42 UINT =====\n");
	lib_return = printf("lib |%u|\n", -42);
	ft_return = ft_printf("ft  |%u|\n", -42);
	printf("-----------------------\nLib return: %d, ft return: %d \n", lib_return, ft_return);
	printf("===== STRING =====\n");
	lib_return = printf("lib |%s|\n", "Hello world !");
	ft_return = ft_printf("ft  |%s|\n", "Hello world !");
	printf("-----------------------\nLib return: %d, ft return: %d \n", lib_return, ft_return);
}
