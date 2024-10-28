/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:18:29 by lginer-m          #+#    #+#             */
/*   Updated: 2024/10/28 20:29:16 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//ejecutar cliente y mostrar su pid
int		ejecute_client(t_program *program)
{
	program->pid_client = getpid();
	ft_printf("Your client PID is %d\n", program->pid_client);
	return (1);
}
/*El cliente debe de recibir el PID del servidor y 
la string que se quiere enviar (comunicar la string pasada como parámetro al servidor)*/
/*int	receive_client(t_program *program, int pid, char *str)
{
	int i;

	i = 0;
	if(i < program->pid_server)
	{
		ft_printf("PID server is arrived");
		program->pid_client = program->pid_server;
		return(1);
	}
}*/
