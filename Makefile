##
## Makefile for makefile in /home/Max/Documents/delivery/CPE_year_Pushswap
## 
## Made by fourrier maxence
## Login   <maxence.fourrier@epitech.eu>
## 
## Started on  Tue Apr 11 10:05:45 2017 fourrier maxence
## Last update Sun Oct 15 09:40:23 2017 maxence.fourrier
##

NAME		= 	tekadv

CC		= 	gcc

RM		= 	rm -f

SRCS_DIR	= 	./src/

GRAPH_DIR	= 	./graph/

SRCS		=	$(GRAPH_DIR)graph.c			\
			$(GRAPH_DIR)tools.c			\
			$(SRCS_DIR)main.c			\
			$(SRCS_DIR)give_object.c		\
			$(SRCS_DIR)menu.c			\
			$(SRCS_DIR)give.c			\
			$(SRCS_DIR)death.c			\
			$(SRCS_DIR)init_sound.c			\
			$(SRCS_DIR)effect_intro.c		\
			$(SRCS_DIR)music_effect.c		\
			$(SRCS_DIR)fire_bird.c			\
			$(SRCS_DIR)draw_mob.c			\
			$(SRCS_DIR)draw_laser_tower.c		\
			$(SRCS_DIR)init_sprite_other.c		\
			$(SRCS_DIR)can_place_rock.c		\
			$(SRCS_DIR)music.c			\
			$(SRCS_DIR)music_module.c		\
			$(SRCS_DIR)intro.c			\
			$(SRCS_DIR)laser.c			\
			$(SRCS_DIR)draw_laser.c			\
			$(SRCS_DIR)check_config.c		\
			$(SRCS_DIR)can_place_lake.c		\
			$(SRCS_DIR)mine_rock.c			\
			$(SRCS_DIR)mob_utils.c			\
			$(SRCS_DIR)break_egg.c			\
			$(SRCS_DIR)mob.c			\
			$(SRCS_DIR)draw_env.c			\
			$(SRCS_DIR)env.c			\
			$(SRCS_DIR)mine.c			\
			$(SRCS_DIR)mine_time.c			\
			$(SRCS_DIR)storm.c			\
			$(SRCS_DIR)depth.c			\
			$(SRCS_DIR)item.c			\
			$(SRCS_DIR)draw_storm.c			\
			$(SRCS_DIR)clear_console.c		\
			$(SRCS_DIR)add_item_inv.c		\
			$(SRCS_DIR)storm_obj.c			\
			$(SRCS_DIR)help.c			\
			$(SRCS_DIR)fusion.c			\
			$(SRCS_DIR)draw_fusion.c		\
			$(SRCS_DIR)my_epurstr.c			\
			$(SRCS_DIR)my_str_to_wordtab.c		\
			$(SRCS_DIR)change_time.c		\
			$(SRCS_DIR)thread_console.c		\
			$(SRCS_DIR)chest.c			\
			$(SRCS_DIR)nuclear.c			\
			$(SRCS_DIR)draw_button_launcher.c	\
			$(SRCS_DIR)draw_nuclear.c		\
			$(SRCS_DIR)launcher.c			\
			$(SRCS_DIR)draw_launcher.c		\
			$(SRCS_DIR)conso_module.c		\
			$(SRCS_DIR)coal_utils.c			\
			$(SRCS_DIR)click_coal_utils.c		\
			$(SRCS_DIR)draw_chest.c			\
			$(SRCS_DIR)draw_hud.c			\
			$(SRCS_DIR)get_prod.c			\
			$(SRCS_DIR)gif.c			\
			$(SRCS_DIR)coal.c			\
			$(SRCS_DIR)draw_coal.c			\
			$(SRCS_DIR)check_can_place.c		\
			$(SRCS_DIR)draw_upgrade.c		\
			$(SRCS_DIR)draw_button.c		\
			$(SRCS_DIR)draw_base.c			\
			$(SRCS_DIR)click_upgrade.c		\
			$(SRCS_DIR)upgrade_base.c		\
			$(SRCS_DIR)init_gif.c			\
			$(SRCS_DIR)upgrade_utils.c		\
			$(SRCS_DIR)base.c			\
			$(SRCS_DIR)draw_solar_utils.c		\
			$(SRCS_DIR)solar.c			\
			$(SRCS_DIR)upgrade_solar.c		\
			$(SRCS_DIR)draw_solar.c			\
			$(SRCS_DIR)upgrade.c			\
			$(SRCS_DIR)draw_placed.c		\
			$(SRCS_DIR)regen.c			\
			$(SRCS_DIR)cursor.c			\
			$(SRCS_DIR)day_night.c			\
			$(SRCS_DIR)init_limit.c			\
			$(SRCS_DIR)day_night_utils.c		\
			$(SRCS_DIR)use_item.c			\
			$(SRCS_DIR)inventory_utils.c		\
			$(SRCS_DIR)init_circle.c		\
			$(SRCS_DIR)corner_change_id.c		\
			$(SRCS_DIR)module.c			\
			$(SRCS_DIR)change_map_id.c		\
			$(SRCS_DIR)craft_inv.c			\
			$(SRCS_DIR)draw_map.c			\
			$(SRCS_DIR)init_floor.c			\
			$(SRCS_DIR)check_inv.c			\
			$(SRCS_DIR)draw_craft_inv.c		\
			$(SRCS_DIR)draw_craft_inv_utils.c	\
			$(SRCS_DIR)init_craft_module.c		\
			$(SRCS_DIR)init_craft_module_other.c	\
			$(SRCS_DIR)init_craft_module_other_.c	\
			$(SRCS_DIR)placed_module.c		\
			$(SRCS_DIR)message.c			\
			$(SRCS_DIR)init_hud.c			\
			$(SRCS_DIR)gen_procedural.c		\
			$(SRCS_DIR)gen_utils.c			\
			$(SRCS_DIR)init_item.c			\
			$(SRCS_DIR)draw_cpt.c			\
			$(SRCS_DIR)config_file.c		\
			$(SRCS_DIR)clear.c			\
			$(SRCS_DIR)tools.c			\
			$(SRCS_DIR)time.c			\
			$(SRCS_DIR)clicked_pos.c		\
			$(SRCS_DIR)draw_detail.c		\
			$(SRCS_DIR)init_explo.c			\
			$(SRCS_DIR)init_ore.c			\
			$(SRCS_DIR)init_sprite.c		\
			$(SRCS_DIR)inventory.c			\
			$(SRCS_DIR)clicked.c			\
			$(SRCS_DIR)draw_inventory.c		\
			$(SRCS_DIR)move.c			\
			$(SRCS_DIR)init_player.c		\
			$(SRCS_DIR)gen_ore.c			\
			$(SRCS_DIR)utils.c			\
			$(SRCS_DIR)draw.c			\
			$(SRCS_DIR)event.c			\
			$(SRCS_DIR)init_game.c			\
			$(SRCS_DIR)config.c			\
			$(SRCS_DIR)init_mountain.c		\
			$(SRCS_DIR)init_fire.c			\
			$(SRCS_DIR)init_rock.c			\
			$(SRCS_DIR)map.c			\
			$(SRCS_DIR)game.c


OBJS		= 	$(SRCS:.c=.o)

CFLAGS		+= 	-I./include

LDFLAGS		+=	-L./lib/my -lmy -lcsfml-graphics -lcsfml-window
LDFLAGS		+=	-lcsfml-system -lcsfml-audio -lm -lpthread

all		:	$(NAME)

$(NAME)		: 	$(OBJS)
			make -C ./lib/my
			$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LDFLAGS)

clean		:
			make clean -C ./lib/my
			$(RM) $(OBJS)

fclean		:	clean
			make fclean -C ./lib/my
			$(RM) $(NAME)

re		:	fclean all

.PHONY		: 	all clean fclean re

