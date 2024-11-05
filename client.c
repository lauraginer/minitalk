/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:18:29 by lginer-m          #+#    #+#             */
/*   Updated: 2024/11/05 20:58:47 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//falta el btoa, para traducir los numeros binarios
//enviar el PIDserver al cliente y el string
int	send_client(int	server_pid, char *str)
{
	if (send_string(server_pid, str) < 0)
	{
			ft_printf("Error: Failed the conexion with client\n");
			return (-1);
	}
	return(1);
}
int send_bit(int server_pid, int bit)
{
	if (bit == 0)
		return(kill(server_pid, SIGUSR1));
	else
		return(kill(server_pid, SIGUSR2));
	return (0);
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
			if(send_bit(server_pid, (str[i] >> bit) & 1) == -1)//verifica si un bit especifico es 1 y envia la señal
				return (-1);
			usleep(200);
			bit++;
		}
		i++;	
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	server_pid;
	
	if (argc == 3)//client
	{
		server_pid = ft_atoi(argv[1]); //convierte la string a un entero
		if(send_client(server_pid, argv[2]) < 1)
		{
			ft_printf("Error: Failed the connection with server\n");
			exit(EXIT_FAILURE);
		}
	
	}
	else
	{
		ft_printf("Error: Invalid arguments\n");
		exit(EXIT_FAILURE); //termina el programa y devuelve un codigo de error al sistema operativo
	}
	return(0);
}
