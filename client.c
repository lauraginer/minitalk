/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:18:29 by lginer-m          #+#    #+#             */
/*   Updated: 2024/10/29 20:47:28 by lauragm          ###   ########.fr       */
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
//enviar el PIDserver al cliente y el string
int	send_client(t_program *program, int	server_pid, char *str)
{
	//ft_printf("Sending server PID %d client is %d\n", program->pid_server, program->pid_client);
	send_string(server_pid, str);
	return(1);
}

//enviar la cadena de caracteres al servidor bit a bit
int	send_string(int server_pid, char *str)
{
	int i;
	int bit;
	
	i = 0;
	while (str[i])
	{
		bit = 0;
		while (bit < 8)
	}
}