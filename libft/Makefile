NAME = libft.a

HEADER_DIR		= ./includes/

OBJS_DIR		= objects/

SRCS_DIR		= functions/

SRCS = $(addprefix $(SRCS_DIR),\
	\
	alloc/ft_calloc.c \
	alloc/ft_realloc.c\
	\
	convert/ft_atoi.c \
	convert/ft_atol.c \
	convert/ft_itoa.c \
	\
	gnl/get_next_line_utils.c \
	gnl/get_next_line.c \
	\
	is/ft_isalnum.c \
	is/ft_isalpha.c \
	is/ft_isascii.c \
	is/ft_isdigit.c \
	is/ft_isprint.c \
	is/ft_isspace.c \
	\
	lst/ft_lstadd_back.c \
	lst/ft_lstadd_front.c \
	lst/ft_lstclear.c \
	lst/ft_lstdelone.c \
	lst/ft_lstiter.c \
	lst/ft_lstlast.c \
	lst/ft_lstmap.c \
	lst/ft_lstnew.c \
	lst/ft_lstsize.c \
	\
	mem/ft_memchr.c \
	mem/ft_memcmp.c \
	mem/ft_memcpy.c \
	mem/ft_memdealloc.c \
	mem/ft_memmove.c \
	mem/ft_memset.c \
	\
	printf/ft_printf_itoa.c \
	printf/ft_printf_put_hex.c \
	printf/ft_printf_put_percent.c \
	printf/ft_printf_put_uintptr.c \
	printf/ft_printf_put_unsigned.c \
	printf/ft_printf_putchar_fd.c \
	printf/ft_printf_putnbr_fd.c \
	printf/ft_printf_putstr_fd.c \
	printf/ft_printf_uitoa.c \
	printf/ft_printf.c \
	\
	put_fd/ft_putchar_fd.c \
	put_fd/ft_putendl_fd.c \
	put_fd/ft_putnbr_fd.c \
	put_fd/ft_putstr_fd.c \
	\
	str/ft_bzero.c \
	str/ft_split.c \
	str/ft_strchr.c \
	str/ft_strcmp.c \
	str/ft_strdup.c \
	str/ft_striteri.c \
	str/ft_strjoin.c \
	str/ft_strlcat.c \
	str/ft_strlcpy.c \
	str/ft_strlen.c \
	str/ft_strmapi.c \
	str/ft_strncmp.c \
	str/ft_strnstr.c \
	str/ft_strrchr.c \
	str/ft_strtrim.c \
	str/ft_substr.c \
	str/ft_tolower.c \
	str/ft_toupper.c)

OBJS	= $(patsubst $(SRCS_DIR)%.c,$(OBJS_DIR)%.o,$(SRCS))

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -I$(HEADER_DIR)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I $(HEADER_DIR) -c $< -o $@
	@echo "$(CYAN)Compiled $<$(RESET)"

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)Successful compilation of $(LIGHT_PURPLE)libft$(RESET) 🎉"

all: $(NAME)

clean:
	@rm -rf $(OBJS_DIR)
	@echo "${NAME}: ${RED} All objects files of $(NAME) have been deleted ❌${RESET}"

fclean: clean
	@rm -f $(NAME)
	@echo "${NAME}: ${RED} All ${NAME} files were deleted ❌${RESET}"

re: fclean all

.PHONY: all clean fclean re

# Colors
BLACK			=	\033[0;30m
BLUE			=	\033[0;34m
CYAN			=	\033[0;36m
GREEN			=	\033[0;32m
ORANGE			=	\033[0;33m
PURPLE			=	\033[0;35m
RED				=	\033[0;31m
WHITE			=	\033[1;37m
YELLOW			=	\033[1;33m
DARK_GRAY		=	\033[1;30m
LIGHT_GRAY		=	\033[0;37m
LIGHT_BLUE		=	\033[1;34m
LIGHT_RED		=	\033[1;31m
LIGHT_CYAN		=	\033[1;36m
LIGHT_GREEN		=	\033[1;32m
LIGHT_PURPLE	=	\033[1;35m
RESET			= 	\033[0m
