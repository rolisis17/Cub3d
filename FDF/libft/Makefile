SRCS = ft_strlen.c ft_toupper.c ft_tolower.c ft_strrchr.c \
ft_strchr.c ft_isprint.c ft_isdigit.c ft_isascii.c ft_isalpha.c \
ft_isalnum.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
ft_strlcat.c ft_strlcpy.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
GNL = get_next_line.c get_next_line_utils.c
CFLAGS = -Wall -Wextra -Werror -fPIE
CC = cc
NAME = libft.a
OBJS = $(SRCS:.c=.o)
BON_OBJ = $(BONUS:.c=.o)
GNL_OBJ = $(GNL:.c=.o)
RM = rm -f
LIBC = ar rcs
INCS = libft.h
DB = -g

.c.o: $(INCS)
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	@$(LIBC) $(NAME) $(OBJS)

all: $(NAME)

bonus: $(BON_OBJ) $(GNL_OBJ)
	@$(LIBC) $(NAME) $(BON_OBJ) $(GNL_OBJ)

clean: 
	@$(RM) $(OBJS) $(BON_OBJ) $(GNL_OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
