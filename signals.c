/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:07:14 by lauragm           #+#    #+#             */
/*   Updated: 2024/10/29 20:21:49 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.c"

void handle_sigusr1(int sig)
{
	(void)sig;
	write(1,"SIGUSR1\n", 9);
} //utiliza esto para utilizar la señal: signal(SIGUSR1, handle_sigusr1) y manejala en caso de error;

void handle_sigusr2(int sig)
{
	(void)sig;
	write(1,"SIGUSR2\n", 9);
}//utiliza esto para utilizar la señal: signal(SIGUSR2, handle_sigusr2);