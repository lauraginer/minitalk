/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:49:46 by lginer-m          #+#    #+#             */
/*   Updated: 2024/10/31 13:27:08 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <sys/types.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_program
{
	int pid_server;
//	int	pid_client;
}	t_program;

int	ejecute_server(t_program *program);
void server_loop(void);
int	ejecute_client(t_program *program);
int	send_client(int	server_pid, char *str);
int	send_string(int server_pid, char *str);
void handle_signals(int sig);


#endif
