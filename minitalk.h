/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:49:46 by lginer-m          #+#    #+#             */
/*   Updated: 2024/11/05 21:00:46 by lginer-m         ###   ########.fr       */
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
# include <stdio.h>

int	ejecute_server(void);
void server_loop(void);
void server_recieve(int boolean);
int	send_client(int	server_pid, char *str);
int	send_string(int server_pid, char *str);
int send_bit(int server_pid, int bit);
void handle_signals(int sig);

#endif
