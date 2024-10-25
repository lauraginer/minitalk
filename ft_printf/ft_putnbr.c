/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:06:05 by lginer-m          #+#    #+#             */
/*   Updated: 2024/06/20 18:46:54 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		count;
	long	ln;

	count = 0;
	ln = n;
	if (ln < 0)
	{
		count += ft_print_char('-');
		ln = -ln;
	}
	if (ln > 9)
	{
		count += ft_putnbr((int)(ln / 10));
		count += ft_print_char((char)(ln % 10 + 48));
	}
	else
		count += ft_print_char((char)(ln + 48));
	return (count);
}

int	ft_putnbr_u(unsigned int n)
{
	int		count;
	long	ln;

	count = 0;
	ln = n;
	if (ln > 9)
	{
		count += ft_putnbr_u((int)(ln / 10));
		count += ft_print_char((char)(ln % 10 + 48));
	}
	else
		count += ft_print_char((char)(ln + 48));
	return (count);
}
