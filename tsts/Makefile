# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: okuilboe <okuilboe@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2025/04/25 16:17:43 by okuilboe      #+#    #+#                  #
#    Updated: 2025/05/24 23:04:37 by okuilboe      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# ==== CONFIG ====

NAME		:= pftest

LIB_SRC_DIR	:= ../srcs		# default symlink target used if not provided
LIB_LNK_TGT	:= $(CURDIR)/ft_printf

LIBRARY		= $(LIB_LNK_TGT)/libftprintf.a

CC 			:= cc
CFLAGS		:= -Wall -Werror -Wextra
CPPFLAGS	:= -I. -Ift_printf -Ift_printf/libft
LDFLAGS 	:= -Lft_printf -lftprintf -Lft_printf/libft -lft

# ==== FILES ====

SRCS		:= $(wildcard *.c) $(wildcard utils/*.c)
OBJS		:= $(SRCS:.c=.o)

# ==== RULES =====

.PHONY = all link-lib clean fclean

all: $(LIBRARY) $(NAME)

$(LIBRARY): $(LIB_LNK_TGT)
	@$(MAKE) -C $(LIB_LNK_TGT)

$(LIB_LNK_TGT):
	@echo "re-creating symlink to the target library."
	@ln -snf $(LIB_SRC_DIR) $(LIB_LNK_TGT) # Create symbolic link to the libft directory

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIB_LNK_TGT) $(LDFLAGS) -o $(NAME)

relib: $(LIB_LNK_TGT)
	@$(MAKE) -C $(LIB_LNK_TGT) relib

rmlib: $(LIB_LNK_TGT)
	@$(MAKE) -C $(LIB_LNK_TGT) rmlib

%.o: %.c
	@echo $?
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $^ -o $@

clean:
	@$(MAKE) -C $(LIB_LNK_TGT) clean
	@echo "Purging object files"
	rm -f $(OBJS)


fclean: clean
	@$(MAKE) -C $(LIB_LNK_TGT) fclean
	rm -f $(NAME)
	rm -f $(LIB_LNK_TGT)

re: fclean all

