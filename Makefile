# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrouves <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 18:27:35 by mrouves           #+#    #+#              #
#    Updated: 2024/11/21 18:38:50 by mrouves          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			:= libft.a

SRCS			:= ft_atoi.c\
					ft_isalpha.c\
					ft_isprint.c\
					ft_memcpy.c\
					ft_strchr.c\
					ft_strlen.c\
					ft_strrchr.c\
					ft_bzero.c\
					ft_isascii.c\
					ft_memchr.c\
					ft_memmove.c\
					ft_strlcat.c\
					ft_strncmp.c\
					ft_isalnum.c\
					ft_isdigit.c\
					ft_memcmp.c\
					ft_memset.c\
					ft_toupper.c\
					ft_tolower.c\
					ft_strlcpy.c\
					ft_strnstr.c\
					ft_strdup.c\
					ft_calloc.c\
					ft_itoa.c\
					ft_strjoin.c\
					ft_putchar_fd.c\
					ft_putstr_fd.c\
					ft_split.c\
					ft_substr.c\
					ft_strtrim.c\
					ft_strmapi.c\
					ft_striteri.c\
					ft_putendl_fd.c\
					ft_putnbr_fd.c\
					ft_printf.c\
					get_next_line.c\
					ft_lstnew.c\
					ft_lstadd_front.c\
					ft_lstsize.c\
					ft_lstlast.c\
					ft_lstadd_back.c\
					ft_lstdelone.c\
					ft_lstclear.c\
					ft_lstiter.c\
					ft_lstmap.c

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
