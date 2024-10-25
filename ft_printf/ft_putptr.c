/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:31:09 by lginer-m          #+#    #+#             */
/*   Updated: 2024/06/25 21:49:39 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long long	address;

	address = (unsigned long)ptr;
	if (!address)
		return (ft_print_string("(nil)"));
	else
	{
		ft_print_string("0x");
		return (ft_puthex(address) + 2);
	}
}
