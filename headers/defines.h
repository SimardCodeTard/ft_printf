/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:51:05 by smenard           #+#    #+#             */
/*   Updated: 2025/11/27 15:05:42 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# include "ft_printf.h"

# define DECIMAL_CHARSET "0123456789"
# define LHEX_CHARSET "0123456789abcdef"
# define UHEX_CHARSET "0123456789ABCDEF"

# define FLAGS "-0.# +"
# define CONVERSIONS "cspdiuxX%"

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef char *	t_string;

typedef enum e_padding_side
{
	LEFT,
	RIGHT
}	t_padding_side;

typedef enum e_value_type
{
	CHAR,
	STRING,
	INT,
	UINT,
	LHEX,
	UHEX,
	PTR,
}	t_value_type;

typedef struct s_arg
{
	void			*value;
	t_value_type	value_type;
	t_string		prefix;
	uint32_t		padding_len;
	uint32_t		precision_len;
	uint32_t		full_len;
}	t_arg;


#endif DEFINES_H
