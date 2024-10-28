/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:18:16 by lginer-m          #+#    #+#             */
/*   Updated: 2024/10/28 20:29:33 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//ejecutar servidor y mostrar su pid
int		ejecute_server(t_program *program)
{
	program->pid_server = getpid();
	ft_printf("Your server PID is %d\n", program->pid_server);
	return (1);
}
//enviar el PIDserver al cliente
int	send_client(t_program *program, int	server_pid)
{
	//ft_printf("Sending server PID %d client is %d\n", program->pid_server, program->pid_client);
	kill(server_pid, SIGUSR1);
	return(1);
}

//Gestionar la señal SIGUSR1 y en otra funcion la SIGUSR2
void handle_sigusr1(int signum, siginfo_t *info, void *context);
