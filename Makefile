NAME = cub3D
CFLAGS = -g -O2 -Wall -Werror -Wextra

HEADERS = file_config.h utils.h cub3d.h file_config_bonus.h cub3d_bonus.h
HEADER_DIR = include/
HEADER = $(addprefix $(HEADER_DIR), $(HEADERS))
INCLUDE = -I $(HEADER_DIR)

LIBCC_DIR = lib/
LIBMLX_DIR = minilibx-linux/
LIBCC_LINK = -lcc
LIBMLX_LINL = -lmlx -lX11 -lXext
LINK = -L. $(LIBMLX_LINL) -lm $(LIBCC_LINK)

SRCS = validation/check_map_borders.c validation/check_map_closed.c \
	   validation/check_start_position.c validation/complete_cub_map.c \
	   validation/init_cub_map.c validation/validate_args.c \
	   validation/validate_color.c validation/validate_line.c \
	   validation/validate_map.c validation/validate_map_line.c \
	   validation/validate_params.c validation/validate_resolution.c \
	   validation/validate_texture.c validation/validation.c \
	   \
	   utils/copy_char_matrix.c utils/destroy_char_matrix.c \
	   utils/free_parse.c utils/ft_contains_only.c \
	   utils/ft_delete_ws.c utils/ft_error.c \
	   utils/get_hex_rgb.c utils/init_params.c \
	   utils/free_cub.c utils/init_cub_params.c \
	   utils/init_image.c \
	   \
	   engine/init_cub.c engine/init_mlx.c \
	   engine/init_pos.c engine/init_textures.c \
	   engine/init_sprites.c engine/init_buffer.c \
	   engine/cub.c engine/exit.c \
	   engine/rotation.c engine/movement.c \
	   engine/raycasting.c engine/drawing.c \
	   engine/spritecasting.c engine/sprite_utils.c \
	   engine/hooks.c engine/bmp.c \
	   \
	   main.c
SRC_DIR = src/base/
SRC = $(addprefix $(SRC_DIR), $(SRCS))
OBJS = $(SRC:.c=.o)
OBJ_DIR = ./
OBJ = $(addprefix $(OBJ_DIR), $(OBJS))

SRCS_BONUS = validation/check_map_borders_bonus.c validation/check_map_closed_bonus.c \
	   validation/check_start_position_bonus.c validation/complete_cub_map_bonus.c \
	   validation/init_cub_map_bonus.c validation/validate_args_bonus.c \
	   validation/validate_line_bonus.c validation/validate_map_bonus.c \
	   validation/validate_map_line_bonus.c validation/validate_params_bonus.c \
	   validation/validate_resolution_bonus.c validation/validate_texture_bonus.c \
	   validation/validation_bonus.c \
	   \
	   utils/copy_char_matrix_bonus.c utils/destroy_char_matrix_bonus.c \
	   utils/free_parse_bonus.c utils/ft_contains_only_bonus.c \
	   utils/ft_delete_ws_bonus.c utils/ft_error_bonus.c \
	   utils/get_hex_rgb_bonus.c utils/init_params_bonus.c \
	   utils/free_cub_bonus.c utils/init_cub_params_bonus.c \
	   utils/init_image_bonus.c \
	   \
	   engine/init_cub_bonus.c engine/init_mlx_bonus.c \
	   engine/init_pos_bonus.c engine/init_textures_bonus.c \
	   engine/init_sprites_bonus.c engine/init_buffer_bonus.c \
	   engine/cub_bonus.c engine/exit_bonus.c \
	   engine/rotation_bonus.c engine/movement_bonus.c \
	   engine/raycasting_bonus.c engine/drawing_bonus.c \
	   engine/spritecasting_bonus.c engine/sprite_utils_bonus.c \
	   engine/celling_floor_bonus.c engine/hooks_bonus.c \
	   engine/bmp_bonus.c \
	   \
	   main.c
SRC_BONUS_DIR = src/bonus/
SRC_BONUS = $(addprefix $(SRC_BONUS_DIR), $(SRCS_BONUS))
OBJS_BONUS = $(SRC_BONUS:.c=.o)
OBJ_BONUS_DIR = ./
OBJ_BONUS = $(addprefix $(OBJ_BONUS_DIR), $(OBJS_BONUS))

all : $(NAME)

bonus : $(OBJ_BONUS)
	@$(MAKE) all -C $(LIBCC_DIR)
	@cp $(LIBCC_DIR)libcc.a ./
	@$(MAKE) all -C $(LIBMLX_DIR)
	@cp $(LIBMLX_DIR)libmlx.a ./
	@gcc $(CFLAGS) $(OBJ_BONUS) $(LINK) -o $(NAME)

$(NAME) : $(OBJ)
	@$(MAKE) all -C $(LIBCC_DIR)
	@cp $(LIBCC_DIR)libcc.a ./
	@$(MAKE) all -C $(LIBMLX_DIR)
	@cp $(LIBMLX_DIR)libmlx.a ./
	@gcc $(CFLAGS) $(OBJ) $(LINK) -o $(NAME)

%.o : %.c $(HEADER)
	gcc $(CFLAGS) $(INCLUDE) -c $< -o $@

clean :
	@$(MAKE) clean -C $(LIBCC_DIR)
	@$(MAKE) clean -C $(LIBMLX_DIR)
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_BONUS)

fclean : clean
	@$(MAKE) fclean -C $(LIBCC_DIR)
	@$(MAKE) fclean -C $(LIBMLX_DIR)
	@rm -rf libcc.a libmlx.a $(NAME)

re : fclean all

norme :
	norminette include/* src/*/*/* lib/*.c lib/*.h src/*/*.c

.PHONY : all clean fclean re norme
