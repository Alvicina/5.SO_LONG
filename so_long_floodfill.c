/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_floodfill.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:07:58 by alvicina          #+#    #+#             */
/*   Updated: 2023/11/15 13:09:41 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_revert_flood_fill(t_vars *vars)
{
	ft_init_vars(vars);
	while (vars->str[vars->i])
	{
		vars->j = 0;
		while (vars->str[vars->i][vars->j] != 0)
		{
			if (vars->str[vars->i][vars->j] >= 'P')
				vars->str[vars->i][vars->j] = vars->str[vars->i][vars->j] - 40;
			vars->j++;
		}
		vars->i++;
	}
}

int	ft_check_flood_fill(t_vars *vars, int x, int y)
{
	ft_init_vars(vars);
	if (vars->str[x][y] == 'E')
		return (-1);
	while (vars->str[vars->i])
	{
		vars->j = 0;
		while (vars->str[vars->i][vars->j] != 0)
		{
			if (vars->str[vars->i][vars->j] == 'C')
				return (-1);
			vars->j++;
		}
		vars->i++;
	}
	ft_revert_flood_fill(vars);
	return (0);
}

void	ft_flood_fill(t_vars *vars, int x, int y)
{
	if (vars->str[x][y] != '1' && vars->str[x][y] <= 'P')
	{
		vars->str[x][y] = vars->str[x][y] + 40;
		ft_flood_fill(vars, x, y + 1);
		ft_flood_fill(vars, x, y - 1);
		ft_flood_fill(vars, x + 1, y);
		ft_flood_fill(vars, x - 1, y);
	}
}

int	ft_checkmap_path_findexit(t_vars *vars)
{
	ft_init_vars(vars);
	while (vars->str[vars->i])
	{
		vars->j = 0;
		while (vars->str[vars->i][vars->j] != 'E'
			&& vars->str[vars->i][vars->j] != 0)
			vars->j++;
		if (vars->str[vars->i][vars->j] == 'E')
		{
			vars->x_exit = vars->i;
			vars->y_exit = vars->j;
		}
		vars->i++;
	}
	ft_flood_fill(vars, vars->x_position, vars->y_position);
	return (ft_check_flood_fill(vars, vars->x_exit, vars->y_exit));
}

int	ft_checkmap_path_findpos(t_vars *vars)
{
	ft_init_vars(vars);
	while (vars->str[vars->i])
	{
		vars->j = 0;
		while (vars->str[vars->i][vars->j] != 'P'
			&& vars->str[vars->i][vars->j] != 0)
			vars->j++;
		if (vars->str[vars->i][vars->j] == 'P')
		{
			vars->x_position = vars->i;
			vars->y_position = vars->j;
		}
		vars->i++;
	}
	return (ft_checkmap_path_findexit(vars));
}
