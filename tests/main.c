/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:57:16 by smenard           #+#    #+#             */
/*   Updated: 2025/12/03 12:44:36 by smenard          ###   ########.fr       */
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
	lib_return = printf("lib |%p|\n", ptr_to_null);
	ft_return = ft_printf("ft |%p|\n", ptr_to_null);
	printf("Lib return: %d, ft return: %d \n", lib_return, ft_return);
	lib_return = printf("lib |%p|\n", NULL);
	ft_return = ft_printf("ft |%p|\n", NULL);
	printf("Lib return: %d, ft return: %d \n", lib_return, ft_return);
	lib_return = printf("lib |%s|\n",(char *) NULL);
	ft_return = ft_printf("ft |%s|\n",(char *) NULL);
	printf("Lib return: %d, ft return: %d \n", lib_return, ft_return);
	lib_return = printf("lib |%s|\n", empty_str);
	ft_return = ft_printf("ft |%s|\n",empty_str);
	printf("Lib return: %d, ft return: %d \n", lib_return, ft_return);
	lib_return = printf("lib |%d|\n", -42);
	ft_return = ft_printf("ft |%d|\n", -42);
	printf("Lib return: %d, ft return: %d \n", lib_return, ft_return);
	lib_return = printf("|%u|\n", -42);
	ft_return = ft_printf("|%u|\n", -42);
	printf("Lib return: %d, ft return: %d \n", lib_return, ft_return);
	lib_return = printf("|%s|\n", "Hello world !");
	ft_return = ft_printf("|%s|\n", "Hello world !");
	printf("Lib return: %d, ft return: %d \n", lib_return, ft_return);
}
