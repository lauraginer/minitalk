/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:42:59 by lginer-m          #+#    #+#             */
/*   Updated: 2024/10/28 20:28:43 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	t_program	program;
	int		server_pid;

	(void)argv;
	if (argc == 2)
	{
		ft_memset(&program, 0, sizeof(t_program));
		ejecute_server(&program);
		
		
	}
	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		send_client(&program, server_pid);
	}
	else
	{
		ft_printf("Error: Invalid arguments\n");
		exit(EXIT_FAILURE); //termina el programa y devuelve un codigo de error al sistema operativo
	}
	return(0);
}
