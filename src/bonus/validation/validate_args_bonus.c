/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wupdegra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 15:52:28 by wupdegra          #+#    #+#             */
/*   Updated: 2020/09/03 19:10:50 by wupdegra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file_config_bonus.h>

void	validate_args(int argc, char **argv)
{
	int		fd;
	char	*dot_pos;

	if (argc < 2 || argc > 3)
		ft_error("Invalid count of arguments!\n");
	dot_pos = ft_strrchr(argv[1], '.');
	if (!dot_pos)
		ft_error("Invalid file name!\n");
	if (ft_strcmp(dot_pos, ".cub"))
		ft_error("Invalid file extension!\n");
	if (argc == 3 && ft_strcmp(argv[2], "--save"))
		ft_error("Invalid option!\n");
	fd = open(argv[1], O_RDONLY);
	if (fd < 1)
		ft_error("Can't open this file!\n");
	close(fd);
}
