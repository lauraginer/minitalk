/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:49:46 by lginer-m          #+#    #+#             */
/*   Updated: 2024/11/06 17:45:15 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

int		ejecute_server(void);
void	server_loop(void);
void	server_recieve(int boolean);
int		send_client(int server_pid, char *str);
int		send_string(int server_pid, char *str);
int		send_bit(int server_pid, int bit);
void	handle_signals(int sig);

#endif
