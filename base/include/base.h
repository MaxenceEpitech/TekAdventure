/*
** base.h for Project-Master in /home/camille/semestre2/tekadventure/base
** 
** Made by camille
** Login   <camille.arbault@epitech.eu>
** 
** Started on  Wed Oct  4 09:21:39 2017 camille
** Last update Sun Oct  8 17:10:41 2017 camille
*/

#ifndef BASE_H_
# define BASE_H_

# include "tek.h"

# define BASE_DAY "sprites/base/base_day.png"
# define BASE_NIGHT "sprites/base/base_night.png"
# define DASHBOARD "sprites/base/dashboard_base.png"
# define DASH_STAY "sprites/base/dashboard_stay.png"
# define DASH_TRAVEL "sprites/base/dashboard_travel.png"
# define DEC "sprites/base/dec_proceed.png"
# define DEC_COMPLETE "sprites/base/dec_complete.png"
# define DEC_IMP "sprites/base/dec_impossible.png"
# define RESTED "sprites/base/rested.png"
# define RESTING "sprites/base/resting.png"
# define SCAN "sprites/base/scanning.png"
# define SCAN_OK "sprites/base/scan_ok.png"
# define SCAN_ERR1 "sprites/base/test_error_1.png"
# define SCAN_ERR2 "sprites/base/test_error_2.png"
# define TEST "sprites/base/test.png"
# define TEST_NO "sprites/base/test_no.png"
# define TEST_YES "sprites/base/test_yes.png"
# define RADIOAC "sprites/base/warning.png"
# define DEC_YES "sprites/base/dec_choice_y.png"
# define DEC_NO "sprites/base/dec_choice_n.png"
# define DEC_P1 "sprites/base/dec_p1.png"
# define DEC_P2 "sprites/base/dec_p2.png"
# define FADE_BLACK "sprites/base/fade_to_black.png"

# define BASE_LEFT "sprites/base/left.png"
# define BASE_RIGHT "sprites/base/right.png"
# define LEFT_TO_RIGHT "sprites/base/left_to_right/left_to_right"
# define RIGHT_TO_LEFT "sprites/base/right_to_left/right_to_left"
# define LTR_TOTAL 63

# define INT_DASH 1
# define INT_BED 2
# define INT_DECPOD 3
# define INT_COMP 4
# define INT_CONSOLE 5
# define INT_DOOR 6
# define INT_LEFT 7
# define INT_RIGHT 8

typedef struct		s_base
{
  sfTexture		**tex;
  sfSprite		**spr;
  sfSprite		**ltr;
  sfSprite		**rtl;
  char			side;
  sfVector2f		bg;
  sfVector2f		player;
  int			warning;
  int			*pos;
  sfFloatRect		*coords;
}			t_base;

/*
** gif handling
*/

char		*my_revstr(char *);
char		*my_int_to_str(int);
char		*new_cat(char *, char *);
sfSprite	**create_gif(char *, int);

/*
** base preparation
*/

t_base		*init_sprites_base(t_base *);
sfSprite	**load_spr_base(sfSprite **, sfTexture **);
sfTexture	**load_tex_base(sfTexture **);
sfTexture	**load_rest_textures(sfTexture **);
t_base		*init_coords_base(t_base *);
void		load_base(t_materials *);

/*
** start and interactions
*/

sfIntRect	my_rect(int, int, int, int);
void		start_base(t_materials *, t_base *);
int		get_base_action(t_materials *, t_base *);
void		use_dashboard(t_materials *, t_base *);
void		use_bed(t_materials *, t_base *);
void		decontamination_pod(t_materials *, t_base *);
void		use_computer(t_materials *, t_base *);

/*
** side movements
*/

void		base_movements(t_materials *, t_base *);
void		move_base_left(t_materials *, t_base *);
void		move_base_right(t_materials *, t_base *);
void		display_base(t_materials *, t_base *);
void		turn_around(t_materials *, t_base *, char);

#endif /* !BASE_H_ */
