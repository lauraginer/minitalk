/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:18:29 by lginer-m          #+#    #+#             */
/*   Updated: 2024/10/31 13:26:56 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//enviar el PIDserver al cliente y el string
int	send_client(int	server_pid, char *str)
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
		{
			if((str[i] >> bit) & 1)//verifica si un bit especifico es 1
				kill(server_pid, SIGUSR1); //envia la señal
			else
				kill(server_pid, SIGUSR2);
			usleep(100);
			bit++;
		}
		i++;	
	}
	return (1);
	}
