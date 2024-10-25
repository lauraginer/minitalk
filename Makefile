# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/25 10:43:36 by lginer-m          #+#    #+#              #
#    Updated: 2024/10/25 11:32:14 by lginer-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

CC = clang
CFLAGS = -g -Wall -Werror -Wextra \
		#-fsanitize=address,undefined \
		#-Wunreachable-code -Ofast \


LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

HEADERS = -I$(LIBFT) -I$(FT_PRINTF)

SRCS = main.c \

OBJS = ${SRCS:.c=.o}

all: libft ft_printf $(NAME)
libft:
	make -C $(LIBFT_DIR)
ft_printf:
	@make -C $(FT_PRINTF_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $< 
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(HEADERS) $(OBJS) $(LIBFT) $(FT_PRINTF) $(LINK) -o $(NAME)
	@echo "Compiling Minitalk..."

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBFT_DIR)/*.o
	@rm -rf $(FT_PRINTF_DIR)/*.o

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)
	@rm -rf $(FT_PRINTF)

re: fclean all

.PHONY: all, clean, fclean, re, libft, ft_printf