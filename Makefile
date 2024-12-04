# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrouves <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 18:27:35 by mrouves           #+#    #+#              #
#    Updated: 2024/12/04 12:28:02 by mrouves          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			:= libft.a

include sources/sources.mk

DIR_OBJS		:= .objs
DIR_SOURCES		:= sources
DIR_HEADERS		:= headers
OBJS			:= $(addprefix $(DIR_OBJS)/, $(SRCS:%.c=%.o))

CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror
IFLAGS			:= -I $(DIR_HEADERS)

GREEN			= \033[0;32m
RED				= \033[0;31m
END				= \033[0m
DIR_DUP			= mkdir -p $(@D)

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $@ $^
	@printf "$(GREEN)$(NAME) created$(END)\n"

$(DIR_OBJS)/%.o: $(DIR_SOURCES)/%.c
	@$(DIR_DUP)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@rm -rf $(DIR_OBJS)
	@printf "$(RED)$(NAME) cleaned objs$(END)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(RED)$(NAME) removed$(END)\n"

re: fclean all

.PHONY: clean fclean re all
