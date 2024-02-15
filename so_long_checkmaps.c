/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_checkmaps.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:35:46 by alvicina          #+#    #+#             */
/*   Updated: 2023/11/17 16:24:37 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_checkmap_wall(t_vars *vars)
{
	ft_init_vars(vars);
	while (vars->str[vars->i])
	{
		if (vars->i == 0 || vars->i == vars->num_lines - 1)
		{
			while (vars->str[vars->i][vars->j] == '1')
				vars->j++;
			if (vars->j != vars->width)
				return (-1);
		}
		vars->j = 0;
		if (vars->i > 0 && vars->i < vars->num_lines - 1)
		{
			if (vars->str[vars->i][vars->j] != '1'
			|| (vars->str[vars->i][vars->width - 1] != '1'))
				return (-1);
		}
		vars->i++;
	}
	return (ft_checkmap_path_findpos(vars));
}

int	ft_checkmap_num_comps(t_vars *vars)
{
	if (vars->exit != 1 || vars->position != 1)
		return (-1);
	else if (vars->collect < 1)
		return (-1);
	else
		return (0);
}

int	ft_checkmap_comps(t_vars *vars)
{
	vars->i = 0;
	while (vars->i < vars->len_map)
	{
		if (vars->map1[vars->i] == '1' || vars->map1[vars->i] == '0'
			|| vars->map1[vars->i] == '\n')
			vars->i++;
		else if (vars->map1[vars->i] == 'C')
		{
			vars->i++;
			vars->collect++;
		}
		else if (vars->map1[vars->i] == 'E')
		{
			vars->i++;
			vars->exit++;
		}
		else if (vars->map1[vars->i] == 'P')
		{
			vars->i++;
			vars->position++;
		}
		else
			return (-1);
	}
	return (ft_checkmap_num_comps(vars));
}

int	ft_checkmap_form(t_vars *vars)
{
	ft_init_vars(vars);
	while (vars->map1[vars->i] != '\n' && vars->map1[vars->i] != 0)
		vars->i++;
	vars->width = vars->i;
	vars->i = 0;
	while (vars->i < vars->len_map + 1)
	{
		while (vars->map1[vars->i] != '\n' && vars->map1[vars->i] != 0)
		{
			vars->i++;
			vars->j++;
		}
		vars->i++;
		while (vars->map1[vars->i] != '\n' && vars->map1[vars->i] != 0)
		{
			vars->i++;
			vars->c++;
		}
		if (vars->j == vars->c || ((vars->map1[vars->i]) == 0
				&& (vars->j - vars->c) == vars->width))
			vars->i++;
		else
			return (-1);
	}
	return (ft_checkmap_comps(vars));
}
