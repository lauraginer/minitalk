/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:18:16 by lginer-m          #+#    #+#             */
/*   Updated: 2024/10/31 13:25:36 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//ejecutar servidor y mostrar su pid
int		ejecute_server(t_program *program)
{
	program->pid_server = getpid();
	ft_printf("Perfect! Your server PID is %d\n", program->pid_server);
	signal(SIGUSR1, handle_signals); //registrar las funciones de manejo de señales
	signal(SIGUSR2, handle_signals);
	return (1);
}
//bucle y gestionar los errores de las señales
void	server_loop(void)
{
	while (1)
	{
		if ((signal(SIGUSR1, handle_signals) == SIG_ERR)
			|| (signal(SIGUSR2, handle_signals) == SIG_ERR))
		{
			ft_printf("Error: Signal failure\n");
			exit(EXIT_FAILURE);
		}
		sleep(10);
	}
	return ;
}
	