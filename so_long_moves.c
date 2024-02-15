/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:37:39 by alvicina          #+#    #+#             */
/*   Updated: 2023/11/15 16:39:26 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_moves(t_vars *vars)
{
	int	fd;

	fd = 1;
	vars->moves = vars->moves + 1;
	write(1, "Moves:", 6);
	ft_putnbr_fd(vars->moves, fd);
	write(1, "\n", 1);
}

void	ft_move_right(t_vars *vars)
{
	if (vars->str[vars->x_exit][vars->y_exit] == 'P'
		&& vars->str[vars->x_position][vars->y_position + 1] != 1)
	{
		if (vars->str[vars->x_position][vars->y_position + 1] == 'C')
		vars->collect--;
		ft_change_exit2(&vars->str[vars->x_exit][vars->y_exit],
			&vars->str[vars->x_position][vars->y_position + 1]);
		vars->y_position = vars->y_position + 1;
		ft_print_moves(vars);
	}
	else if (vars->str[vars->x_position][vars->y_position + 1] == 'E'
		&& vars->collect == 0)
	{
		ft_print_moves(vars);
		ft_exit_rb(vars);
	}
	else if (vars->str[vars->x_position][vars->y_position + 1] != '1')
	{
		if (vars->str[vars->x_position][vars->y_position + 1] == 'C')
			vars->collect--;
		ft_change_img(&(vars->str[vars->x_position][vars->y_position]),
			&(vars->str[vars->x_position][vars->y_position + 1]));
		vars->y_position = vars->y_position + 1;
		ft_print_moves(vars);
	}	
}

void	ft_move_down(t_vars *vars)
{
	if (vars->str[vars->x_exit][vars->y_exit] == 'P'
		&& vars->str[vars->x_position + 1][vars->y_position] != 1)
	{
		if (vars->str[vars->x_position + 1][vars->y_position] == 'C')
		vars->collect--;
		ft_change_exit2(&vars->str[vars->x_exit][vars->y_exit],
			&vars->str[vars->x_position + 1][vars->y_position]);
		vars->x_position = vars->x_position + 1;
		ft_print_moves(vars);
	}
	else if (vars->str[vars->x_position + 1][vars->y_position] == 'E'
		&& vars->collect == 0)
	{
		ft_print_moves(vars);
		ft_exit_rb(vars);
	}
	else if (vars->str[vars->x_position + 1][vars->y_position] != '1')
	{
		if (vars->str[vars->x_position + 1][vars->y_position] == 'C')
			vars->collect--;
		ft_change_img(&(vars->str[vars->x_position][vars->y_position]),
			&(vars->str[vars->x_position + 1][vars->y_position]));
		vars->x_position = vars->x_position + 1;
		ft_print_moves(vars);
	}
}

void	ft_move_left(t_vars *vars)
{
	if (vars->str[vars->x_exit][vars->y_exit] == 'P'
		&& vars->str[vars->x_position][vars->y_position - 1] != 1)
	{
		if (vars->str[vars->x_position][vars->y_position - 1] == 'C')
		vars->collect--;
		ft_change_exit2(&vars->str[vars->x_exit][vars->y_exit],
			&vars->str[vars->x_position][vars->y_position - 1]);
		vars->y_position = vars->y_position - 1;
		ft_print_moves(vars);
	}
	else if (vars->str[vars->x_position][vars->y_position - 1] == 'E'
		&& vars->collect == 0)
	{
		ft_print_moves(vars);
		ft_exit_rb(vars);
	}
	else if (vars->str[vars->x_position][vars->y_position - 1] != '1')
	{
		if (vars->str[vars->x_position][vars->y_position - 1] == 'C')
			vars->collect--;
		ft_change_img(&(vars->str[vars->x_position][vars->y_position]),
			&(vars->str[vars->x_position][vars->y_position - 1]));
		vars->y_position = vars->y_position - 1;
		ft_print_moves(vars);
	}
}

void	ft_move_up(t_vars *vars)
{
	if (vars->str[vars->x_exit][vars->y_exit] == 'P'
		&& vars->str[vars->x_position - 1][vars->y_position] != 1)
	{
		if (vars->str[vars->x_position - 1][vars->y_position] == 'C')
		vars->collect--;
		ft_change_exit2(&vars->str[vars->x_exit][vars->y_exit],
			&vars->str[vars->x_position - 1][vars->y_position]);
		vars->x_position = vars->x_position - 1;
		ft_print_moves(vars);
	}
	else if (vars->str[vars->x_position - 1][vars->y_position] == 'E'
		&& vars->collect == 0)
	{
		ft_print_moves(vars);
		ft_exit_rb(vars);
	}
	else if (vars->str[vars->x_position - 1][vars->y_position] != '1')
	{
		if (vars->str[vars->x_position - 1][vars->y_position] == 'C')
			vars->collect--;
		ft_change_img(&(vars->str[vars->x_position][vars->y_position]),
			&(vars->str[vars->x_position - 1][vars->y_position]));
		vars->x_position = vars->x_position - 1;
		ft_print_moves(vars);
	}
}
