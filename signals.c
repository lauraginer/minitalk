/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:07:14 by lauragm           #+#    #+#             */
/*   Updated: 2024/11/04 20:12:29 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handle_signals(int sig)
{
	static char	current_char;
	static int	bit_count;

	if (sig == SIGUSR1)
    	ft_printf("Received SIGUSR1\n");
	else if (sig == SIGUSR2)
        ft_printf("Received SIGUSR2\n");
	current_char = 0;
	bit_count = 0;
	if (sig == SIGUSR1)
		current_char &= ~(1 << (7 - bit_count)); //se limpia el bit en current_char
	else if (sig == SIGUSR2)
		current_char |= (1 << (7 - bit_count)); //se establece el bit correspondiente	
	bit_count++;
	if(bit_count == 8)
	{
		write(1,&current_char, 1);
		current_char = 0;
		bit_count = 0;
	}	
}