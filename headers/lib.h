/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:51:49 by smenard           #+#    #+#             */
/*   Updated: 2025/12/03 13:52:27 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H
# include "defines.h"

/* parse.c */
t_arg		ft_parse_arg(t_string str, va_list ap, size_t *ptr_i);

/* normalize.c */
void		ft_normalize_arg(t_arg *arg);

/* print.c */
ssize_t		ft_putstr(t_string str);

ssize_t		ft_putnbr_base_signed(int64_t num, t_string base);

ssize_t		ft_putnbr_base(uint64_t num, t_string base);

ssize_t		ft_print_arg(t_arg arg);

/* utils.c */
size_t		ft_strlen(t_string str);

size_t		ft_strlen_until(t_string str, char stop);

uint64_t	ft_abs(int64_t num);

char		*ft_strchr(t_string str, char c);

t_string	ft_strdup(t_string str);

#endif
