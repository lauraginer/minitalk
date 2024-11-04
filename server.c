/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:18:16 by lginer-m          #+#    #+#             */
/*   Updated: 2024/11/04 20:05:54 by lginer-m         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_program	program;
	
	(void)argv;
	ft_memset(&program, 0, sizeof(t_program));
	ft_printf("Starting server....\n");
	if (argc == 1)//server
	{
		if (ejecute_server(&program) < 1)
		{
			ft_printf("Error: Failed to get PID of server");
			exit(EXIT_FAILURE);
		}
		
	}
	else
	{
		ft_printf("Error: Invalid arguments\n");
		exit(EXIT_FAILURE); //termina el programa y devuelve un codigo de error al sistema operativo
	}
	server_loop();
	return(0);
}
	