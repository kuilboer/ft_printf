# ==== CONFIG ====

NAME = libftprintf.a

LIBFT_SRC = https://github.com/kuilboer/libft.git
LIBFT_DIR = $(CURDIR)/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

# ==== COMPILER ====

CC 			:= cc
CFLAGS		:= -Wall -Werror -Wextra
CPPFLAGS	:= -I. -Ilibft
LDFLAGS 	:= 

# ==== FILES ==== 

SRCS = \
	ft_printf.c   		\
	ft_vfprintf.c		\
	ft_tohex.c			\
	handle_char.c		\
	handle_str.c		\
	handle_ptr.c 		\
	handler_utils.c		\
	handle_hex.c		\
	handle_hex_format.c \
	fmt_parser.c		\


OBJS = $(SRCS:.c=.o)

.PHONY: all lib clean fclean re rmlib relib

all: lib $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS) libft/libft.a

%.o: %.c
	@echo $?
	$(CC) -c -g -O0 $(CPPFLAGS) $(LDFLAGS) $(CFLAGS) $^ -o $@

lib: $(LIBFT_DIR)
	@$(MAKE) -C $(LIBFT_DIR)

$(LIBFT_DIR):
	@git clone $(LIBFT_SRC) $(LIBFT_DIR)
	@rm -rf $(LIBFT_DIR)/.git*
	
relib: rmlib $(LIBFT_DIR) re 

rmlib:
	@echo "Removing library directories: "
	@echo "    - $(LIBFT_DIR)" 
	@rm -rf $(LIBFT_DIR)

clean: $(LIBFT_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "Removing object files." 
	@rm -f $(OBJS)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "Removing compiled output files." 
	@rm -f $(NAME)

re: fclean all