# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/17 06:47:34 by brturcio          #+#    #+#              #
#    Updated: 2025/06/19 14:23:06 by brturcio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==================== CONFIG ====================
NAME		:= philo
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g
INC			:= -Iinc

# ==================== DIRECTORIES ====================
DIR_SRCS	:= srcs
DIR_OBJS	:= objs

# ==================== FILES ====================
SRCS		:=	$(DIR_SRCS)/ft_check_args_utils.c \
				$(DIR_SRCS)/ft_check_args.c \
				$(DIR_SRCS)/ft_control_free_msjs_errors.c \
				$(DIR_SRCS)/ft_init_the_struct.c \
				$(DIR_SRCS)/ft_utils.c \
				$(DIR_SRCS)/main.c

OBJS		:=	$(DIR_OBJS)/ft_check_args_utils.o \
				$(DIR_OBJS)/ft_check_args.o \
				$(DIR_OBJS)/ft_control_free_msjs_errors.o \
				$(DIR_OBJS)/ft_init_the_struct.o \
				$(DIR_OBJS)/ft_utils.o \
				$(DIR_OBJS)/main.o 

# ==================== RULES ====================
all : $(NAME)

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "✅ Compilation completed: $(NAME)"

clean :
	@rm -rf $(DIR_OBJS)
	@echo "✅ clean done."

fclean : clean
	@rm -f $(NAME)
	@echo "✅ fclean done."

re : fclean all

.PHONY : all clean fclean re
