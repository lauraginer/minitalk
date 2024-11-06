# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/25 10:43:36 by lginer-m          #+#    #+#              #
#    Updated: 2024/11/06 17:56:30 by lginer-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -g -Wall -Werror -Wextra \
        -g -fsanitize=address,undefined \
        #-Wunreachable-code -Ofast \

NAME_SERVER = server
SERVER_SRC = server.c
SERVER_OBJ = $(SERVER_SRC:.c=.o)

NAME_CLIENT = client
CLIENT_SRC = client.c
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

SIGNALS_SRC = signals.c
SIGNALS_OBJ = $(SIGNALS_SRC:.c=.o)

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(SERVER_OBJ) $(SIGNALS_OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(SERVER_OBJ) $(SIGNALS_OBJ) $(LIBFT) $(FT_PRINTF)

$(NAME_CLIENT): $(CLIENT_OBJ) $(SIGNALS_OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(CLIENT_OBJ) $(SIGNALS_OBJ) $(LIBFT) $(FT_PRINTF)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

clean:
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ) $(SIGNALS_OBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	make -C $(LIBFT_DIR) fclean
	make -C $(FT_PRINTF_DIR) fclean

re: fclean all
