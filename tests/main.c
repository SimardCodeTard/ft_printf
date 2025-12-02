/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:57:16 by smenard           #+#    #+#             */
/*   Updated: 2025/12/03 11:28:08 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int	main(void)
{
	int	lib_return;
	int	ft_return;

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
