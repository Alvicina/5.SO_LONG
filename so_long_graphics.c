/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_graphics.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:50:13 by alvicina          #+#    #+#             */
/*   Updated: 2023/11/20 10:42:34 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_keyhook(int keycode, t_vars *vars)
{
	ft_init_vars(vars);
	if (keycode == 53)
		ft_exit_rb(vars);
	if (keycode == 2 || keycode == 124)
		if (vars->str[vars->x_position][vars->y_position + 1] != 1)
			ft_move_right(vars);
	if (keycode == 1 || keycode == 125)
		if (vars->str[vars->x_position + 1][vars->y_position] != 1)
			ft_move_down(vars);
	if (keycode == 0 || keycode == 123)
		if (vars->str[vars->x_position][vars->y_position - 1] != 1)
			ft_move_left(vars);
	if (keycode == 13 || keycode == 126)
		if (vars->str[vars->x_position - 1][vars->y_position] != 1)
			ft_move_up(vars);
	mlx_clear_window(vars->mlx, vars->window);
	ft_render_window(vars);
	return (0);
}

int	ft_exit_rb(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->window);
	free(vars->str);
	free(vars->map1);
	exit (0);
}

void	ft_put_image_window(t_vars *vars)
{
	if (vars->str[vars->i][vars->j] == '1')
		mlx_put_image_to_window(vars->mlx, vars->window, vars->wall,
			vars->y, vars->c);
	else if (vars->str[vars->i][vars->j] == '0')
		mlx_put_image_to_window(vars->mlx, vars->window, vars->path,
			vars->y, vars->c);
	else if (vars->str[vars->i][vars->j] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->window, vars->money,
			vars->y, vars->c);
	else if (vars->str[vars->i][vars->j] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->window, vars->person,
			vars->y, vars->c);
	else if (vars->str[vars->i][vars->j] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->window, vars->out,
			vars->y, vars->c);
}

void	ft_render_window(t_vars *vars)
{
	ft_init_vars(vars);
	vars->c = -50;
	while (vars->str[vars->i])
	{
		vars->j = 0;
		vars->c = vars->c + 50;
		vars->y = 0;
		while (vars->str[vars->i][vars->j])
		{
			ft_put_image_window(vars);
			vars->y = vars->y + 50;
			vars->j++;
		}
		vars->i++;
	}
}

void	ft_start_window(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->img_width = 50;
	vars->img_height = 50;
	vars->window = mlx_new_window(vars->mlx, vars->img_width * vars->width,
			vars->img_height * vars->num_lines, "SO_LONG");
	vars->out = mlx_xpm_file_to_image(vars->mlx, "./textures/exit.xpm",
			&vars->img_width, &vars->img_height);
	vars->path = mlx_xpm_file_to_image(vars->mlx, "./textures/free.xpm",
			&vars->img_width, &vars->img_height);
	vars->money = mlx_xpm_file_to_image(vars->mlx, "./textures/me3.xpm",
			&vars->img_width, &vars->img_height);
	vars->person = mlx_xpm_file_to_image(vars->mlx, "./textures/me4.xpm",
			&vars->img_width, &vars->img_height);
	vars->wall = mlx_xpm_file_to_image(vars->mlx, "./textures/wall (1).xpm",
			&vars->img_width, &vars->img_height);
	ft_render_window(vars);
}
