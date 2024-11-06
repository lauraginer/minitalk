/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:07:14 by lauragm           #+#    #+#             */
/*   Updated: 2024/11/06 18:21:19 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <unistd.h>

void	server_recieve(int boolean)
{
	static int	bit_displacement = 0;
	static char	letter = 0;

	letter += ((boolean & 1) << bit_displacement++);
	if (bit_displacement == 8)
	{
		write(1, &letter, 1);
		bit_displacement = 0;
		letter = 0;
	}
	return ;
}

void	handle_signals(int sig)
{
	if (sig == SIGUSR1)
		server_recieve(0); // Recibe un 0
	else if (sig == SIGUSR2)
		server_recieve(1); // Recibe un 1
}
