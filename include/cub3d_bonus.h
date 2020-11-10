/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 18:28:28 by wupdegra          #+#    #+#             */
/*   Updated: 2020/09/03 21:12:38 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <file_config_bonus.h>
# include "../minilibx-linux/include/mlx.h"
# include <sys/stat.h>

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ARROW_LEFT 65361
# define KEY_ARROW_RIGHT 65363
# define KEY_ARROW_UP 65362
# define KEY_ARROW_DOWN 65364
# define KEY_ESC 65307

# define MOVEMENT_SPEED 0.11
# define ROTATION_SPEED 0.06

# define T_WIDTH 64
# define T_HEIGHT 64

# define DARK 1

typedef	struct	s_img
{
	void	*img_ptr;
	int		bit_per_pix;
	int		size_line;
	int		endian;
	int		*data;
	int		width;
	int		height;
}				t_img;

typedef	struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}				t_mlx;

typedef	enum	e_orient
{
	North = 0,
	South,
	West,
	East
}				t_orient;

typedef	struct	s_sprite
{
	double	x;
	double	y;
	double	dist;
}				t_sprite;

typedef struct	s_rgb
{
	int			red;
	int			green;
	int			blue;
	int			hex_v;
}				t_rgb;

typedef	struct	s_bmp
{
	char	signature[2];
	int		file_size;
	int		reserved;
	int		data_offset;
	int		header_size;
	int		width;
	int		height;
	short	planes;
	short	bpp;
	int		compression;
	int		img_size;
	int		x_ppm;
	int		y_ppm;
	int		color_used;
	int		color_important;
	int		color;
}				t_bmp;

typedef	struct	s_app
{
	t_mlx			mlx;
	size_t			width;
	size_t			height;
	int				**texture;
	char			**cub_map;
	size_t			map_w;
	size_t			map_h;
	bool			save;
	int				**buff;

	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perpendicular;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;

	int				tex_x;
	int				tex_y;
	t_orient		tex_orient;
	double			tex_wall_x;
	double			tex_step;
	double			tex_pos;
	int				tex_color;

	double			*z_buff;
	size_t			sprite_count;
	t_sprite		*sprite;
	int				*s_order;
	double			sprite_ray_x;
	double			sprite_ray_y;
	double			sprite_inv_det;
	double			sprite_ray_trans_x;
	double			sprite_ray_trans_y;
	int				sprite_ray_screen_x;
	int				sprite_ray_v_screen;
	int				sprite_ray_width;
	int				sprite_ray_height;
	int				sprite_ray_draw_start_x;
	int				sprite_ray_draw_start_y;
	int				sprite_ray_draw_end_x;
	int				sprite_ray_draw_end_y;
	int				sprite_ray_tex_x;
	int				sprite_ray_tex_y;

	double			cf_ray_dir_x0;
	double			cf_ray_dir_y0;
	double			cf_ray_dir_x1;
	double			cf_ray_dir_y1;
	int				cf_pos;
	double			cf_pos_z;
	double			cf_row_dist;
	double			cf_floor_step_x;
	double			cf_floor_step_y;
	double			cf_floor_x;
	double			cf_floor_y;
	int				cf_cell_x;
	int				cf_cell_y;
	int				cf_tex_x;
	int				cf_tex_y;
	int				cf_color;

	t_bmp			bmp;
}				t_app;

void			init_cub(t_app *app, t_config *params);
void			init_mlx(t_app *app);
void			init_pos(t_app *app, t_config *params);
void			init_textures(t_app *app, t_config *params);
int				image_loader(t_app *app, int **texure, char *path);
void			init_sprites(t_app *app, t_config *params);
void			count_sprites(t_app *app, t_config *params);
void			set_sprites(t_app *app, t_config *params);
void			init_buffer(t_app *app, t_config *params);
int				movement(int keycode, t_app *app);
void			forward(t_app *app);
void			back(t_app *app);
void			left(t_app *app);
void			right(t_app *app);
void			rotation(t_app *app, bool is_right);
void			hooks(t_app *app);
int				exit_cub(t_app *app);
int				cub(t_app *app);
int				dim(int color, double dist);
void			cf_casting(t_app *app);
void			raycasting(t_app *app);
t_orient		choose_texture_orient(int side);
void			fill_buffer(t_app *app, int x);
void			spritecasting(t_app *app);
void			get_sprite_dist(t_app *app);
void			sort_sprites(t_app *app);
void			drawing(t_app *app);
void			save_screen(t_app *app);

#endif
