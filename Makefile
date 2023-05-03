# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/07 18:35:15 by pgouasmi          #+#    #+#              #
#    Updated: 2023/04/27 17:38:26 by pgouasmi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a
# SRCSLIB = /libft/ft_isalnum.c	\
# 		/libft/ft_isalpha.c		\
# 		/libft/ft_isascii.c		\
# 		/libft/ft_isdigit.c		\
# 		/libft/ft_isprint.c		\
# 		/libft/ft_itoa.c		\
# 		/libft/ft_strchr.c		\
# 		/libft/ft_strdup.c		\
# 		/libft/ft_strjoin.c		\
# 		/libft/ft_strlcat.c		\
# 		/libft/ft_strlcpy.c		\
# 		/libft/ft_strlen.c		\
# 		/libft/ft_strncmp.c		\
# 		/libft/ft_strnstr.c		\
# 		/libft/ft_strrchr.c		\
# 		/libft/ft_strtrim.c		\
# 		/libft/ft_substr.c		\
# 		/libft/ft_tolower.c		\
# 		/libft/ft_toupper.c		\
# 		/libft/ft_atoi.c		\
# 		/libft/ft_itoa.c		\
# 		/libft/ft_split.c 		\
# 		/libft/ft_strtrim.c		\
# 		/libft/ft_substr.c		\
# 		/libft/ft_bzero.c		\
# 		/libft/ft_memcpy.c		\
# 		/libft/ft_memmove.c		\
# 		/libft/ft_memset.c		\
# 		/libft/ft_strmapi.c		\
# 		/libft/ft_striteri.c	\
# 		/libft/ft_calloc.c		\
# 		/libft/ft_memcmp.c		\
# 		/libft/ft_memchr.c		\
# 		/libft/ft_putchar_fd.c	\
# 		/libft/ft_putstr_fd.c	\
# 		/libft/ft_putnbr_fd.c	\
# 		/libft/ft_putendl_fd.c	\
# 		/libft/ft_lstadd_front.c	\
# 		/libft/ft_lstlast.c		\
# 		/libft/ft_lstnew.c		\
# 		/libft/ft_lstsize.c		\
# 		/ft_printf/ft_printf.c		\
# 		/ft_printf/ft_putchar_pf.c	\
# 		/ft_printf/ft_putnbr_base.c	\
# 		/ft_printf/ft_putnbr_base_p.c\
# 		/ft_printf/ft_putstr_pf.c	\
# 		/GNL/get_next_line.c		\
# 		/GNL/get_next_line_bonus.c		\
# 		/GNL/get_next_line_utils.c		\
# 		/GNL/get_next_line_utils_bonus.c		\
# 		/push_swap/push_swap.c				\
# 		/push_swap/instructions_ps/instructions_push_swap.c	\
# 		/push_swap/instructions_ps/instructions_push_swap2.c	\
# 		/push_swap/instructions_ps/instructions_push_swap3.c	\
# 		/push_swap/push_swap_resources/argv_manager1.c			\
# 		/push_swap/push_swap_resources/argv_manager2.c			\
# 		/push_swap/push_swap_resources/push_swap_tools.c			\
# 		/push_swap/push_swap_resources/radix_tools.c				\
# 		/push_swap/push_swap_resources/radix_index_tools.c		\
# 		/push_swap/push_swap_algorithms/push_swap_algorithms.c 	\
# 		/push_swap/push_swap_algorithms/two_elements_case.c		\
# 		/push_swap/push_swap_algorithms/three_elements_case.c	\
# 		/push_swap/push_swap_algorithms/radix_sort.c	\

LIBFT_PATH	=	./includes/

LIBFT_FILE	=	libft.a
		
MLX_FILE	=	libmlx.a

LIBFT_LIB	=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

MLX_FLAG	=	-framework OpenGL -framework AppKit 

MLX_PATH	=	./minilibx_opengl_20191021/

MLX_LIB		=	$(addprefix $(MLX_PATH), $(MLX_FILE))

MLX_EX		=	$(MLX_LIB) $(MLX_FLAG)

OBJS = ${SRCSLIB:.c=.o}

HEADER = so_long.h

CC = cc

FLAG = -Wall -Wextra -Werror

C_FILE		=	so_long.c				\

SRC			=	$(addprefix $(SRC_DIR),$(C_FILE))

OBJ			=	$(SRC:.c=.o)

.c.o:
	$(CC) $(FLAG) -c $< -o $@

all:	$(NAME)

lib:	
	@make -C $(LIBFT_PATH)

mlx:
	@make -sC $(MLX_PATH)

%.o:	%.c $(HEADER) Makefile
			$(CC) $(FLAG) -I . -c $< -o $@

$(NAME): lib mlx $(OBJ)
	$(CC) $(OBJ) $(LIBFT_LIB) $(MLX_EX) -o $(NAME)

clean:
	@make clean -sC $(MLX_PATH)
	@make clean -sC $(LIBFT_PATH)
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)


ffclean:	fclean
			rm -f ./a.out

re :
	make fclean
	make

remake :	re
			$(CC) $(FLAG) so_long.c so_long.a