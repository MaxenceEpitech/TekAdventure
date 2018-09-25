/*
** planet.h for tekadventure in /home/jean-baptiste/Projets/Semestre2/Graphical/tekadventure/jb_planet
** 
** Made by jean-baptiste
** Login   <jean-baptiste.melet@epitech.eu>
** 
** Started on  Tue Aug 29 11:40:27 2017 jean-baptiste
** Last update Thu Aug 31 11:40:32 2017 jean-baptiste
*/

#define MAP "sprites/space_map/old_starmap.png"
#define HUD "sprites/space_map/hud_starmap.png"
#define BROWN "sprites/space_map/planet_brown.png"
#define GREEN "sprites/space_map/planet_green.png"
#define LBROWN "sprites/space_map/planet_light_brown.png"
#define ORANGE "sprites/space_map/planet_orange_craters.png"
#define PINKISH "sprites/space_map/planet_pinkish_yellow.png"
#define PINK "sprites/space_map/planet_pink.png"
#define RED1 "sprites/space_map/planet_red1.png"
#define RED2 "sprites/space_map/planet_red2.png"
#define BLUE_RING "sprites/space_map/planet_rings_blue.png"
#define RED_RING "sprites/space_map/planet_rings_orange.png"
#define YELLOW "sprites/space_map/planet_yellow.png"
#define SUN "sprites/space_map/sun.png"

#include <SFML/Graphics.h>

typedef struct		s_my_planets
{
  sfSprite		**spr;
  sfTexture		**tex;
  sfVector2f		*pos;
}			t_my_planets;

#include "tek.h"

int		my_planets(t_my_planets *);
int		place_planets(t_materials *);
