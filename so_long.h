/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:14:41 by alvicina          #+#    #+#             */
/*   Updated: 2023/11/24 10:00:47 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>
# include "./mlx/mlx.h"

typedef struct s_vars{
	int		len_map;
	char	*map1;
	char	**str;
	ssize_t	num_lines;
	int		i;
	int		j;
	ssize_t	c;
	ssize_t	y;
	ssize_t	width;
	int		collect;
	int		exit;
	int		position;
	int		x_position;
	int		y_position;
	int		x_exit;
	int		y_exit;
	void	*window;
	void	*mlx;
	void	*wall;
	void	*person;
	void	*money;
	void	*path;
	void	*out;
	int		img_width;
	int		img_height;
	int		moves;
	int		total;
}	t_vars;

size_t	ft_strlen(const char *s);
int		ft_count_lines(t_vars *vars);
int		ft_put_lines(t_vars *vars);
void	ft_init_vars(t_vars *vars);
int		ft_checkmap_wall(t_vars *vars);
int		ft_checkmap_form(t_vars *vars);
int		ft_mapcheck_malloc_error(void);
int		ft_checkmap_comps(t_vars *vars);
int		ft_checkmap_num_comps(t_vars *vars);
int		ft_checkmap_path_findpos(t_vars *vars);
int		ft_checkmap_path_findexit(t_vars *vars);
void	ft_flood_fill(t_vars *vars, int x, int y);
int		ft_check_flood_fill(t_vars *vars, int x, int y);
void	ft_revert_flood_fill(t_vars *vars);
void	ft_render_window(t_vars *vars);
void	ft_start_window(t_vars *vars);
void	ft_put_image_window(t_vars *vars);
int		ft_exit_rb(t_vars *vars);
int		ft_keyhook(int keycode, t_vars *vars);
void	ft_move_right(t_vars *vars);
void	ft_move_down(t_vars *vars);
void	ft_move_left(t_vars *vars);
void	ft_move_up(t_vars *vars);
void	ft_change_img(char *x, char *y);
void	ft_change_exit(char *x, char *y);
void	ft_change_exit2(char *x, char *y);
void	ft_print_moves(t_vars *vars);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif