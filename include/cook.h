/*
** EPITECH PROJECT, 2017
** cook.h
** File description:
** header file for my cook
*/
#ifndef COOK_H_
#define COOK_H_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Audio/Music.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Time.h>
#include <stddef.h>
#include "list.h"
#include "enum.h"
#include "define.h"
#include "my.h"

typedef struct node screen;
typedef struct node obj_list;

struct	music {
	sfMusic		*music;
};

struct sound {
	sfSoundBuffer	*buffer;
	sfSound		*sound;
};

struct	text {
	sfText		*text;
	sfVector2f	text_pos;
	sfFont		*font;
	char		*string;
	int		points;
	int		counter;
};

struct	sprite {
	sfSprite	*sprite;
	sfVector2f	speed;
	sfTexture	*texture;
	sfIntRect	*rect;
	int		current_anim;
	int		nb_anim;
};

struct game {
	screen			*screens[SCREEN_SIZE];
	enum screen_type	current_screen;
	enum screen_type	previous_screen;
	struct game_object	*order[MAX_ING];
	struct game_object	*valid[2];
	struct	game_object	*ingredients[MAX_ING];
	struct game_object	*all_ing[ALL_ING];
	struct	game_object	*player;
	sfClock			*clock;
	sfRenderWindow		*window;
	struct sound		*sound_effect[2];
	bool			pause;
	bool			check;
	bool			send_order;
	bool			score;
	int			count;
	int			nb_client;
	int			client_num;
	int			nb_of_scoop;
};

struct game_object {
	void		*obj;
	enum obj_type	type;
	enum letter	letter;
	enum button_type button_type;
	void		(*ptr_move)(struct game_object *obj,
	struct game *cook);
	void		(*ptr_display)(struct game_object *obj,
	struct game *cook);
};

// Event
int	check_event(struct game *cook, sfEvent event, sfKeyCode key,
	int (*ptr)(struct game *));
int	check_play(struct game *cook, struct game_object *obj,
	sfMouseButtonEvent event);
int	check_exit(struct game *cook, struct game_object *obj,
	sfMouseButtonEvent event);
int	check_help(struct game *cook, struct game_object *obj,
	sfMouseButtonEvent event);
int	check_back(struct game *cook, struct game_object *obj,
	sfMouseButtonEvent event);
int	check_menu(struct game *cook, struct game_object *obj,
	sfMouseButtonEvent event);
int	handle_event(struct game *cook);
int	analyse_event(struct game *cook, sfEvent event);
void	change_scale(struct sprite *img, int count);
int	check_skip(struct game *cook, struct game_object *obj,
	sfMouseButtonEvent event);


// Keys
int	key_escape(struct game *cook);
int	key_o(struct game *cook);
int	key_tt(struct game *cook);
int	key_p(struct game *cook);
int	key_v(struct game *cook);
int	key_c(struct game *cook);
int	key_s(struct game *cook);
int	key_h(struct game *cook);
int	key_return(struct game *cook);
int	key_space(struct game *cook);

// Create functions
struct	game_object *create_music(char *path);
struct	game_object *create_text(char *path, sfVector2f pos,
int size, int color);
void	create_rect_tab(struct sprite *obj, sfIntRect size);
struct	game_object	*create_sprite(char const *path_to_spritesheet,
	enum obj_type type, int nb_anim, sfIntRect size);
sfRenderWindow	*create_my_window(int width, int height);
struct game_object *create_sound(char *path, enum obj_type type);

// Init functions
void	init_menu_screen(struct game *cook);
void	init_game(struct game *cook);
struct game_object *init_background(sfVector2f pos, char *path,
	enum obj_type type);
struct game_object	*init_button(char *path, sfVector2f pos,
	enum obj_type type, sfVector2f scale);
void	init_pause_screen(struct game *cook);
void	init_help_screen(struct game *cook);
void	init_player(struct game *cook);
struct game_object	*init_ingredient(char *path, sfVector2f pos,
	enum letter letter, sfVector2f scale);
void	init_tab(struct game *cook);
void	init_target(struct node **head, int target);
void	init_victory_screen(struct game *cook);
void	init_smiley(struct game *cook);
void	init_all_ing(struct game *cook);
void	init_valid(struct game *cook);
void	init_intro_screen(struct game *cook);
void	init_music(struct node **head, char *path);
void	init_sound(struct game *cook, int i, char *path);
void	init_clock(struct node **head);
void	init_defeat_screen(struct game *cook);

// Display functions
void	display_sprite(struct game_object *obj, struct game *cook);
void	display_text(struct game_object *obj, struct game *cook);
void	play_music(struct game_object *obj, struct game *cook);
void	play_sound(struct game_object *obj, struct game *cook);
void	display_button(struct game_object *obj, struct game *cook);
void	display_ingredient(struct game *cook);
void	display_null(struct game_object *obj, struct game *cook);
void	display_order(struct game *cook);
void	display_player(struct game *cook);
void	display_valid(struct game *cook);
void	display_intro(struct game_object *obj, struct game *cook);
void	display_head(struct node *head, struct game *cook);

// Move functions
bool	check_client_stop(struct game_object *obj, int nb_client);
void	move_client(struct game_object *obj, struct game *cook);
void	exit_client(struct game_object *obj, struct game *cook);
void	move_null(struct game_object *obj, struct game *cook);
void	move_anim(struct game_object *obj, struct game *cook);
void	move_background(struct game_object *obj, struct game *cook);
void	decrement_counter(struct game_object *obj, struct game *cook);

// Text functions
void	set_color(struct text *score, int color);
void	increment_score(struct game_object *obj, struct game *cook);
struct	game_object *init_text(sfVector2f pos, int size, int color, char *text);
void	init_points(struct node **head);
char	*add_space(char *str);

// Clean up
void	clean_up(struct game *cook);
void	free_tab(struct game *cook);
void	free_ing(struct game *cook);

// Error handling
int	errors(char **envp);

// Game Functions
int	my_cook(struct game *cook);
void	generate_order(struct game *cook);
bool	compare_order(struct game *cook);
bool	end_game(struct game *cook, struct game_object *obj);
void	*get_obj(struct game *cook, enum obj_type type, enum screen_type screen);

// Math functions
bool	check_click(sfFloatRect *rect, float x, float y);
bool	get_click(struct game_object *obj, float x, float y);
sfIntRect	ret_int_rect(float top, float left, float width, float height);
sfVector2f	ret_vec(float y, float x);
bool	get_over(struct game_object *obj, sfVector2i i);
int generate_nbr(struct game *cook, int min, int max);

#endif /* !COOK_H_ */