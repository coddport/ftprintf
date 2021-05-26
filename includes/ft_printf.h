/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mironbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 02:28:31 by mironbel          #+#    #+#             */
/*   Updated: 2020/08/13 04:35:41 by mironbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include <stdint.h>
# include <stddef.h>
# include "libft.h"

# define F_NUL	0b0000000000000000
# define F_MNS	0b0000000000001000
# define F_PLS	0b0000000000000100
# define F_ZER	0b0000000000000010
# define F_SPC	0b0000000000000001
# define F_HSH	0b0000000000100000
# define F_AP	0b0000000000010000

# define AST	0b0000000010000000
# define DOL	0b0000000001000000
# define DOT	0b0000001000000000
# define UP		0b0000000100000000

# define S_H	0b0000000000000001
# define S_HH	0b0000000000000010
# define S_T	0b0000000000000100
# define S_Z	0b0000000000001000
# define S_J	0b0000000000010000
# define S_L	0b0000000000100000
# define S_LL	0b0000000001000000
# define S_LLL	0b0000000010000000
# define S_I	0b0000000100000000
# define S_ZER	0b0000001000000000

# define ERR	(-1)

typedef	struct		s_directive
{
	char			*format;
	va_list			arg;
	short			flag;
	unsigned int	width;
	int				precis;
	short			size;
	unsigned int	con;
	int				fd;
	size_t			i;
	int				done;
	int				var;
	int				temp;
}					t_dir;

int					ft_printf(const char *format, ...);
void				parse_process(t_dir *x);
void				process_str(t_dir *x);
void				process_chr(t_dir *x);
void				process_pct(t_dir *x);
void				put_snb(t_dir *x);
void				put_unb(t_dir *x);
void				put_pnb(t_dir *x);
void				put_nbf(t_dir *x);
void				put_nbl(t_dir *x);
int					check_directive(const char *str, size_t *i);
int					set_prefix(int prefix, t_dir *x, int base);
int					is_dirs(const char d);
void				make_align(int prefix, t_dir *x, int base);
int					pf_atoi(char **nptr);
void				pf_print_base(uintmax_t num, int minus, int base, t_dir *x);

#endif
