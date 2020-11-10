NAME = libcc.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -Os
HEADER_DIR = ./
INCLUDE = -I $(HEADER_DIR)
SRCS = ft_atoi.c ft_isdigit.c ft_isnumeric.c \
	   ft_lstadd_back.c ft_lstclear.c ft_lstdelone.c \
	   ft_lstnew.c ft_split.c ft_strchr.c \
	   ft_strcmp.c ft_strcpy.c ft_strdup.c \
	   ft_strjoin.c ft_strlen.c ft_strrchr.c \
	   ft_strtrim.c ft_memcpy.c \
	   ft_calloc.c ft_memset.c \
	   get_next_line.c
SRC_DIR = ./
SRC = $(addprefix $(SRC_DIR), $(SRCS))
OBJS = $(SRC:.c=.o)
OBJ_DIR = ./
OBJ = $(addprefix $(OBJ_DIR), $(OBJS))

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADER_DIR)lib.h
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

norme :
	norminette .

.PHONY : all clean fclean re norme
