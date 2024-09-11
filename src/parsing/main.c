#include "cub3d.h"

void	*get_info(void)
{
	static t_info	info;

	return (&info);
}

void	ft_exit_param(void)
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
		printf(RED_W "[Invalid]\n" RESET);
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
		ft_exit_param();
	i = argc - 1;
	if (!ft_strcmp(ft_strrchr(argv[1], '.'), ".cub") && argc == 2)
		condition->name = argv[1];
	else
		ft_give_prompt_back(i, argc, argv);
}

int	main(int argc, char **argv)
{
	t_info	*info;
	t_condition	condition;

	ft_parse_arguments(argc, argv, &condition);
	condition.substr = ft_create_two_dimensional_array(argv);
	
	if (move_on_if_map_valid(&condition) == false)
		return (EXIT_FAILURE);
	info = (t_info *)get_info();
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "cub3d");
	mlx_hook(info->win, ON_DESTROY, KEYPRESSMASK, ft_exit, info);
	mlx_hook(info->win, ON_KEYDOWN, KEYPRESSMASK, keypress, info);
	mlx_hook(info->win, ON_KEYUP, KEYRELEASEMASK, keyrelease, info);
	init_map(info);
	init_player(info);
	init_texture(info, &condition);
	mlx_loop_hook(info->mlx, rendering, info);
	mlx_loop(info->mlx);
	
	ft_hunt_leak();
	return (EXIT_SUCCESS);
}
