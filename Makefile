# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/17 06:47:34 by brturcio          #+#    #+#              #
#    Updated: 2025/08/05 18:28:09 by brturcio         ###   ########.fr        #
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
SRCS		:=	$(DIR_SRCS)/alloc_control.c \
				$(DIR_SRCS)/exit.c \
				$(DIR_SRCS)/errors.c \
				$(DIR_SRCS)/init_structs.c \
				$(DIR_SRCS)/monitor.c \
				$(DIR_SRCS)/parse_args.c \
				$(DIR_SRCS)/threads.c \
				$(DIR_SRCS)/routine.c \
				$(DIR_SRCS)/utils.c \
				$(DIR_SRCS)/main.c

OBJS		:=	$(DIR_OBJS)/alloc_control.o \
				$(DIR_OBJS)/exit.o \
				$(DIR_OBJS)/errors.o \
				$(DIR_OBJS)/init_structs.o \
				$(DIR_OBJS)/monitor.o \
				$(DIR_OBJS)/parse_args.o \
				$(DIR_OBJS)/threads.o \
				$(DIR_OBJS)/routine.o \
				$(DIR_OBJS)/utils.o \
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
