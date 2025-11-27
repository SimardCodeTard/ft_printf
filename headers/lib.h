/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:51:49 by smenard           #+#    #+#             */
/*   Updated: 2025/11/27 15:03:56 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H
# include "defines.h"

t_arg	ft_parse_arg(t_string str, void *ap);

void	ft_normalize_arg(t_arg *arg);

void	ft_putnbr_base(uint64_t num, t_string base);

void	ft_print_arg(void *arg, t_value_type type);

void	ft_print_substr(t_string str);

#endif
