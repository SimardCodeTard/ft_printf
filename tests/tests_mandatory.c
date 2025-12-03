/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_mandatory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:50:33 by smenard           #+#    #+#             */
/*   Updated: 2025/12/03 17:14:48 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	tests_mandatory(void)
{
	int		lib_return;
	int		ft_return;
	void	*null;
	void	**ptr_to_null;
	char	*empty_str;

	empty_str = malloc(1);
	null = NULL;
	ptr_to_null = &null;
	empty_str[0] = '\0';

	printf("========== NULL & EMPTY ==========\n");

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

	printf("========== INT ==========\n");

	printf("===== 42 INT =====\n");
	lib_return = printf("lib |%d|\n", 42);
	ft_return = ft_printf("ft  |%d|\n", 42);
	printf("-----------------------\nLib return: %d, ft return: %d \n", lib_return, ft_return);

	printf("===== -42 INT =====\n");
	lib_return = printf("lib |%d|\n", -42);
	ft_return = ft_printf("ft  |%d|\n", -42);
	printf("-----------------------\nLib return: %d, ft return: %d \n", lib_return, ft_return);

	printf("===== INTMAX INT =====\n");
	lib_return = printf("lib |%d|\n", INT_MAX);
	ft_return = ft_printf("ft  |%d|\n", INT_MAX);
	printf("-----------------------\nLib return: %d, ft return: %d \n", lib_return, ft_return);

	printf("===== INTMIN INT =====\n");
	lib_return = printf("lib |%d|\n", INT_MIN);
	ft_return = ft_printf("ft  |%d|\n", INT_MIN);
	printf("-----------------------\nLib return: %d, ft return: %d \n", lib_return, ft_return);

	printf("========== UINT ==========\n");

	printf("===== 42 UINT =====\n");
	lib_return = printf("lib |%u|\n", 42);
	ft_return = ft_printf("ft  |%u|\n", 42);
	printf("-----------------------\nLib return: %d, ft return: %d \n", lib_return, ft_return);

	printf("===== -42 UINT =====\n");
	lib_return = printf("lib |%u|\n", -42);
	ft_return = ft_printf("ft  |%u|\n", -42);
	printf("-----------------------\nLib return: %d, ft return: %d \n", lib_return, ft_return);

	printf("===== INTMAX UINT =====\n");
	lib_return = printf("lib |%u|\n", INT_MAX);
	ft_return = ft_printf("ft  |%u|\n", INT_MAX);
	printf("-----------------------\nLib return: %d, ft return: %d \n", lib_return, ft_return);

	printf("===== INTMIN UINT =====\n");
	lib_return = printf("lib |%u|\n", INT_MIN);
	ft_return = ft_printf("ft  |%u|\n", INT_MIN);
	printf("-----------------------\nLib return: %d, ft return: %d \n", lib_return, ft_return);

	printf("========== STRING ==========\n");

	printf("===== STRING =====\n");
	lib_return = printf("lib |%s|\n", "Hello world !");
	ft_return = ft_printf("ft  |%s|\n", "Hello world !");
	printf("-----------------------\nLib return: %d, ft return: %d \n", lib_return, ft_return);

	printf("===== STRING EMOJIS =====\n");
	lib_return = printf("lib |%s|\n", "😁🌸👁️");
	ft_return = ft_printf("ft  |%s|\n", "😁🌸👁️");
	printf("-----------------------\nLib return: %d, ft return: %d \n", lib_return, ft_return);

	printf("========== CHAR ==========\n");

	printf("===== Q =====\n");
	lib_return = printf("lib |%c|\n", 'Q');
	ft_return = ft_printf("ft  |%c|\n", 'Q');
	printf("-----------------------\nLib return: %d, ft return: %d \n", lib_return, ft_return);

	printf("===== NULL BYTE =====\n");
	lib_return = printf("lib |%c|\n", '\0');
	ft_return = ft_printf("ft  |%c|\n", '\0');
	printf("-----------------------\nLib return: %d, ft return: %d \n", lib_return, ft_return);

	printf("===== EXTENDED-ASCII CHAR =====\n");
	lib_return = printf("lib |%c|\n", 202);
	ft_return = ft_printf("ft  |%c|\n", 202);
	printf("-----------------------\nLib return: %d, ft return: %d \n", lib_return, ft_return);


	printf("===== NON-ASCII CHAR =====\n");
	lib_return = printf("lib |%c|\n", 1058);
	ft_return = ft_printf("ft  |%c|\n", 1058);
	printf("-----------------------\nLib return: %d, ft return: %d \n", lib_return, ft_return);

	printf("========== LHEX ==========\n");

	printf("===== 42 LHEX =====\n");
	lib_return = printf("lib |%x|\n", 42);
	ft_return = ft_printf("ft  |%x|\n", 42);
	printf("-----------------------\nLib return: %d, ft return: %d \n", lib_return, ft_return);

	printf("===== -42 LHEX =====\n");
	lib_return = printf("lib |%x|\n", -42);
	ft_return = ft_printf("ft  |%x|\n", -42);
	printf("-----------------------\nLib return: %d, ft return: %d \n", lib_return, ft_return);

	printf("===== INTMAX LHEX =====\n");
	lib_return = printf("lib |%x|\n", INT_MAX);
	ft_return = ft_printf("ft  |%x|\n", INT_MAX);
	printf("-----------------------\nLib return: %d, ft return: %d \n", lib_return, ft_return);

	printf("===== INTMIN LHEX =====\n");
	lib_return = printf("lib |%x|\n", INT_MIN);
	ft_return = ft_printf("ft  |%x|\n", INT_MIN);
	printf("-----------------------\nLib return: %d, ft return: %d \n", lib_return, ft_return);

	printf("========== UHEX ==========\n");

	printf("===== 42 UHEX =====\n");
	lib_return = printf("lib |%X|\n", 42);
	ft_return = ft_printf("ft  |%X|\n", 42);
	printf("-----------------------\nLib return: %d, ft return: %d \n", lib_return, ft_return);

	printf("===== -42 UHEX =====\n");
	lib_return = printf("lib |%X|\n", -42);
	ft_return = ft_printf("ft  |%X|\n", -42);
	printf("-----------------------\nLib return: %d, ft return: %d \n", lib_return, ft_return);

	printf("===== INTMAX UHEX =====\n");
	lib_return = printf("lib |%X|\n", INT_MAX);
	ft_return = ft_printf("ft  |%X|\n", INT_MAX);
	printf("-----------------------\nLib return: %d, ft return: %d \n", lib_return, ft_return);

	printf("===== INTMIN UHEX =====\n");
	lib_return = printf("lib |%X|\n", INT_MIN);
	ft_return = ft_printf("ft  |%X|\n", INT_MIN);
	printf("-----------------------\nLib return: %d, ft return: %d \n", lib_return, ft_return);
	free(empty_str);
}
