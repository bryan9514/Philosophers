# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/17 06:47:34 by brturcio          #+#    #+#              #
#    Updated: 2025/06/17 07:42:34 by brturcio         ###   ########.fr        #
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
SRCS		:= 	$(DIR_SRCS)/main.c \



OBJS		:=	$(DIR_OBJS)/main.o \


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
