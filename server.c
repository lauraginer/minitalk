/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:18:16 by lginer-m          #+#    #+#             */
/*   Updated: 2024/10/29 20:30:36 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//ejecutar servidor y mostrar su pid
int		ejecute_server(t_program *program)
{
	program->pid_server = getpid();
	ft_printf("Perfect! Your server PID is %d\n", program->pid_server);
	signal(SIGUSR1, handle_sigusr1); //registrar las funciones de manejo de señales
	signal(SIGUSR2, handle_sigusr2);
	return (1);
}
//enviar el PIDserver al cliente

