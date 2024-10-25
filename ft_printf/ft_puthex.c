/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:24:28 by lginer-m          #+#    #+#             */
/*   Updated: 2024/06/20 19:37:33 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long long nbr)
{
	int	count;

	count = 0;
	if (nbr <= 9)
	{
		ft_print_char(nbr + '0');
		count++;
	}
	else if (nbr >= 16)
	{
		count += ft_puthex(nbr / 16);
		count += ft_puthex(nbr % 16);
	}
	else
	{
		ft_print_char(nbr - 10 + 'a');
		count++;
	}
	return (count);
}

int	ft_puthex_m(unsigned long long nbr)
{
	int	count;

	count = 0;
	if (nbr <= 9)
	{
		ft_print_char(nbr + '0');
		count++;
	}
	else if (nbr >= 16)
	{
		count += ft_puthex_m(nbr / 16);
		count += ft_puthex_m(nbr % 16);
	}
	else
	{
		ft_print_char(nbr - 10 + 'A');
		count++;
	}
	return (count);
}