/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:14:41 by mohammedmad       #+#    #+#             */
/*   Updated: 2024/09/11 12:16:05 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit(void)
{
	printf("Execute 'Cub3d' \n");
	exit(1);
}

void	ft_give_prompt_back(int i, int argc, char **argv)
{
	i = 1;
	while (i < argc)
		printf("%s\n", argv[i++]);
	exit(1);
}

bool	move_on_if_map_valid(t_condition *condition)
{
	if (condition->substr == NULL)
	{
		printf(RED "[Invalid]\n" RESET);
		ft_hunt_leak();
		return (false);
	}
	if (ft_grep_to_pars_if('.', condition, ft_to_do_texturs)
		&& ft_grep_to_pars_if(',', condition, ft_to_do_c_floor)
		&& ft_grep_to_pars_if('1', condition, ft_to_do_map))
	{
		printf(GRN_W "[Valid]\n" RESET);
	}
	else
	{
		printf(RED_W "[Invalid]\n" RESET);
		ft_hunt_leak();
		return (false);
	}
	return (true);
}

void	ft_parse_arguments(int argc, char **argv, t_condition *condition)
{
	int	i;

	if (argc == 1)
		ft_exit();
	i = argc - 1;
	if (!ft_strcmp(ft_strrchr(argv[1], '.'), ".cub") && argc == 2)
		condition->name = argv[1];
	else
		ft_give_prompt_back(i, argc, argv);
}

int	main(int argc, char **argv)
{
	t_condition	game_condition;

	ft_parse_arguments(argc, argv, &game_condition);
	game_condition.substr = ft_create_two_dimensional_array(argv);
	if (move_on_if_map_valid(&game_condition) == false)
		return (EXIT_FAILURE);
	ft_hunt_leak();
	return (EXIT_SUCCESS);
}
