# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 12:23:09 by mrouves           #+#    #+#              #
#    Updated: 2025/01/22 14:54:47 by mrouves          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			:=	allocs/alloc.c\
					allocs/ft_memcpy.c\
					allocs/ft_memset.c\
					allocs/ft_memmove.c\
					allocs/ft_bzero.c\
					allocs/ft_memcmp.c\
					allocs/ft_memchr.c\
					allocs/ft_calloc.c\
					allocs/ft_realloc.c\
					allocs/mem_dynamic_cache.c\
					allocs/mem_static_cache.c\
					string/ft_atoi.c\
					string/ft_isalpha.c\
					string/ft_isspace.c\
					string/ft_isprint.c\
					string/ft_strchr.c\
					string/ft_strlen.c\
					string/ft_strrchr.c\
					string/ft_isascii.c\
					string/ft_strlcat.c\
					string/ft_strncmp.c\
					string/ft_isalnum.c\
					string/ft_isdigit.c\
					string/ft_toupper.c\
					string/ft_tolower.c\
					string/ft_strlcpy.c\
					string/ft_strnstr.c\
					string/ft_strdup.c\
					string/ft_itoa.c\
					string/ft_strjoin.c\
					string/ft_split.c\
					string/ft_substr.c\
					string/ft_strtrim.c\
					string/ft_strmapi.c\
					string/ft_striteri.c\
					string/get_next_line.c\
					prints/ft_putchar_fd.c\
					prints/ft_putstr_fd.c\
					prints/ft_putendl_fd.c\
					prints/ft_putnbr_fd.c\
					prints/ft_printf.c\
					abstracts/array_list.c\
					abstracts/collection_instance.c\
					abstracts/collection_accessor.c\
					abstracts/collection_addition.c\
					abstracts/collection_deletion.c\
					abstracts/hashmap.c\
					abstracts/hash.c\
