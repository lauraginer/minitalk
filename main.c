/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:42:59 by lginer-m          #+#    #+#             */
/*   Updated: 2024/10/25 15:13:13 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	t_program	program;

	if (argc == 3)
	{
		ft_memset(&program, 0, sizeof(t_program));
		ejecute_server(&program, argv);
	}
	else
	{
		ft_printf("Error: Invalid arguments\n");
		exit(EXIT_FAILURE); //termina el programa y devuelve un codigo de error al sistema operativo
	}
	return(0);
}

//ejecutar servidor y mostrar su pid
void	*ejecute_server(t_program *program)
{
	program->pid_server = getpid();
	ft_printf("Your server PID is %d\n", program->pid_server);
	return ;
}