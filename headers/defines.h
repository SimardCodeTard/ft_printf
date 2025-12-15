/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenard <smenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:51:05 by smenard           #+#    #+#             */
/*   Updated: 2025/12/15 12:18:27 by smenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include "includes.h"

# define DEC_CHARSET "0123456789"
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
	INVALID = '\0',
	CHAR = 'c',
	STRING = 's',
	INT = 'd',
	IINT = 'i',
	UINT = 'u',
	LHEX = 'x',
	UHEX = 'X',
	PTR = 'p',
	PERCENT = '%'
}	t_value_type;

typedef struct s_arg
{
	void			*value;
	t_value_type	type;
}	t_arg;

#endif
