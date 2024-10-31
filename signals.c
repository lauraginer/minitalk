/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:07:14 by lauragm           #+#    #+#             */
/*   Updated: 2024/10/31 13:28:29 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handle_signals(int sig)
{
	static char	current_char;
	static int	bit_count;

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