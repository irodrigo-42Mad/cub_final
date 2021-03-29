# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/23 11:31:25 by irodrigo          #+#    #+#              #
#    Updated: 2021/03/29 17:57:22 by irodrigo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# OS DISCLAIMER #
.DELETE_ON_ERROR:

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Linux)
	LIBS := -lm -lbsd -lX11 -lXext
	MLX = mlx_linux/libmlx.a
	MINILIBX = mlx_linux
	INCLUDES = -I/usr/include -I. -Iincludes/ -I$(MINILIBX) -I$(LIBFT)
endif
ifeq ($(UNAME_S), Darwin)
	LIBS := -lz -framework OpenGL -framework AppKit
	MLX = mlx_ios/libmlx.dylib
	MINILIBX = mlx_ios
	INCLUDES = -I/usr/include -I. -Iincludes/ -I$(MINILIBX) -I$(LIBFT)
endif

# FILE NAME #
NAME = cub3D
NAMEBONUS = cub3D

# SOURCES #
SRC = 	ft_create_map ft_check_error ft_draw_game ft_elm_threatment ft_init_structs \
		ft_keyb_aux ft_keyboard ft_main ft_numbers ft_map_parser ft_parse_file ft_save_bmp \
		ft_screen_save ft_set_raycast ft_set_sprite ft_sprite_draw gnl ft_libft_aux \
		ft_file_check ft_aux_fnc ft_textures ft_file_parser ft_clean ft_create_map_aux \
		ft_aux_fnc_second

SRCBONUS = ft_create_map_bonus ft_check_error_bonus ft_draw_game_bonus ft_elm_threatment_bonus ft_init_structs_bonus \
		ft_keyb_aux_bonus ft_keyboard_bonus ft_main_bonus ft_numbers_bonus ft_map_parser_bonus ft_parse_file_bonus ft_save_bmp_bonus \
		ft_screen_save_bonus ft_set_raycast_bonus ft_set_sprite_bonus ft_sprite_draw_bonus gnl_bonus ft_libft_aux_bonus \
		ft_file_check_bonus ft_aux_fnc_bonus ft_textures_bonus ft_file_parser_bonus ft_clean_bonus ft_create_map_aux_bonus

SRCCUB = $(addsuffix .c, $(SRC))
SRCCUBBONUS = $(addsuffix .c, $(SRCBONUS))

OBJS = $(SRCCUB:.c=.o)
OBJSBONUS = $(SRCCUBBONUS:.c=.o)

LIBFT = libft/libft.a

# COMPILER #
CC = gcc -Wall -Wextra -Werror -O3 #-g3 -fsanitize=address

# COLOUR DEFINITION #
BLUE = \033[0;34m
GREEN = \033[1;32m
RESET = \033[0m

# CLEANING INSTRUCTION #
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BLUE)==========CREATING LIBFT==========$(RESET)"
	@cd libft && make re
	@echo "$(BLUE)==========CREATING MINILIBX==========$(RESET)"
	@make -C ${MINILIBX}
	@echo "$(BLUE)==========CREATING CUBE==========$(RESET)"
	@$(CC) $(INCLUDES) ${OBJS} $(LIBFT) $(MLX) ${LIBS} -o ${NAME}
	@echo "Done"
	@echo "$(BLUE)==========COPY LIBMLX.DYLIB==========$(RESET)"
	@cp ${MLX} ./
	@echo "Done"
	@echo "$(GREEN)==========WELLDONE==========$(RESET)"
	@echo "Success creating Cub3D file"

bonus:  $(OBJSBONUS)
	@echo "$(BLUE)==========CREATING LIBFT==========$(RESET)"
	@cd libft && make re
	@echo "$(BLUE)==========CREATING MINILIBX==========$(RESET)"
	@make -C ${MINILIBX}
	@echo "$(BLUE)==========CREATING CUBE==========$(RESET)"
	@$(CC) $(INCLUDES) ${OBJSBONUS} $(LIBFT) $(MLX) ${LIBS} -o ${NAMEBONUS}
	@echo "Done"
	@echo "$(BLUE)==========COPY LIBMLX.DYLIB==========$(RESET)"
	@cp ${MLX} ./
	@echo "Done"
	@echo "$(GREEN)==========WELLDONE==========$(RESET)"
	@echo "Success creating Cub3D file"

normi: fclean
	norminette $(SRCCUB) $(SRCCUBBONUS) ./libft ./cub3d.h ./lst_errors.h ./colors.h ./cub3d_bonus.h ./colors_bonus.h ./lst_errors_bonus.h

clean:
	@$(RM) $(OBJS)
	@$(RM) $(OBJSBONUS)
	@make -C $(MINILIBX)/ clean
	@make -C libft/ clean
	@$(RM) ${LIBFT}
	@${RM} libmlx.dylib
	@${RM} cub3d.h.gch
	@echo "$(GREEN)==========REMOVED==========$(RESET)"
	@echo "Success normal cleaning"

fclean: clean
	@$(RM) ${NAME}
	@$(RM) *.bmp
	@echo "$(GREEN)==========TOTALLY REMOVED==========$(RESET)"
	@echo "Success deepest cleaning"

re : fclean all

.PHONY: all clean fclean re shell addsuffix normi
