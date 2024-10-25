/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:49:46 by lginer-m          #+#    #+#             */
/*   Updated: 2024/10/25 15:06:24 by lginer-m         ###   ########.fr       */
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
	int	pid_client;
}	t_program;

void	*ejecute_server(t_program *program);

#endif