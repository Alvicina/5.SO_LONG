/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:48:03 by alvicina          #+#    #+#             */
/*   Updated: 2023/11/17 15:48:57 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_second_read_map(char *argv, int total, t_vars *vars)
{
	int		fd2;
	ssize_t	nb_bytes;

	fd2 = open(argv, O_RDONLY);
	if (fd2 == -1)
		return (0);
	vars->map1 = malloc(total + 2);
	if (vars->len_map == 0)
		return (0);
	nb_bytes = read (fd2, vars->map1, total);
	if (nb_bytes == -1)
		return (0);
	if (vars->map1[total - 1] != '\n')
	{
		vars->map1[total] = '\n';
		vars->map1[total + 1] = 0;
	}
	else
		vars->map1[total] = 0;
	if (close(fd2) == -1)
		return (0);
	return (vars->map1);
}

char	*ft_read(int fd, char *argv, t_vars *vars)
{
	int		partial;
	int		total;
	char	buf[1];

	partial = 1;
	total = 0;
	while (partial > 0)
	{
		partial = read (fd, buf, 1);
		if (partial == -1)
			return (0);
		total = total + partial;
	}
	if (close (fd) == -1)
		return (0);
	vars->len_map = total;
	return (ft_second_read_map(argv, total, vars));
}

char	*ft_open_map(char *argv, t_vars *vars)
{
	int	fd;

	fd = open (argv, O_RDONLY);
	if (fd == -1)
		return (0);
	return (ft_read(fd, argv, vars));
}

int	ft_check_arg(char *argv)
{
	int	len_arg;

	len_arg = ft_strlen(argv);
	if (len_arg < 5)
		return (-1);
	else if (argv[len_arg - 1] != 'r' || argv[len_arg - 2] != 'e'
		|| argv[len_arg - 3] != 'b' || argv[len_arg - 4] != '.')
		return (-1);
	return (len_arg);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	vars.moves = 0;
	vars.exit = 0;
	vars.position = 0;
	vars.collect = 0;
	if (argc != 2)
		return (write(2, "Error: introduzca mapa\n", 24));
	if (ft_check_arg(argv[1]) == -1)
		return (write(2, "Error: Archivo no valido\n", 26));
	vars.map1 = ft_open_map(argv[1], &vars);
	if (vars.map1 == 0)
		return (write(2, "Error al leer / introducir mapa", 31));
	if (ft_checkmap_form(&vars) == -1)
		return (write(2, "Error: Mapa no valido\n", 23));
	if (ft_count_lines(&vars) == -1)
		return (write(2, "Error: Mapa no valido\n", 23));
	ft_start_window(&vars);
	mlx_hook(vars.window, 2, 0, ft_keyhook, &vars);
	mlx_hook(vars.window, 17, 0, ft_exit_rb, &vars);
	mlx_loop(vars.mlx);
}
