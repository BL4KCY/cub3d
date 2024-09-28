#include "cub3d.h"


void	set_pistol_path(t_weapon *weapon)
{
	weapon->img[0].path = "textures/firstPerson/attack-pistol/1.xpm";
	weapon->img[1].path = "textures/firstPerson/attack-pistol/2.xpm";
	weapon->img[2].path = "textures/firstPerson/attack-pistol/3.xpm";
	weapon->img[3].path = "textures/firstPerson/attack-pistol/4.xpm";
	weapon->img[4].path = "textures/firstPerson/attack-pistol/5.xpm";
	weapon->img[5].path = "textures/firstPerson/attack-pistol/6.xpm";
	weapon->img[6].path = "textures/firstPerson/attack-pistol/7.xpm";
	weapon->img[7].path = "textures/firstPerson/attack-pistol/8.xpm";
	weapon->img[8].path = "textures/firstPerson/attack-pistol/9.xpm";
	weapon->img[9].path = "textures/firstPerson/attack-pistol/10.xpm";
	weapon->img[10].path = "textures/firstPerson/attack-pistol/11.xpm";
	weapon->img[11].path = "textures/firstPerson/attack-pistol/12.xpm";
	weapon->img[12].path = "textures/firstPerson/attack-pistol/13.xpm";
}


t_weapon	init_pistol(void)
{
	t_weapon	weapon;

	weapon.n_frames = PISTOL_FRAMES;
	weapon.img = ft_malloc(sizeof(t_img) * (weapon.n_frames));
	set_pistol_path(&weapon);
	weapon.is_aiming = false;
	weapon.is_shooting = false;
	weapon.is_whiping = false;
	weapon.is_kneeling = false;
	weapon.whiping_frame = 9;
	weapon.whiping_frame_max = 12;
	weapon.shooting_frame = 2;
	weapon.shooting_frame_max = 6;
	weapon.aiming_frame = 2;
	weapon.aiming_frame_max = 2;
	weapon.kneeling_frame = 0;
	weapon.kneeling_frame_max = 0;
	weapon.delay_frame = 100;
	return (weapon);
}

void	set_knife_path(t_weapon *weapon)
{
	weapon->img[0].path = "textures/firstPerson/attack-knifestab/1.xpm";
	weapon->img[1].path = "textures/firstPerson/attack-knifestab/2.xpm";
	weapon->img[2].path = "textures/firstPerson/attack-knifestab/3.xpm";
	weapon->img[3].path = "textures/firstPerson/attack-knifestab/4.xpm";
	weapon->img[4].path = "textures/firstPerson/attack-knifestab/5.xpm";
}

t_weapon	init_knife(void)
{
	t_weapon	weapon;

	weapon.n_frames = KNIFE_FRAMES;
	weapon.img = ft_malloc(sizeof(t_img) * (weapon.n_frames));
	set_knife_path(&weapon);
	weapon.is_aiming = false;
	weapon.is_shooting = false;
	weapon.shooting_frame = 2;
	weapon.shooting_frame_max = 3;
	weapon.aiming_frame = 2;
	weapon.aiming_frame_max = 2;
	weapon.delay_frame = 100;
	return (weapon);
}

void	set_hand_path(t_weapon *weapon)
{
	weapon->img[0].path = "textures/firstPerson/attack-punch/1.xpm";
	weapon->img[1].path = "textures/firstPerson/attack-punch/2.xpm";
	weapon->img[2].path = "textures/firstPerson/attack-punch/3.xpm";
	weapon->img[3].path = "textures/firstPerson/attack-punch/4.xpm";
	weapon->img[4].path = "textures/firstPerson/attack-punch/5.xpm";
	weapon->img[5].path = "textures/firstPerson/attack-punch/6.xpm";
	weapon->img[6].path = "textures/firstPerson/attack-punch/7.xpm";
	weapon->img[7].path = "textures/firstPerson/attack-punch/8.xpm";
	weapon->img[8].path = "textures/firstPerson/attack-punch/9.xpm";
	weapon->img[9].path = "textures/firstPerson/attack-punch/10.xpm";
	weapon->img[10].path = "textures/firstPerson/attack-punch/11.xpm";
	weapon->img[11].path = "textures/firstPerson/attack-punch/12.xpm";
	weapon->img[12].path = "textures/firstPerson/attack-punch/13.xpm";
	weapon->img[13].path = "textures/firstPerson/attack-punch/14.xpm";
	weapon->img[14].path = "textures/firstPerson/attack-punch/15.xpm";
	weapon->img[15].path = "textures/firstPerson/attack-punch/16.xpm";
	weapon->img[16].path = "textures/firstPerson/attack-punch/17.xpm";
	weapon->img[17].path = "textures/firstPerson/attack-punch/18.xpm";
	weapon->img[18].path = "textures/firstPerson/attack-punch/19.xpm";
	weapon->img[19].path = "textures/firstPerson/attack-punch/20.xpm";
	weapon->img[20].path = "textures/firstPerson/attack-punch/21.xpm";
	weapon->img[21].path = "textures/firstPerson/attack-punch/22.xpm";
	weapon->img[22].path = "textures/firstPerson/attack-punch/23.xpm";
}

t_weapon	init_hand(void)
{
	t_weapon	weapon;

	weapon.n_frames = 23;
	weapon.img = ft_malloc(sizeof(t_img) * (weapon.n_frames));
	set_hand_path(&weapon);
	weapon.is_aiming = false;
	weapon.is_shooting = false;
	weapon.is_whiping = false;
	weapon.is_kneeling = false;
	weapon.shooting_frame = 1;
	weapon.shooting_frame_max = 5;
	weapon.aiming_frame = 6;
	weapon.aiming_frame_max = 9;
	weapon.whiping_frame = 10;
	weapon.whiping_frame_max = 16;
	weapon.kneeling_frame = 18;
	weapon.kneeling_frame_max = 22;
	weapon.delay_frame = 100;
	return (weapon);
}

void	set_machinegun_path(t_weapon *weapon)
{
	weapon->img[0].path = "textures/firstPerson/attack-machinegun/1.xpm";
	weapon->img[1].path = "textures/firstPerson/attack-machinegun/2.xpm";
	weapon->img[2].path = "textures/firstPerson/attack-machinegun/3.xpm";
	weapon->img[3].path = "textures/firstPerson/attack-machinegun/4.xpm";
	weapon->img[4].path = "textures/firstPerson/attack-machinegun/5.xpm";
	weapon->img[5].path = "textures/firstPerson/attack-machinegun/6.xpm";
	weapon->img[6].path = "textures/firstPerson/attack-machinegun/7.xpm";
	weapon->img[7].path = "textures/firstPerson/attack-machinegun/8.xpm";
	weapon->img[8].path = "textures/firstPerson/attack-machinegun/9.xpm";
	weapon->img[9].path = "textures/firstPerson/attack-machinegun/10.xpm";
	weapon->img[10].path = "textures/firstPerson/attack-machinegun/11.xpm";
	weapon->img[11].path = "textures/firstPerson/attack-machinegun/12.xpm";
	weapon->img[12].path = "textures/firstPerson/attack-machinegun/13.xpm";
	weapon->img[13].path = "textures/firstPerson/attack-machinegun/14.xpm";
	weapon->img[14].path = "textures/firstPerson/attack-machinegun/15.xpm";
	weapon->img[15].path = "textures/firstPerson/attack-machinegun/16.xpm";
	weapon->img[16].path = "textures/firstPerson/attack-machinegun/17.xpm";
	weapon->img[17].path = "textures/firstPerson/attack-machinegun/18.xpm";
	weapon->img[18].path = "textures/firstPerson/attack-machinegun/19.xpm";
	weapon->img[19].path = "textures/firstPerson/attack-machinegun/20.xpm";
	weapon->img[20].path = "textures/firstPerson/attack-machinegun/21.xpm";
	weapon->img[21].path = "textures/firstPerson/attack-machinegun/22.xpm";
}
t_weapon	init_machinegun(void)
{
	t_weapon	weapon;

	weapon.n_frames = 22;
	weapon.img = ft_malloc(sizeof(t_img) * (weapon.n_frames));
	set_machinegun_path(&weapon);
	weapon.is_aiming = false;
	weapon.is_shooting = false;
	weapon.is_kneeling = false;
	weapon.is_guarding = false; 
	weapon.shooting_frame = 2;
	weapon.shooting_frame_max = 16;
	weapon.aiming_frame = 1;
	weapon.aiming_frame_max = 1;
	weapon.whiping_frame = 18;
	weapon.whiping_frame_max = 21;
	weapon.kneeling_frame = 0;
	weapon.kneeling_frame_max = 0;
	weapon.delay_frame = 100;
	return (weapon);
}

t_weapon	init_weapon(t_weapon_type type)
{
	if (type == PISTOL)
		return (init_pistol());
	if (type == KNIFE)
		return (init_knife());
	if (type == HAND)
		return (init_hand());
	if (type == MACHINEGUN)
		return (init_machinegun());
	return (init_pistol());
}