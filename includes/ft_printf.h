/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcornet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:48:11 by gcornet-          #+#    #+#             */
/*   Updated: 2021/04/22 12:48:13 by gcornet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_flags	t_flags;
struct			s_flags
{
	va_list		ap;
	char		padding;
	char		type;
	char		null[7];
	char		base[17];
	int			ret;
	int			width;
	int			precision;
};

int				ft_printf(const char *str, ...);
void			ft_parse_padding(const char *str, t_flags *flags);
void			ft_parse_precision(const char *str, t_flags *flags);
int				check_type(t_flags *flags);
int				ft_putchar(char c);
int				ft_get_displayed_precision(t_flags *flags,
					long int nbr, int len);
int				ft_size_10(t_flags *flags, int nb);
int				ft_putstr(char *str);
void			ft_print_hexa(t_flags *flags, unsigned int nbr);
void			ft_size_16(unsigned long int n, int *hexa_len);
void			ft_print_hexa_ull(t_flags *flags, unsigned long long nbr);
void			ft_size_16_ull(unsigned long long n, int *hexa_len);
int				ft_u_size_10(t_flags *flags, long int nbr);

void			ft_print_d_i(t_flags *flags);
void			ft_print_c(t_flags *flags);
void			ft_print_u(t_flags *flags);
void			ft_print_s(t_flags *flags);
void			ft_print_x(t_flags *param);
void			ft_print_p(t_flags *flags);
void			ft_print_pct(t_flags *param);
void			reinit_flags(t_flags *flags);

#endif
