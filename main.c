/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:42:59 by lginer-m          #+#    #+#             */
/*   Updated: 2024/10/31 13:42:09 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	t_program	program;
	int		server_pid;
	
	ft_memset(&program, 0, sizeof(t_program));
	if (argc == 2)//server
	{
		if (ejecute_server(&program) < 1)
		{
			ft_printf("Error: Failed to get PID of server");
			return (1);
		}
		server_loop();
		
	}
	else if (argc == 3)//client
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
