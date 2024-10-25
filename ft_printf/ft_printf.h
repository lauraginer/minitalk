/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:43:19 by lginer-m          #+#    #+#             */
/*   Updated: 2024/06/20 19:36:57 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_print_char(char c);
int		ft_print_string(char *str);
int		ft_puthex(unsigned long long nbr);
int		ft_puthex_m(unsigned long long nbr);
int		ft_putptr(void *ptr);
int		ft_putnbr(int n);
int		ft_putnbr_u(unsigned int n);

#endif