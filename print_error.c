/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:20:56 by lginer-m          #+#    #+#             */
/*   Updated: 2024/10/25 14:22:03 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}