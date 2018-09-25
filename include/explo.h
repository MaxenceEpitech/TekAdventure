/*
** explo.h for tekadv in /home/maxence.fourrier/tekadventure
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sun Oct  8 23:22:23 2017 maxence.fourrier
** Last update Fri Oct 13 13:30:10 2017 maxence.fourrier
*/

#ifndef EXPLO_H_

# define EXPLO_H_

/*      __________ ________________________ __________
**
**                        INCLUDES
**      __________ ________________________ __________
*/

# include <stdlib.h>
# include <unistd.h>
# include <SFML/Graphics.h>
# include <SFML/Audio.h>
# include <SFML/Window.h>
# include <SFML/System.h>

/*      __________ ________________________ __________
**
**                        DEFINES
**      __________ ________________________ __________
*/

# define BACK_LINE		".\n"

# define READ_SIZE		1

# define MAX_DIFFICULTY		3

# define RADIUS_BASE		2

# define PROB_ERROR		1

# define HIT_SPEED_MIN		0.02

# define REGEN_TIME_PLAYER	1000
# define REGEN_TIME_BASE	1000
# define CONSO_TIME_OXY		1000
# define REGEN_OXY		4

# define PER_SECOND		"  Volts / S"
# define MODULE_PLACED		"  Module placed"
# define MODULES_PLACED		"  Modules placed"
# define TOTAL_ENERGY		"  Volt stocked"
# define TOTALS_ENERGY		"  Volts stocked"

# define LEVEL			"Level : "

# define MAX_UPGRADE		10

# define FONT			"font.ttf"

/*
**		     __ Windows __
*/
# define SCREEN_WIDTH		1341
# define SCREEN_HEIGHT		700
# define SCREEN_NAME		"__ Explo World =P __"

/*
**		     __ CONSOLE __
*/
# define CONSOLE		">> _ TekAdv _ $>"
# define SPACE			" "

# define CONSOLE_ON		"Console enable in config file.\n"
# define CONSOLE_OFF		"Console disable in config file.\n"

# define GIVE_ELEMENT		"You must add an element.\n"
# define GIVE_AMOUNT		"You must add an amount.\n"
# define GIVE_USAGE		"Give usage : give <element> <amount>\n"
# define ADDED_INV		" has been added to your inventory.\n"
# define UNKNOWN_ELEM		"Unknown element.\n"
# define GIVE_CANT		"Cant give the item to your inventory.\n"
# define UNKNOWN_COMMAND	": Unknown command.\n"
# define UNVALID_AMOUNT		": is not a valid amount.\n"

# define MAP_CLEAR		"Map successfully clear.\n"
# define USAGE_CLEAR		"Wrong usage of clear.\n"
# define USE_CLEAR_INV		"Syntax : clear <inventory>\n"
# define USE_CLEAR_MAP		"         clear <map>\n"
# define INV_CLEAR		"Inventory succesfully clear.\n"

/*
**		     __ TIME __
*/
# define HOUR			1000 * 10

# define NB_MINUTE		60
# define NB_HOUR		24

# define MINUTE			HOUR / NB_MINUTE

/*
**		     __ MOB __
*/
# define NB_MOB			20

# define MOB_BOSS		0
# define MOB_EGG		1
# define MOB_2			2

# define MOB_MIN_TIME		20

# define RANGE_EGG_BREAK	300

/*
**		     __ STORM __
*/
# define MIN_TIME_STORM		40
# define MAX_TIME_STORM		120
# define STORM_DURING_TIME	10

# define NB_MAX_OBJ		40
# define PERCENT_ADD_OBJ	80

# define MIN_GEN_OBJ		1
# define MAX_GEN_OBJ		2

/*
**		     __ GIF __
*/
# define NB_GIF			20

# define GIF_1			0
# define GIF_1_NAME		"textures/gif/gif-"
# define GIF_1_TOTAL		118
# define GIF_1_TIME		20

# define GIF_2			1
# define GIF_2_NAME		"textures/base/base-"
# define GIF_2_TOTAL		44
# define GIF_2_TIME		30

# define GIF_3			2
# define GIF_3_NAME		"textures/base_sphere/new-base-"
# define GIF_3_TOTAL		29
# define GIF_3_TIME		20

# define GIF_4			3
# define GIF_4_NAME		"textures/fire/fire-"
# define GIF_4_TOTAL		59
# define GIF_4_TIME		20

# define GIF_5			4
# define GIF_5_NAME		"textures/nuclear/nuclear-"
# define GIF_5_TOTAL		59
# define GIF_5_TIME		20

# define GIF_6			5
# define GIF_6_NAME		"textures/sphere/nuclear-"
# define GIF_6_TOTAL		80
# define GIF_6_TIME		20

# define GIF_7			6
# define GIF_7_NAME		"textures/launch_button/launch-"
# define GIF_7_TOTAL		156
# define GIF_7_TIME		20

# define GIF_8			7
# define GIF_8_NAME		"textures/fusion/fusion-"
# define GIF_8_TOTAL		60
# define GIF_8_TIME		40

# define GIF_9			8
# define GIF_9_NAME		"textures/rock/tornade-"
# define GIF_9_TOTAL		11
# define GIF_9_TIME		15

# define GIF_10			9
# define GIF_10_NAME		"textures/oeuf/image-"
# define GIF_10_TOTAL		69
# define GIF_10_TIME		15

# define GIF_11			10
# define GIF_11_NAME		"textures/perso_inv/perso-"
# define GIF_11_TOTAL		234
# define GIF_11_TIME		20

# define GIF_12			0
# define GIF_12_NAME		"textures/champ2/zeratul"
# define GIF_12_TOTAL		234
# define GIF_12_TIME		0

# define GIF_13			11
# define GIF_13_NAME		"textures/oeuf/image-"
# define GIF_13_TOTAL		69
# define GIF_13_TIME		20

# define GIF_14			0
# define GIF_14_NAME		"textures/insect/Phoenix"
# define GIF_14_TOTAL		125
# define GIF_14_TIME		20

# define GIF_15			12
# define GIF_15_NAME		"textures/cutscene_intro/intro"
# define GIF_15_TOTAL		503
# define GIF_15_TIME		70

# define GIF_16			13
# define GIF_16_NAME		"textures/turret/turret"
# define GIF_16_TOTAL		189
# define GIF_16_TIME		14.5

# define GIF_17			14
# define GIF_17_NAME		"textures/splash/splash-"
# define GIF_17_TOTAL		11
# define GIF_17_TIME		15

# define GIF_18			15
# define GIF_18_NAME		"textures/loading/loading-"
# define GIF_18_TOTAL		65
# define GIF_18_TIME		30

/*
**		     __ Config file __
*/
# define UNVALIDE_FILE		"UNVALIDE FILE, \nThe line "
# define UNVALIDE_FILE_		" is unvalid.\nIt should be : "
# define UNVALIDE_FILE__	"=<number>\nPlease change the line or "
# define UNVALIDE_FILE___	"contact an operator.\n"

# define LINE_1			"DIFFICULTY"
# define LINE_2			"MAP WIDTH"
# define LINE_3			"MAP HEIGHT"
# define LINE_4			"NUMBER OF LAKE"
# define LINE_5			"NUMBER OF FIRE"
# define LINE_6			"NUMBER OF ROCK"
# define LINE_7			"AMOUNT OF OXYGEN"
# define LINE_8			"AMOUNT OF HP"
# define LINE_9			"AMOUNT OF ENERGY"
# define LINE_10		"PLAYER MOVE SPEED"
# define LINE_11		"NUMBER OF PLANETS"
# define LINE_12		"CONSOLE"
# define LINE_13		"STORM"

# define E_LINE_1		1
# define E_LINE_2		2
# define E_LINE_3		3
# define E_LINE_4		4
# define E_LINE_5		5
# define E_LINE_6		6
# define E_LINE_7		7
# define E_LINE_8		8
# define E_LINE_9		9
# define E_LINE_10		10
# define E_LINE_11		11
# define E_LINE_12		12
# define E_LINE_13		13

/*
**	             __ CIRCLE __
*/
# define NB_CIRCLE		10

# define RADIUS_CIRCLE_HOME	300

/*
**		     __ Inventory __
*/
# define SIZE_INV_Y		3
# define SIZE_INV_X		7

# define INV_DIM_X		118
# define INV_DIM_Y		119

# define POS_X			400
# define POS_Y			70

# define INV_X			6 + POS_X
# define INV_Y			6 + POS_Y

# define ITEM_DRAW_X		INV_X - (SCREEN_WIDTH / 2)
# define ITEM_DRAW_Y		INV_Y - (SCREEN_HEIGHT / 2)

# define INV_DRAW_X		POS_X - (SCREEN_WIDTH / 2)
# define INV_DRAW_Y		POS_Y - (SCREEN_HEIGHT / 2)

# define EQU_DRAW_X		INV_DRAW_X - 29
# define EQU_DRAW_Y		INV_DRAW_Y + 400

# define EQU_X			POS_X - 29 + 34
# define EQU_Y			POS_Y + 400 + 35

# define INV_CRAFT_X		100 - (SCREEN_WIDTH / 2)
# define INV_CRAFT_Y		15 + (-SCREEN_HEIGHT / 2)
# define SIZE_CRAFT_X		131
# define SIZE_CRAFT_Y		120
# define CRAFT_CROSS		20

# define SIZE_OF_PAGE		5

# define STACK_SIZE		9

/*
**		     __ Gen Map procedural __
*/
# define M_G_R_MAX		5
# define M_G_R_MIN		7

# define M_G_NB_POS_MAX		12
# define M_G_NB_POS_MIN		8

# define M_G_POS_DIFF		15

# define END_LIST_POS		-100

/*
**		     __ Ore __
*/
# define NB_ORE			10

# define COAL			'0'
# define COAL_MAX		8
# define COAL_MIN		5
# define PERCENT_COAL		5 / 100

# define IRON			'1'
# define IRON_MAX		8
# define IRON_MIN		5
# define PERCENT_IRON		7 / 100

# define COPPER			'2'
# define COPPER_MAX		12
# define COPPER_MIN		7
# define PERCENT_COPPER		6 / 100

# define LITHIUM		'3'
# define LITHIUM_MAX		5
# define LITHIUM_MIN		2
# define PERCENT_LITHIUM	4 / 100

# define URANIUM		'4'
# define URANIUM_MAX		8
# define URANIUM_MIN		5
# define PERCENT_URANIUM	2 / 100

# define TITANIUM		'5'
# define TITANIUM_MAX		7
# define TITANIUM_MIN		5
# define PERCENT_TITANIUM	3 / 100

# define IRIDIUM		'6'
# define IRIDIUM_MAX		1
# define IRIDIUM_MIN		1
# define PERCENT_IRIDIUM	0.1 / 100

# define CARBON			'7'
# define GLASS			'8'
# define SAND			'9'
# define ANTI			'9' + 1
# define FOOD			'9' + 2

# define MOD_SOLAR		'20'
# define MOD_COAL		'21'
# define MOD_LAUNCHER		'22'
# define MOD_NUCLEAR		'23'
# define MOD_FUSION		'24'
# define MOD_CHEST		'25'
# define MOD_DRILL		'26'

# define FOOD_HEAL		10

# define ORE_BORDER		5

# define ORE_GEN_CIRCLE		5

# define MIN_DIST_BTW		10

# define ROCK			'0' - 1

# define ORE_HEIGHT		4

/*
**		     __ Pos __
*/
# define SPEED			1.1

# define MIN_DIST		SPEED + 1

# define MAP_BORDER		3

/*
**		     __ Coor __
*/
# define BORDER			3

# define MOUNTAIN_X		5
# define MOUNTAIN_Y		4

# define FLOOR_X		300
# define FLOOR_Y		300

# define FIRE_X			1
# define FIRE_Y			1

# define ROCK_X			1
# define ROCK_Y			1

# define BASE_X			0
# define BASE_Y			0
# define BASE_MIN_X		45
# define BASE_MIN_Y		14
# define BASE_MAX_X		186
# define BASE_MAX_Y		143
# define BASE_CENTER_X		123
# define BASE_CENTER_Y		71

# define BASE_CANT_WALK_PIXEL	SPRITE_FLOOR_SIZE / 2

# define SOLAR_MIN_X		0
# define SOLAR_MIN_Y		0
# define SOLAR_MAX_X		0
# define SOLAR_MAX_Y		0

/*
**		     __ Module __
*/
# define NB_PLACED		30

# define NB_MODULE		25
# define NB_LIMIT		20

# define MODULE_BASE		0
# define MODULE_SOLAR		1
# define MODULE_COAL		2
# define MODULE_LAUNCHER	3
# define MODULE_NUCLEAR		4
# define MODULE_FUSION		5
# define MODULE_CHEST		6
# define MODULE_DRILL		7

# define ITEM_DRILL		7
# define ITEM_CARBON		8
# define ITEM_GLASS		9

# define MODULE_LASER		10

# define PATH_P_BASE		"textures/building/home.png"
# define SPR_P_BASE		0
# define PATH_P_SOLAR		"textures/building/solar_panel.png"
# define SPR_P_SOLAR		1
# define PATH_P_COAL		"textures/building/coal.png"
# define SPR_P_COAL		2
# define PATH_P_LAUNCHER	"textures/building/launcher.png"
# define SPR_P_LAUNCHER		3
# define PATH_P_NUCLEAR		"textures/building/nuclear.png"
# define SPR_P_NUCLEAR		4
# define PATH_P_FUSION		"textures/building/fusion.png"
# define SPR_P_FUSION		5
# define PATH_P_CHEST		"textures/building/chest.png"
# define SPR_P_CHEST		6
# define PATH_P_LASER		"textures/building/chest.png"
# define SPR_P_LASER		10

# define COAL_BURN_TIME		75
# define NUCLEAR_BURN_TIME	300
# define FUSION_PROD_TIME	100
# define FUSION_CONSO		2000
# define CONSO_FUSION_		" Volts / S"

/*
**		     __ FLOOR __
*/
# define DEPTH			6
# define NB_FLOOR		100

# define DIRT			1
# define GRASS			2

# define PATH_F_0		"textures/floor/sand.png"
# define SPR_F_0		0
# define PATH_F_1		"textures/floor/sand_1.png"
# define SPR_F_1		1
# define PATH_F_2		"textures/floor/sand_2.png"
# define SPR_F_2		2

# define PATH_F_0_0		"textures/floor/sand_hole1.png"
# define SPR_F_0_0		0
# define PATH_F_0_1		"textures/floor/sand_coal.png"
# define SPR_F_0_1		1
# define PATH_F_0_2		"textures/floor/sand_iron.png"
# define SPR_F_0_2		2
# define PATH_F_0_3		"textures/floor/sand_copper.png"
# define SPR_F_0_3		3
# define PATH_F_0_4		"textures/floor/sand_unknown.png"
# define SPR_F_0_4		4
# define PATH_F_0_5		"textures/floor/sand_uranium.png"
# define SPR_F_0_5		5
# define PATH_F_0_6		"textures/floor/sand_unknown.png"
# define SPR_F_0_6		6
# define PATH_F_0_7		"textures/floor/sand_iridium.png"
# define SPR_F_0_7		7

# define PATH_F_1_0		"textures/floor/sand_hole1_.png"
# define SPR_F_1_0		0
# define PATH_F_1_1		"textures/floor/sand_coal_.png"
# define SPR_F_1_1		1
# define PATH_F_1_2		"textures/floor/sand_iron_.png"
# define SPR_F_1_2		2
# define PATH_F_1_3		"textures/floor/sand_copper_.png"
# define SPR_F_1_3		3
# define PATH_F_1_4		"textures/floor/sand_unknown_.png"
# define SPR_F_1_4		4
# define PATH_F_1_5		"textures/floor/sand_uranium_.png"
# define SPR_F_1_5		5
# define PATH_F_1_6		"textures/floor/sand_unknown_.png"
# define SPR_F_1_6		6
# define PATH_F_1_7		"textures/floor/sand_iridium_.png"
# define SPR_F_1_7		7

# define PATH_F_2_0		"textures/floor/sand_bedrock.png"
# define SPR_F_2_0		0
# define PATH_F_2_1		"textures/floor/sand_bedrock.png"
# define SPR_F_2_1		1
# define PATH_F_2_2		"textures/floor/sand_bedrock.png"
# define SPR_F_2_2		2
# define PATH_F_2_3		"textures/floor/sand_bedrock.png"
# define SPR_F_2_3		3
# define PATH_F_2_4		"textures/floor/sand_bedrock.png"
# define SPR_F_2_4		4
# define PATH_F_2_5		"textures/floor/sand_bedrock.png"
# define SPR_F_2_5		5
# define PATH_F_2_6		"textures/floor/sand_bedrock.png"
# define SPR_F_2_6		6
# define PATH_F_2_7		"textures/floor/sand_bedrock.png"
# define SPR_F_2_7		7

/*
**		     __ POW3R __
*/
# define POWER_DRILL		5

/*
**		     __ HUD __
*/
# define HUD_BAR_SIZE_X		15
# define HUD_BAR_SIZE_Y		200

# define HUD_POS_X		560
# define HUD_POS_Y		130

# define PATH_OXY		"textures/oxygen.png"
# define SPR_OXY		0
# define PATH_POWER		"textures/power.png"
# define SPR_POWER		1
# define PATH_HP		"textures/health.png"
# define SPR_HP			2

/*
**		     __ Sounds __
*/
# define NB_SOUND		50

# define SND_MENU		0
# define PATH_SND_MENU		"music/EO_below_the_asteroids.ogg"
# define SND_GAME_0		1
# define PATH_GAME_0		"music/general/1.ogg"
# define SND_GAME_1		2
# define PATH_GAME_1		"music/general/2.ogg"
# define SND_GAME_2		3
# define PATH_GAME_2		"music/general/3.ogg"
# define SND_GAME_3		4
# define PATH_GAME_3		"music/general/4.ogg"
# define SND_GAME_4		5
# define PATH_GAME_4		"music/general/5.ogg"
# define SND_GAME_5		6
# define PATH_GAME_5		"music/general/6.ogg"
# define SND_GAME_6		7
# define PATH_GAME_6		"music/general/7.ogg"
# define SND_GAME_7		8
# define PATH_GAME_7		"music/general/8.ogg"
# define SND_BASE		9
# define PATH_SND_BASE		"music/building/base.wav"
# define SND_SOLAR		10
# define PATH_SND_SOLAR		"music/building/solar.wav"
# define SND_COAL		11
# define PATH_SND_COAL		"music/building/coal_furnace.wav"
# define SND_NUCLEAR		12
# define PATH_SND_NUCLEAR	"music/building/nuclear.wav"
# define SND_FUSION		13
# define PATH_SND_FUSION	"music/building/fusion.wav"
# define SND_LASER		14
# define PATH_SND_LASER		"music/effect/laser.ogg"
# define SND_DRILL_1		15
# define PATH_SND_DRILL_1	"music/effect/drilling1.wav"
# define SND_DRILL_2		16
# define PATH_SND_DRILL_2	"music/effect/drilling2.wav"
# define SND_EGG_EXPLO		17
# define PATH_SND_EGG_EXPLO	"music/effect/egg_explo.ogg"
# define SND_DIE_BIRD		18
# define PATH_SND_DIE_BIRD	"music/effect/bird_die.wav"
# define SND_CRASH		19
# define PATH_SND_CRASH		"music/effect/crash.ogg"
# define SND_SIREN		20
# define PATH_SND_SIREN		"music/effect/siren.ogg"
# define SND_INC		21
# define PATH_SND_INC		"music/effect/inc.wav"
# define SND_EVACUATE		22
# define PATH_SND_EVACUATE	"music/effect/evacuate.wav"
# define SND_DESTROY		23
# define PATH_SND_DESTROY	"music/effect/destroy.wav"
# define SND_BFR_SIREN		24
# define PATH_SND_BFR_SIREN	"music/effect/before_siren.wav"
# define SND_DI1		25
# define PATH_SND_DI1		"music/effect/death_insect.ogg"
# define SND_DI2		26
# define PATH_SND_DI2		"music/effect/death_insect2.ogg"
# define SND_DI3		27
# define PATH_SND_DI3		"music/effect/death_insect3.ogg"
# define SND_INJ1		28
# define PATH_SND_INJ1		"music/effect/injur.ogg"
# define SND_INJ2		29
# define PATH_SND_INJ2		"music/effect/injur2.ogg"
# define SND_INJ3		30
# define PATH_SND_INJ3		"music/effect/injur3.ogg"
# define SND_DEATH1		31
# define PATH_SND_DEATH1	"music/effect/death.ogg"
# define SND_DEATH2		32
# define PATH_SND_DEATH2	"music/effect/death2.ogg"
# define SND_DEATH3		33
# define PATH_SND_DEATH3	"music/effect/death4.ogg"
# define SND_CHEST		34
# define PATH_SND_CHEST		"music/effect/chest.ogg"

/*
**		     __ Sprites __
*/
# define NB_SPRITE		80

# define PATH_SPRITE_0		"textures/red.png"
# define PATH_SPRITE_1		"textures/blue.png"
# define SPR_0			0
# define PATH_INV		"textures/inventory_.png"
# define SPR_INV		1
# define PATH_ROCK_		"textures/inventory.png"
# define SPR_ROCK_		2
# define PATH_FIRE		"textures/inventory.png"
# define SPR_FIRE		3
# define PATH_MOUNTAIN		"textures/inventory.png"
# define SPR_MOUNTAIN		4
# define PATH_INV_EQU		"textures/equiped.png"
# define SPR_INV_EQU		5
# define PATH_FLOOR_1		"textures/floor/sand.png"
# define SPR_FLOOR_1		6
# define PATH_FLOOR_2		"textures/floor_1.png"
# define SPR_FLOOR_2		7
# define PATH_FLOOR_3		"textures/floor_1.png"
# define SPR_FLOOR_3		8
# define PATH_FLOOR_4		"textures/floor_1.png"
# define SPR_FLOOR_4		9
# define PATH_FLOOR_5		"textures/floor_1.png"
# define SPR_FLOOR_5		10
# define PATH_CHARAC		"textures/perso.png"
# define SPR_CHARAC		11
# define PATH_CLICK		"textures/click.png"
# define SPR_CLICK		12
# define PATH_HOME		"textures/home.png"
# define SPR_HOME		13
# define PATH_SOLAR		"textures/solar_panel.png"
# define SPR_SOLAR		14
# define PATH_ARROW_R		"textures/arrow_red.png"
# define SPR_ARROW_R		15
# define PATH_ARROW_G		"textures/arrow_green.png"
# define SPR_ARROW_G		16
# define PATH_CRAFT		"textures/craft.png"
# define SPR_CRAFT		17
# define PATH_INV_G		"textures/inv_case_green.png"
# define SPR_INV_G		18
# define PATH_INV_R		"textures/inv_case_red.png"
# define SPR_INV_R		19
# define PATH_INV_SOLAR		"textures/solar_clicked.png"
# define SPR_INV_SOLAR		20
# define PATH_LINK		"textures/link_.png"
# define SPR_LINK		21
# define PATH_LINK_		"textures/link.png"
# define SPR_LINK_		22
# define PATH_DONE		"textures/done.png"
# define SPR_DONE		23
# define PATH_UPGRADE		"textures/upgrade_.png"
# define SPR_UPGRADE		24
# define PATH_UPGRADE_		"textures/upgrade.png"
# define SPR_UPGRADE_		25
# define PATH_ON		"textures/on.png"
# define SPR_ON			26
# define PATH_ON_		"textures/on_.png"
# define SPR_ON_		27
# define PATH_OFF		"textures/off.png"
# define SPR_OFF		28
# define PATH_OFF_		"textures/off_.png"
# define SPR_OFF_		29
# define PATH_BLACK		"textures/black.png"
# define SPR_BLACK		30
# define PATH_SPEED		"textures/speed.png"
# define SPR_SPEED		31
# define PATH_AMOUNT		"textures/quantity.png"
# define SPR_AMOUNT		32
# define PATH_BATTERY		"textures/battery.png"
# define SPR_BATTERY		33
# define PATH_LEVEL		"textures/level.png"
# define SPR_LEVEL		34
# define PATH_INV_CHEST		"textures/inventory___.png"
# define SPR_INV_CHEST		35
# define PATH_FURNACE		"textures/furnace.png"
# define SPR_FURNACE		36
# define PATH_ADD_G		"textures/add_g.png"
# define SPR_ADD_G		37
# define PATH_ADD_G_		"textures/add_g_.png"
# define SPR_ADD_G_		38
# define PATH_ADD_R		"textures/add_r.png"
# define SPR_ADD_R		39
# define PATH_NUCLEAR_REAC	"textures/nuclear_reactor.png"
# define SPR_NUCLEAR_REAC	40
# define PATH_LAUNCHER_B	"textures/launcher_back.png"
# define SPR_LAUNCHER_B		41
# define PATH_FUSION_B		"textures/fusion.png"
# define SPR_FUSION_B		42
# define PATH_TAKE		"textures/take.png"
# define SPR_TAKE		43
# define PATH_TAKE_		"textures/take_.png"
# define SPR_TAKE_		44
# define PATH_TRASH		"textures/trash.png"
# define SPR_TRASH		45
# define PATH_MINE_1		"textures/floor/mine_1.png"
# define SPR_MINE_1		46
# define PATH_MINE_2		"textures/floor/mine_2.png"
# define SPR_MINE_2		47
# define PATH_MINE_3		"textures/floor/mine_3.png"
# define SPR_MINE_3		48
# define PATH_ROCK_0		"textures/rock_2.png"
# define SPR_ROCK_0		49
# define PATH_ROCK_1		"textures/rock_4.png"
# define SPR_ROCK_1		50
# define PATH_ROCK_2		"textures/rock_6.png"
# define SPR_ROCK_2		51
# define PATH_ROCK_3		"textures/rock_8.png"
# define SPR_ROCK_3		52
# define PATH_LAKE		"textures/lake.png"
# define SPR_LAKE		53
# define PATH_LASER_T		"textures/laser_tower.png"
# define SPR_LASER_T		54
# define PATH_SKY		"textures/menu/blank_galaxy.png"
# define SPR_SKY		55
# define PATH_MENU		"textures/menu/menu.png"
# define SPR_MENU		56
# define PATH_MENU_HELP		"textures/menu/menu_help.png"
# define SPR_MENU_HELP		57
# define PATH_MENU_NEW		"textures/menu/menu_new.png"
# define SPR_MENU_NEW		58
# define PATH_MENU_LOAD		"textures/menu/menu_load.png"
# define SPR_MENU_LOAD		59
# define PATH_MENU_OPT		"textures/menu/menu_options.png"
# define SPR_MENU_OPT		60
# define PATH_MENU_Q		"textures/menu/menu_quit.png"
# define SPR_MENU_Q		61
# define PATH_OPT		"textures/menu/options.png"
# define SPR_OPT		62
# define PATH_HELP		"textures/menu/help.png"
# define SPR_HELP		63
# define PATH_SOON		"textures/menu/coming_soon.png"
# define SPR_SOON		64
# define PATH_SPLASH		"textures/splash.png"
# define SPR_SPLASH		65
# define PATH_LOST		"textures/lost.png"
# define SPR_LOST		66

# define SPRITE_FLOOR_SIZE	256

# define POS_TAB_FLOOR		5

# define CLICK_SIZE		50

# define PERSO_SIZE_X		51
# define PERSO_SIZE_Y		93

/*
**		     __ Item __
*/
# define NB_ITEM		40

# define ITEM_SIZE_X		115
# define ITEM_SIZE_Y		114

# define ITEM_INIT_X		10
# define ITEM_INIT_Y		10

# define ITEM_SIZE_X_		ITEM_SIZE_X + 7
# define ITEM_SIZE_Y_		ITEM_SIZE_Y + 7

# define PATH_ROCK		"textures/item/rock_item.png"
# define SPR_ROCK		0
# define PATH_COAL		"textures/item/coal_item.png"
# define SPR_COAL		1
# define PATH_IRON		"textures/item/iron_item.png"
# define SPR_IRON		2
# define PATH_COPPER		"textures/item/copper_item.png"
# define SPR_COPPER		3
# define PATH_LITHIUM		"textures/item/lithium_item.png"
# define SPR_LITHIUM		4
# define PATH_URANIUM		"textures/item/uranium_item.png"
# define SPR_URANIUM		5
# define PATH_TITANIUM		"textures/item/titanium_item.png"
# define SPR_TITANIUM		6
# define PATH_IRIDIUM		"textures/item/iridium_item.png"
# define SPR_IRIDIUM		7
# define PATH_CARBON		"textures/item/carbon_item.png"
# define SPR_CARBON		8
# define PATH_GLASS		"textures/item/glass_item.png"
# define SPR_GLASS		9
# define PATH_SAND		"textures/item/sand_item.png"
# define SPR_SAND		10
# define PATH_ANTI		"textures/item/antimatiere_item.png"
# define SPR_ANTI		11
# define PATH_FOOD		"textures/item/food_item.png"
# define SPR_FOOD		12

# define PATH_I_SOLAR		"textures/item/solar_item.png"
# define SPR_I_SOLAR		20
# define PATH_I_COAL		"textures/item/coal_item_.png"
# define SPR_I_COAL		21
# define PATH_I_LAUNCHER	"textures/item/launcher_item.png"
# define SPR_I_LAUNCHER		22
# define PATH_I_NUCLEAR		"textures/item/nuclear_item.png"
# define SPR_I_NUCLEAR		23
# define PATH_I_FUSION		"textures/item/fusion_item.png"
# define SPR_I_FUSION		24
# define PATH_I_CHEST		"textures/item/chest_item.png"
# define SPR_I_CHEST		25
# define PATH_I_DRILL		"textures/item/drill.png"
# define SPR_I_DRILL		26
# define PATH_I_CARBON		"textures/item/carbon_item.png"
# define SPR_I_CARBON		27
# define PATH_I_GLASS		"textures/item/glass_item.png"
# define SPR_I_GLASS		28
# define PATH_I_LASER		"textures/item/laser_item.png"
# define SPR_I_LASER		29

# define PLACEABLE		0

/*
**		     __ Event __
*/
# define QUIT			1
# define LEFT			2
# define RIGHT			3
# define UP			4
# define DOWN			5
# define INVENTORY		6
# define ESCAPE			7
# define CRAFT			8

/*
**		     __ Error Message __
*/
# define IN_FILE	"Error in the file : "
# define M_DIFFICULTY	"Line 1.\nThe difficulty must be between 1 and 3.\n"
# define M_M_SIZE	"Line 2 and 3.\nThe map width and height"
# define M_M_SIZE_2	" has to be at least 100 blocs.\n"
# define M_M_MOUNTAIN	"Line 4.\nThe amount of mountains "
# define M_M_MOUNTAIN_2	"must be between 1 and 80.\n"
# define M_M_FIRE	"Line 5.\nThe amount of fires "
# define M_M_FIRE_2	"must be between 1 and 40.\n"
# define M_M_ROCK	"Line 6.\nThe amount of rocks "
# define M_M_ROCK_2	"must be between 1 and 1200.\n"
# define M_P_OXY	"Line 7.\nThe amount of oxygen "
# define M_P_OXY_2	"for the player must be between 0 and 100.\n"
# define M_P_HP		"Line 8.\nThe amount of Health for the player "
# define M_P_HP_2	"must be between 0 and 100.\n"
# define M_P_POWER	"Line 9.\nThe amount of Power for the player "
# define M_P_POWER_2	"must be between 0 and 100.\n"
# define M_P_SPEED	"Line 10.\nThe speed of the player must be between "
# define M_P_SPEED_2	"1 and 5.\n"
# define M_PLANETS	"Line 11.\nThe ammount of planets must "
# define M_PLANETS_2	"be between 2 and 20.\n"
# define M_CONSOLE	"Line 12.\nThe console must be 1 or 0.\n"
# define M_STORM	"Line 13.\nThe storm must be 1 or 0.\n"

# define FILE_EXIST	": This file does not existe. Check usage bellow :\n"

# define USAGE_1	"Usage : "
# define USAGE_2	" Config_File\n"

# define OPEN_MSG	"Open Error.\n"
# define READ_MSG	"Read Error.\n"
# define MALLOC_MSG	"Malloc Error.\n"

/*
**	             __ Returns Values __
*/
# define SUCCESS	0
# define ERROR		84

/*
**                       __ TypeDef __
*/
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

typedef struct		s_ptr
{
  int			nb;
  int			(*fnc)();
}			t_ptr;

typedef struct		s_ptr_line
{
  char			*str;
  int			(*fnc)();
}			t_ptr_line;

typedef struct		s_list
{
  char			*data;
  struct s_list		*next;
}			t_list;

typedef struct		s_pos
{
  int			alive;
  int			type;
  int			draw;
  sfVector2i		vec;
  struct s_pos		*next;
}			t_pos;

typedef struct		s_my_framebuffer
{
  sfUint8		*pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

typedef struct		s_graph
{
  sfRenderWindow	*window;
  t_my_framebuffer	*framebuffer;
  t_my_framebuffer	*framebuffer_time;
  sfTexture		*texture;
  sfTexture		*tex_time;
  sfSprite		*sprite;
  sfSprite		*time;
  sfView		*view;
  sfText		*text;
  sfFont		*font;
}			t_graph;

typedef struct		s_config
{
  int			storm;
  int			console;
  int			difficulty;
  int			map_size_x;
  int			map_size_y;
  int			map_mountain;
  int			map_fire;
  int			map_rock;
  int			player_power;
  int			player_oxy;
  int			player_hp;
  int			player_speed;
  int			planets;
}			t_config;

typedef struct		s_limit
{
  sfVector2f		top;
  sfVector2f		bot;
}			t_limit;

typedef struct		s_module
{
  int			type;
  int			*quantity;
}			t_module;

typedef struct		s_inv
{
  int			item;
  int			quantity;
}			t_inv;

typedef struct		s_placed_mod
{
  float			angle;
  sfVector2i		furnace;
  int			on;
  int			link_cost;
  int			draw;
  sfVector2i		pos;
  int			upgrade;
  int			type;
  int			link;
  sfCircleShape		*circle;
  t_inv			***inv;
  struct s_placed_mod	*next;
}			t_placed_mod;

typedef struct		s_day
{
  unsigned long long	time;
  int			minute;
  int			day;
}			t_day;

typedef struct		s_obj
{
  int			cpt;
  int			alive;
  sfVector2f		pos;
  sfVector2f		dir;
}			t_obj;

typedef struct		s_mob
{
  int			splash;
  int			type;
  sfVector2f		pos;
  int			hp;
  int			draw;
  int			draw_;
}			t_mob;

typedef struct		s_storm
{
  unsigned long long	time;
  int			on;
  int			time_left;
  t_obj			**obj;
}			t_storm;

typedef struct		s_game
{
  int			music;
  sfSprite		**front_mob;
  sfSprite		**back_mob;
  sfVector2i		**rock_limit;
  char			**item_name;
  sfVector2i		base;
  int			***upgrade;
  t_mob			**mob;
  t_storm		*storm;
  unsigned long long	regen_player;
  unsigned long long	regen_base;
  unsigned long long	time;
  unsigned long long	draw_time;
  unsigned long long	conso_oxy;
  unsigned long long	spawn_mob;
  sfVector2i		size;
  t_module		**module;
  t_placed_mod		*placed;
  t_limit		**limit;
  t_limit		**move_pos;
  int			**map;
  char			***ore;
  int			**depth;
  t_pos			*mountain;
  t_pos			*fire;
  t_pos			*rock;
}			t_game;

typedef struct		s_player
{
  sfSprite		**front_player;
  sfSprite		**back_player;
  sfVector2i		draw;
  t_inv			***inv;
  sfVector2f		pos;
  sfVector2f		dir;
  sfVector2i		click;
  int			speed;
  float			hp;
  int			reg_hp;
  int			cons_oxy;
  int			oxy;
  int			power;
  int			base_power;
}			t_player;

typedef struct		s_explo
{
  sfMusic		**music;
  t_day			*day;
  sfCircleShape		**circle;
  sfSprite		***floor;
  sfSprite		***gif;
  sfSprite		**placed;
  sfSprite		**time;
  t_config		*config;
  sfSprite		**sprite;
  sfSprite		**module;
  sfSprite		**hud;
  sfSprite		**item;
  t_graph		*graph;
  t_player		*player;
  t_game		*game;
}			t_explo;

/*      __________ ________________________ __________
**
**                     Tekadv / Explo
**      __________ ________________________ __________
*/
/*
**	             __ init_sound.c __
*/
sfMusic		**init_music_other_other_other(sfMusic **);
sfMusic		**init_music_other_other(sfMusic **);
sfMusic		**init_music_other(sfMusic **);
sfMusic		**init_music();

/*
**	             __ death.c __
*/
void		draw_death(t_explo *, unsigned long long, unsigned long long);
int		death_player(t_explo *);
int		death(t_explo *);

/*
**	             __ give.c __
*/
int		give_health(char **, t_explo *);
int		give_power(char **, t_explo *);
int		give_oxygen(char **, t_explo *);

/*
**	             __ music_effect.c __
*/
void		effect_laser(t_explo *, int);
void		effect_drill(t_explo *);
void		effect_bird(t_explo *);
void		effect_egg(t_explo *);
void		effect_death(t_explo *);

/*
**	             __ music_effect.c __
*/
void		effect_intro(t_explo *, int);

/*
**	             __ fire_bird.c __
*/
void		kill_mob(t_placed_mod *, t_mob *, t_explo *);
void		draw_tower(t_explo *, t_placed_mod *, int);
void		bird_not_in_range(t_explo *, t_placed_mod *);

/*
**	             __ music_module.c __
*/
void		music_coal(t_explo *, t_placed_mod *);
void		music_solar(t_explo *, t_placed_mod *);
void		music_nuclear(t_explo *, t_placed_mod *);
void		music_fusion(t_explo *, t_placed_mod *);
void		music_base(t_explo *);

/*
**	             __ music.c __
*/
void		music_game(t_explo *);
void		play_stop_music(t_explo *, sfVector2i, sfVector2i, int);
void		effect_dmg(t_explo *);

/*
**	             __ menu.c __
*/
int		menu(t_explo *);

/*
**	             __ draw_laser_tower.c __
*/
void		draw_laser_tower(t_explo *, t_placed_mod *);

/*
**	             __ draw_laser.c __
*/
void		draw_laser(t_explo *, t_placed_mod *);

/*
**	             __ laser.c __
*/
void		click_laser(t_explo *, t_placed_mod *);
int		laser(t_explo *, t_placed_mod *);

/*
**	             __ intro.c __
*/
void		intro(t_explo *);

/*
**	             __ break_egg.c __
*/
void		break_egg(t_explo *);

/*
**	             __ mine_rock.c __
*/
int		check_rock(t_explo *, t_pos *, sfVector2f);
int		is_a_rock(t_explo *, sfVector2i, t_pos *);
int		mine_rock(t_explo *, sfVector2f, sfVector2i);

/*
**	             __ can_place_lake.c __
*/
int		can_place_lake(t_pos *, sfVector2f, int, t_explo *);

/*
**	             __ can_place_rock.c __
*/
int		can_place_rock(t_pos *, sfVector2f, int, t_explo *);

/*
**	             __ mine_time.c __
*/
void		draw_effect_mine(t_explo *, int, sfVector2f);
void		draw_while_mining(t_explo *, int, sfVector2f);
int		mouse_pressed_time(t_explo *, sfVector2f, int);
int		check_mine_time(sfVector2i, t_explo *);

/*
**	             __ mine.c __
*/
void		add_mined_to_inv(t_explo *, sfVector2i);
int		mine(int, t_explo *, sfVector2i, sfVector2f);

/*
**	             __ depth.c __
*/
int		**fill_depth(t_config *, int **);
int		**init_depth(t_config *);

/*
**	             __ gen_ore.c __
*/
char		**gen_ore_other(char **, sfVector2i);
char		**gen_ore(char **, sfVector2i);

/*
**	             __ draw_env.c __
*/
void		draw_env_lake(t_explo *, t_pos *);
void		draw_env_rock(t_explo *, t_pos *);

/*
**	             __ env.c __
*/
sfVector2i	**init_rock_limit();
void		draw_env(t_explo *);
void		check_rock_dir(t_explo *, t_pos *, sfVector2f, sfVector2f);
void		draw_env_after_player(t_explo *, t_pos *);

/*
**	             __ mob_utils.c __
*/
void		draw_gif_mob(t_explo *, t_mob *, sfVector3f, sfVector2i);
int		nb_egg_around_player(t_explo *);
sfVector2f	gen_egg(t_explo *);
void		gen_mob(t_explo *);

/*
**	             __ draw_mob.c __
*/
void		draw_bird(t_explo *);
void		draw_egg_before(t_explo *);
void		draw_egg_after(t_explo *);

/*
**	             __ mob.c __
*/
sfSprite	**init_mob_front(char *);
sfSprite	**init_mob_back(char *);
t_mob		**init_mob();
void		create_mod(t_explo *, sfVector2i, int, int);
void		move_mob(sfVector2f, t_mob *);

/*
**	             __ item.c __
*/
char		**init_item_name();

/*
**	             __ storm_obj.c __
*/
sfVector2f	gen_obj_pos(sfVector2f);
sfVector2f	gen_obj_dir(sfVector2f, sfVector2f);
void		create_storm_obj(t_explo *, t_storm *, int);

/*
**	             __ draw_storm.c __
*/
void		draw_gif_storm(t_explo *, int *, sfVector3f, sfVector2i);
void		draw_storm(t_explo *, t_storm *);

/*
**	             __ storm.c __
*/
t_storm		*init_storm();
void		check_dist_storm(t_explo *, t_storm *);
void		storm(t_explo *);
void		do_storm(t_explo *);

/*
**	             __ add_item_inv.c __
*/
sfVector2i	inv_had_place_console(t_inv ***, int);
int		add_item_inv_console(t_inv ***, int, int);

/*
**	             __ draw_fusion.c __
*/
void		add_power_fusion(t_explo *, t_placed_mod *,
				 sfVector2i, sfVector2f);
void		draw_fusion(t_explo *, t_placed_mod *);

/*
**	             __ fusion.c __
*/
int		click_button(t_explo *, t_placed_mod *);
sfVector3f	fusion_gif(t_explo *, sfVector3f, t_placed_mod *);
int		fusion(t_explo *, t_placed_mod *);

/*
**	             __ thread_console.c __
*/
int		console(t_explo *, int power);

/*
**	             __ change_time.c __
*/
int		verif_tab(char **);
int		change_time(char **, t_explo *);

/*
**	             __ clear_console.c __
*/
int		clear_elements(char **, t_explo *);

/*
**	             __ my_str_to_wordtab.c __
*/
char		**my_str_to_wordtab(const char *, char);

/*
**	             __ my_epurstr.c __
*/
char		*my_epurstr(char *);

/*
**	             __ give_object.c __
*/
int		detect_element(char **, t_explo *);
int		give_object(t_explo *, int, int);
int		detect_utils(char **, t_explo *);

/*
**	             __ help.c __
*/
int		exit_console(char **, t_explo *);
int		is_num(char *);
int		print_help_console(char **, t_explo *);

/*
**	             __ draw_button_launcher.c __
*/
void		draw_launcher_button(t_explo *, t_placed_mod *,
				     sfVector2i, sfVector2f);

/*
**	             __ draw_launcher.c __
*/
void		draw_background_launcher(t_explo *, sfVector2f);
void		draw_amount_launcher(t_explo *, sfVector2f, t_inv *);
void		draw_add_button_launcher(t_explo *, sfVector2f,
					 sfVector2i, int);
void		draw_launcher(t_explo *, t_placed_mod *);

/*
**	             __ launcher.c __
*/
int		launcher(t_explo *, t_placed_mod *);

/*
**	             __ conso_module.c __
*/
void		check_conso_type_other(t_explo *, t_placed_mod *, int);
void		check_conso_type(t_explo *, t_placed_mod *, int);
void		check_conso_module(t_explo *, t_placed_mod *);

/*
**	             __ draw_nuclear.c __
*/
void		draw_nuclear(t_explo *, t_placed_mod *);

/*
**	             __ nuclear.c __
*/
int		nuclear(t_explo *, t_placed_mod *);

/*
**	             __ click_coal_utils.c __
*/
int		change_furnace_on_other(sfVector2i, t_placed_mod *);
int		change_furnace_on(sfVector2i, t_placed_mod *);
int		change_nuclear_on_other(sfVector2i, t_placed_mod *);
int		change_nuclear_on(sfVector2i, t_placed_mod *);

/*
**	             __ coal_utils.c __
*/
void		check_first_furnace(t_explo *, t_placed_mod *, sfVector2i);
void		check_second_furnace(t_explo *, t_placed_mod *, sfVector2i);
int		click_add_coal(t_explo *, t_placed_mod *);

/*
**	             __ coal.c __
*/
sfVector2i	draw_fire(t_explo *explo, sfVector2i, t_placed_mod *);
void		draw_black(t_explo *);
int		click_coal(t_explo *, t_placed_mod *);
int		coal(t_explo *, t_placed_mod *);

/*
**	             __ draw_coal.c __
*/
void		draw_background_coal(t_explo *, t_placed_mod *, sfVector2f);
void		draw_power_coal(t_explo *, t_placed_mod *,
				sfVector2f, sfVector2i);
void		draw_add_button_coal(t_explo *, int, sfVector2f, int);
void		draw_amount_coal(t_explo *, sfVector2f, t_inv *);
void		draw_coal(t_explo *, t_placed_mod *);

/*
**	             __ check_can_place.c __
*/
int		can_place_center(sfVector2f, t_limit **,
				 t_placed_mod *, int);
int		can_place_top_right(sfVector2f, t_limit **,
				    t_placed_mod *, int);
int		can_place_top_left(sfVector2f, t_limit **,
				   t_placed_mod *, int);
int		can_place_bot_right(sfVector2f, t_limit **,
				    t_placed_mod *, int);
int		can_place_bot_left(sfVector2f, t_limit **,
				   t_placed_mod *, int);

/*
**	             __ draw_chest.c __
*/
void		draw_chest(t_explo *, t_placed_mod *, sfVector2i, int *);

/*
**	             __ chest.c __
*/
t_inv		*get_inv_clicked(t_explo *, t_placed_mod *,
				 sfVector2i *, int);
int		change_item_chest(t_explo *, sfVector2i,
				  t_inv *, t_placed_mod *);
int		click_chest(t_explo *, t_placed_mod *, int *);
int		chest(t_explo *, t_placed_mod *);

/*
**	             __ get_prod.c __
*/
int		get_prod_module(t_explo *, t_placed_mod *);
int		get_prod_base(t_explo *, t_placed_mod *);

/*
**	             __ click_upgrade.c __
*/
int		click_upgrade(t_explo *, sfVector2f, int *);

/*
**	             __ draw_upgrade.c __
*/
void		draw_arrow_upgrade(t_explo *, int *,
				   sfVector2f, t_placed_mod *);
void		draw_item_number(t_explo *, sfVector2f, int, int);
void		draw_frame_upgrade(t_explo *, sfVector2f, int, int);
void		draw_item_upgrade(t_explo *, int *,
				  sfVector2f, t_placed_mod *);
void		draw_upgrade(t_explo *, int *, sfVector2f, t_placed_mod *);

/*
**	             __ draw_base.c __
*/
void		draw_base_production(t_explo *, sfVector2f);
void		draw_base_energy(t_explo *, sfVector2f);
void		draw_base_amount(t_explo *, sfVector2f, t_placed_mod *);
void		draw_base_upgrade(t_explo *, sfVector2f);
void		draw_base(t_explo *);

/*
**	             __ base.c __
*/
t_placed_mod	*get_base_module(t_placed_mod *);
void		base_back(t_explo *, int *, int *, int *);
int		base(t_explo *, t_placed_mod *);

/*
**	             __ upgrade_base.c __
*/
int		*first_upgrade_base();
int		*second_upgrade_base();
int		*third_upgrade_base();

/*
**	             __ upgrade_solar.c __
*/
int		*first_upgrade_solar();
int		*second_upgrade_solar();
int		*third_upgrade_solar();

/*
**	             __ upgrade_utils.c __
*/
void		del_inv(t_inv ***, int, int);
int		can_upgrade(t_explo *, int *);
int		can_link(t_placed_mod *, t_explo *);

/*
**	             __ upgrade.c __
*/
int		***init_upgrade();

/*
**	             __ draw_button.c __
*/
void            button_link(t_explo *, sfVector2f, sfVector2i,
			    sfVector2i);
void            button_upgrade(t_explo *, sfVector2f, sfVector2i,
			       sfVector2i);
void            button_power(t_explo *, sfVector2f, sfVector2i,
			     t_placed_mod *);
void		draw_button(t_explo *, sfVector2i, sfVector2i,
			    t_placed_mod *);

/*
**	             __ draw_solar_utils.c __
*/
void		draw_arrow_solar_upg(t_explo *, t_inv ***, t_placed_mod *);
void		draw_arrow_solar_link(t_explo *, t_inv ***, t_placed_mod *);
void		draw_level(t_explo *, t_placed_mod *, sfVector2f);

/*
**	             __ draw_solar.c __
*/
void		draw_done(t_explo *, sfVector2f);
void		draw_needed_upgrade(t_explo *, t_placed_mod *);
void		draw_needed_link(t_explo *, int);
void		draw_solar(t_explo *, t_placed_mod *);

/*
**	             __ solar.c __
*/
int		solar(t_explo *, t_placed_mod *);

/*
**	             __ day_night_utils.c __
*/
t_day		*init_day();
int		get_hour(t_explo *);
int		get_minute(t_explo *, int);

/*
**	             __ day_night.c __
*/
void		draw_game_time(t_explo *);
void		change_day_time_morning(t_explo *, int);
void		change_day_time_night(t_explo *, int);
int		game_time(t_explo *);

/*
**	             __ cursor.c __
*/
void		draw_cursor_text(t_explo *, sfVector2f, t_inv *);
void		draw_cursor(t_inv *, t_explo *, sfVector2i, int *);
void		draw_chest_cursor(t_explo *, t_inv *);

/*
**	             __ module.c __
*/
int		check_dist(t_limit **, t_explo *, t_placed_mod *);
int		click_module(sfVector2f, t_explo *, t_limit **,
			     t_placed_mod *);
int		place_module(t_explo *, sfVector2f);

/*
**	             __ regen.c __
*/
void		regen_player(t_explo *);
int		regen(t_explo *);

/*
**	             __ init_circle.c __
*/
sfCircleShape	**init_circle(t_explo *);

/*
**	             __ use_item.c __
*/
int		check_use(t_explo *, sfVector2i, sfVector2f);

/*
**	             __ corner_change_id.c __
*/
int		is_corner_down_left(int **, sfVector2i, int, int);
int		is_corner_down_right(int **, sfVector2i, int, int);
int		is_corner_up_right(int **, sfVector2i, int, int);
int		is_corner_up_left(int **, sfVector2i, int, int);

/*
**	             __ change_map_id.c __
*/
int		**change_id(int **, sfVector2i);

/*
**	             __ init_floor.c __
*/
sfSprite	**init_ore_first();
sfSprite	**init_ore_second();
sfSprite	**init_floor_first();
sfSprite	***init_floor();

/*
**	             __ draw_map.c __
*/
void		draw_sprite_map(t_explo *, sfVector2i);
void		draw_map(t_explo *);

/*
**	             __ check_inv.c __
*/
int		del_item_inv_quantity(t_inv ***, sfVector2i, int *);
int		use_inv_item(t_inv ***, int, int);
sfVector2i	inv_has_place(t_explo *, int);
int		inv_contain(t_explo *, int);

/*
**	             __ draw_craft_inv_utils.c __
*/
int		draw_item_craft(t_explo *, int, int);
int		is_craftable(t_explo *, int);
int		draw_arrow(t_explo *, int, int);

/*
**	             __ draw_craft_inv.c __
*/
int		draw_frame(t_explo *, int, int, sfVector2f);
int		draw_needed_ammount(t_explo *, int, int, sfVector2f);
int		draw_needed_item(t_explo *, int, int);
void		draw_craft_inv(t_explo *, int);

/*
**	             __ craft_inv.c __
*/
int		del_from_inv(t_explo *, int);
int		check_clicked_craft(t_explo *);
int		craft_item(t_explo *, int);
void		craft_inventory(t_explo *);

/*
**	             __ placed_module.c __
*/
t_placed_mod	*add_to_placed(sfVector2i, sfVector2i, int, t_placed_mod *);
t_placed_mod	*del_from_placed(t_placed_mod *, sfVector2i);

/*
**	             __ init_craft_module_other_.c __
*/
t_module	*init_laser(t_module *);

/*
**	             __ init_craft_module_other.c __
*/
t_module	*init_fusion(t_module *);
t_module	*init_chest(t_module *);
t_module	*init_drill(t_module *);
t_module	*init_carbon(t_module *);
t_module	*init_glass(t_module *);

/*
**	             __ init_craft_module.c __
*/
t_module	*init_solar(t_module *);
t_module	*init_coal(t_module *);
t_module	*init_launcher(t_module *);
t_module	*init_central(t_module *);
void		init_craft_module(t_module **);

/*
**	             __ init_hud.c __
*/
sfSprite	**init_hud();

/*
**	             __ draw_hud.c __
*/
void		draw_hp(t_explo *);
void		draw_power(t_explo *);
void		draw_oxygen(t_explo *);
void		draw_hud_bar(t_explo *);
void		draw_hud_sprite(t_explo *);

/*
**	             __ gen_utils.c __
*/
int		init_ore_is_unvalide(char **, sfVector2i);
int		gen_pos_is_unvalide(sfVector2i, sfVector2i, char **, int);

/*
**	             __ init_ore.c __
*/
sfVector2i	gen_init_pos_filament(char **, sfVector2i, int);
void		gen_other_filament(char **, sfVector2i, sfVector2i, int);
char		**gen_filament(char **, sfVector2i, sfVector2i, sfVector2i);
char		***init_ore(t_config *);

/*
**	             __ check_config.c __
*/
int		check_config_other(char *, t_config *);
int		check_config(char *, t_config *);

/*
**	             __ config_file.c __
*/
char		*get_line_check(int);
int		check_end_config_file(int, char *);
int		config_file_is_valide(char *);

/*
**	             __ init_item.c __
*/
sfSprite	**init_item();
sfSprite	**init_module_item();

/*
**	             __ gif.c __
*/
void		draw_gif(t_explo *, int *, sfVector3f, sfVector2i);

/*
**	             __ init_gif.c __
*/
char		*new_cat(char *, char *);
sfSprite	**create_gif(char *, int);
sfSprite	***init_gif();

/*
**	             __ init_sprite_other.c __
*/
sfSprite	**init_other_other_other_sprite(sfSprite **);
sfSprite	**init_other_other_sprite(sfSprite **);
sfSprite	**init_other_sprite(sfSprite **);

/*
**	             __ init_sprite.c __
*/
void		init_pos_sprite(t_explo *);
sfSprite	**init_sprite();
sfSprite	**init_placed_sprite();

/*
**	             __ time.c __
*/
unsigned long long	get_time();

/*
**	             __ move.c __
*/
sfVector2f	get_dir_with_map(sfVector2f, sfVector2i, sfVector2f, int **);
int		move(t_explo *);

/*
**	             __ clicked_pos.c __
*/
sfVector2i	check_clicked_pos_equ(t_explo *);
sfVector2i	check_clicked_pos(t_explo *);

/*
**	             __ clicked.c __
*/
void		change_move_pos(t_explo *);
int		get_obj_clicked_left(t_explo *);
int		get_obj_clicked_right(t_explo *);

/*
**	             __ inventory_utils.c __
*/
int		add_item_full_stack(t_explo *, sfVector2i, sfVector2i);
int		add_item(t_explo *, sfVector2i, sfVector2i);
int		click_trash(t_explo *);
void		draw_name_item(t_explo *, int, sfVector2i);

/*
**	             __ inventory.c __
*/
int		swap_item(t_explo *, sfVector2i, sfVector2i);
int		change_item_pressed(t_explo *, sfVector2i, t_inv *, int *);
int		change_item(t_explo *, int *);
int		inventory(t_explo *);

/*
**	             __ event.c __
*/
int		wait_key(sfRenderWindow *, sfKeyCode);
int		wait_mouse(sfRenderWindow *);
int		get_event();

/*
**	             __ clear.c __
*/
void		clear_sprite(sfSprite **);
void		clear_tab(char **);
void		clear_ore(char ***);
void		clear_ressources(t_explo *);

/*
**	             __ game.c __
*/
int		game_event(t_explo *);
int		start_game(t_explo *);
int		game(t_explo *);

/*
**	             __ draw_inventory.c __
*/
void		draw_inv_equ(t_explo *, int);
void		draw_inv_top(t_explo *, int, int);
void		draw_item_inv(t_explo *, sfVector2i);
void		draw_inventory(t_explo *, sfVector2i, int *);

/*
**	             __ draw_detail.c __
*/
int		draw_home(t_explo *);
int		draw_perso(t_explo *);
int		draw_click(t_explo *);

/*
**	             __ draw_cpt.c __
*/
int		init_draw_cpt_y(t_explo *);
int		init_draw_cpt_x(t_explo *);
sfVector2i	init_draw_max(t_explo *);

/*
**	             __ draw_placed.c __
*/
void		init_placed_draw(t_placed_mod *);
void		draw_undraw_placed(t_explo *, t_placed_mod *);
void		draw_placed(t_explo *, t_placed_mod *, sfVector2f);

/*
**	             __ draw.c __
*/
void		draw_floor(t_explo *);
void		draw_rest(t_explo *);
void		draw_all(t_explo *);
void		draw(t_explo *);

/*
**	             __ rock.c __
*/
t_pos		*link_pos_rock(t_pos *, sfVector2i, t_game *, t_config *);
t_pos		*init_list_rock(int, sfVector2i, t_game *, t_config *);

/*
**	             __ fire.c __
*/
t_pos		*link_pos_fire(t_pos *, sfVector2i, t_game *, t_config *);
t_pos		*init_list_fire(int, sfVector2i, t_game *, t_config *);

/*
**	             __ mountain.c __
*/
t_pos		*link_pos_mountain(t_pos *, sfVector2i, t_config *);
t_pos		*init_list_mountain(int, sfVector2i, t_config *);

/*
**	             __ gen_procedural.c __
*/
int		contain_not_gen(int **);
sfVector2i	gen_pos_radius(sfVector2i, int);
int		**change_biome(int **, sfVector2i *, sfVector2i);
int		**gen_biome_part(int, int **, sfVector2i);
int		**gen_biome(int **, sfVector2i);

/*
**	             __ map.c __
*/
int		not_placeable(t_pos *, sfVector2i, sfVector2i, t_config *);
int		**fill_map(t_config *, int **);
int		**init_map(t_config *);

/*
**	             __ config.c __
*/
char		*re_alloc(char *);
char		*get_next_line(const int);
int		get_line_config(int);
t_config	*init_config(char *);

/*
**	             __ init_player.c __
*/
t_player	*init_player();
t_inv		***init_inv();

/*
**	             __ init_limit.c __
*/
t_limit		**init_move_pos();
t_limit		**init_limit();
t_placed_mod	*init_placed(t_config *);

/*
**	             __ init_game.c __
*/
t_game		*init_game_other(t_game *, t_config *);
t_game		*init_game(t_config *);
t_module	**init_module(t_config *);

/*
**	             __ init_explo.c __
*/
t_explo		*init_explo(char *);
sfView		*init_view(t_player *);
sfText		*init_text(sfFont *);
t_graph		*init_graph(t_player *);

/*
**	             __ utils.c __
*/
sfCircleShape	*create_circle(sfVector2f, sfColor, int);
char		**fill_map_c(t_config *, char **);
sfVector2f	vector2f(double, double);
sfVector3f	vector3f(double, double, double);
sfVector2i	vector2i(int, int);

/*
**	             __ message.c __
*/
int		error_config_file(char *, int);
int		msg_error(char *, char *);
int		no_file(char *, char *);
int		usage(char *);

/*
**	             __ tools.c __
*/
int		use_food(t_explo *, sfVector2i);
int		get_dist_btw(sfVector2f, sfVector2f);
int		my_rand(int, int);
sfSprite	*load_picture(char *);

/*      __________ ________________________ __________
**
**                    LIBRARY #GRAPHIC
**      __________ ________________________ __________
*/
sfUint8			*create_pixel_buffer(int width, int height);
sfRenderWindow		*create_window(char *name, int width, int height);
t_my_framebuffer	*my_framebuffer_create(int width, int height);
void			my_put_pixel(t_my_framebuffer *framebuffer,
                                     int y, int x, sfColor color);
void			refresh(t_graph *);
void			clear_screen(t_graph *);

/*      __________ ________________________ __________
**
**                        LIBRARY #C
**      __________ ________________________ __________
*/

t_list	*my_rev_list(t_list *list);
t_list	*my_link_list(t_list *list, char *data);
t_list	*my_list_cpy(t_list *list);
int	my_list_size(t_list *begin);
int	my_list_is_empty(t_list *liste);
void	my_print_list(t_list *liste);

int	my_getnbr(char *);
int	my_decimal_to_octal(int nb);
int	my_strlen(char *str);
int	my_str_who_bigger(char *s1, char *s2);
int	my_str_to_int(char *str);
int	my_strcmp(char *a, char *b);
int	my_swap(int *a, int *b);

void	my_putstr_error(char *str);
void	my_putnbr(int nb);
void	my_putchar(char a);
void	my_putstr(char *str);

char	*my_int_to_str(int nb);
char	*my_str_maj(char *str);
char	*my_decimal_to_hexa(int nb);
char	*supp_0(char *str);
char	*my_revstr(char *str);

#endif /* ! EXPLO_H_ */
