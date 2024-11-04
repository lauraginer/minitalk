/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:18:29 by lginer-m          #+#    #+#             */
/*   Updated: 2024/11/04 19:52:39 by lginer-m         ###   ########.fr       */
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

	int	main(int argc, char **argv)
{
	int	server_pid;
	
	if (argc == 3)//client
	{
		server_pid = ft_atoi(argv[1]); //convierte la string a un entero
		if (send_client(server_pid, argv[2]) < 1)
		{
			ft_printf("Error: Failed the conexion with client\n");
			return (1);
		}
	}
	else
	{
		ft_printf("Error: Invalid arguments\n");
		exit(EXIT_FAILURE); //termina el programa y devuelve un codigo de error al sistema operativo
	}
	return(0);
}
