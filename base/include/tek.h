/*
** tek.h for tekadevnture in /home/JB.Melet/Projets/Semestre2/Graphical/
** 
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
** 
** Started on  Wed Aug  9 16:49:59 2017 JeanBaptiste Melet
** Last update Sun Oct  8 16:55:28 2017 camille
*/

#ifndef TEK_H_
# define TEK_H_

# include <SFML/System.h>
# include <SFML/Graphics.h>
# include <SFML/Audio.h>

# define WIDTH 1341
# define HEIGHT 700
# define WIN_TITLE "ENDLESS PSO"

# define ERROPEN "ERROR: Could not open file.\n"
# define ERRCLOSE "ERROR: Could not close file.\n"
# define ERRMLC "ERROR: Failed to allocate memory.\n"
# define ERRLOAD "ERROR: Failed to load file.\n"

# define SKY "sprites/blank_galaxy.png"
# define MENU "sprites/menu.png"
# define MENU_HELP "sprites/menu_help.png"
# define MENU_NEW "sprites/menu_new.png"
# define MENU_LOAD "sprites/menu_load.png"
# define MENU_OPT "sprites/menu_options.png"
# define MENU_Q "sprites/menu_quit.png"
# define OPTIONS "sprites/options.png"
# define HELP "sprites/help.png"
# define SOON "sprites/coming_soon.png"

# define MUSIC_BATTLE1 "music/battle_theme1.ogg"
# define MUSIC_ASTER "music/EO_below_the_asteroids.ogg"
# define MUSIC_CANTINA "music/cantina.ogg"
# define MUSIC_EPIC "music/menu_starmap.ogg"

# define INT_NEW 1
# define INT_LOAD 2
# define INT_HELP 3
# define INT_OPT 4
# define INT_QUIT 5

typedef struct	s_planet
{
  int	num;
  float	gravity;
  int	height;
}		t_planet;

typedef struct	s_my_framebuffer
{
  sfUint8	*pixels;
  int		width;
  int		height;
}		t_my_framebuffer;

typedef struct		s_materials
{
  sfRenderWindow	*wdw;
  sfSprite		**spr;
  sfTexture		**tex;
  sfMusic		**music;
  t_my_framebuffer	*fb;
  sfVector2i		mouse;
}			t_materials;

typedef struct	s_game
{
  int		pos_x;
  int		pos_y;
}		t_game;

/*
** game preparation
*/
sfSprite	**load_spr(sfSprite **, sfTexture **);
sfTexture	**load_tex(sfTexture **);
sfSprite	**load_astronaut(sfSprite **, sfTexture **);
sfSprite	**load_paralax(sfSprite **, sfTexture **);
sfTexture	**load_tex_astronaut(sfTexture **);
sfTexture	**load_tex_paralax(sfTexture **);
sfRenderWindow	*create_window(char *, int, int);
sfMusic		**load_music(sfMusic **);
t_materials	*prepare_game(t_materials *);
int		begin_game(t_materials *);
void		init_positions_fire_planet(t_materials *);

/*
** menu
*/
void	show_menu(t_materials *);
int	menu_what_to_display(sfVector2i, int, t_materials *);
int	draw_sprite_menu(int, int, t_materials *);
int	choice_menu(sfVector2i);
void	execute_choice_menu(int, t_materials *);
void	show_help(t_materials *);
void	show_options(t_materials *);
void	coming_soon(t_materials *);
void	start_game(t_materials *);
void	free_and_quit(t_materials *);

/*
** drawing functions
*/
sfUint8			*create_pixel_buffer(int, int);
t_my_framebuffer	*create_fbuffer(int, int);

void	my_put_pixel(t_my_framebuffer *, int, int, sfColor);
void	my_draw_line(t_my_framebuffer *, sfVector2i, sfVector2i, sfColor);

/*
** gameplay
*/
void	player_movement(t_materials *, int);
void	set_positions_fire_planet(t_materials *);
void	move_left(t_materials *, int);
void	move_right(t_materials *, int);
void	jump(t_materials *, t_planet *);
void	jump_upward(t_materials *, t_planet *);
void	jump_left(t_materials *, t_planet *);
void	jump_right(t_materials *, t_planet *);

/*
** display
*/
void	my_paralax_fire_planet(t_materials *);
void	my_paralax_fire_planet_movement(t_materials *);
void	display_fire_planet(t_materials *, int, char);
void	simple_display_fire_planet(t_materials *, char);
void	display_planet_noframes(t_materials *, t_planet *, char);
void	display_planet_frames(t_materials *, t_planet *, int, char);

#endif /* !TEK_H */
