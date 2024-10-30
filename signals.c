/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:07:14 by lauragm           #+#    #+#             */
/*   Updated: 2024/10/30 20:26:21 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.c"

void handle_sigusr1(int sig, siginfo_t *info, void *ucontext)
{
	char	current_char;
	int		bit_count;
	int		i;
	(void)sig;
	write(1,"SIGUSR1\n", 9);

	current_char = 0;
	bit_count = 0;
	i = -1;
	if(current_char > i)
	{
		current_char |= (1 << bit_count);
		bit_count++;
	}
	if(bit_count == 8)
	{
		write(1,&current_char, 1);
		current_char = 0;
		bit_count = 0;
	}	
} //utiliza esto para utilizar la señal: signal(SIGUSR1, handle_sigusr1) y manejala en caso de error;

void handle_sigusr2(int sig)
{
	(void)sig;
	write(1,"SIGUSR2\n", 9);
}//utiliza esto para utilizar la señal: signal(SIGUSR2, handle_sigusr2);