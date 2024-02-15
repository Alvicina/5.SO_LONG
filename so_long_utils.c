/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:23:36 by alvicina          #+#    #+#             */
/*   Updated: 2023/11/17 15:44:14 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_mapcheck_malloc_error(void)
{
	write(2, "Error al alocar mapa para el chequeo", 36);
	return (-2);
}

int	ft_put_lines(t_vars *vars)
{
	size_t	i;
	int		j;

	i = 0;
	j = 1;
	vars->str[0] = vars->map1;
	while (j < vars->num_lines)
	{
		while (vars->map1[i] != '\n')
			i++;
		if (vars->map1[i] == '\n')
		{
			vars->map1[i] = 0;
			i++;
			vars->str[j] = &vars->map1[i];
		}
		j++;
	}
	return (ft_checkmap_wall(vars));
}

int	ft_count_lines(t_vars *vars)
{
	size_t	init;
	size_t	count;
	size_t	final;

	init = 0;
	final = 0;
	count = 0;
	while (vars->map1[init])
	{
		init = final;
		while (vars->map1[init] == '\n' && vars->map1[init] != 0)
			init++;
		if (vars->map1[init] != '\n' && vars->map1[init] != 0)
			count++;
		final = init;
		while (vars->map1[final] != '\n' && vars->map1[final] != 0)
			final++;
		init = final;
	}
	vars->str = malloc(sizeof (char *) * (count + 1));
	if (vars->str == 0)
		return (ft_mapcheck_malloc_error());
	vars->str[count] = 0;
	vars->num_lines = count;
	return (ft_put_lines(vars));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

void	ft_init_vars(t_vars *vars)
{
	vars->c = 0;
	vars->i = 0;
	vars->j = 0;
	vars->y = 0;
}
