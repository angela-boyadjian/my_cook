/*
** EPITECH PROJECT, 2017
** init_game.c
** File description:
** init game functions
*/
#include "cook.h"

void	init_tab(struct game *cook)
{
	for (int i = 0; i < MAX_ING; ++i) {
		cook->ingredients[i] = malloc(sizeof(struct sprite *));
		cook->order[i] = malloc(sizeof(struct sprite *));
	}
	for (int i = 0; i < ALL_ING; ++i)
		cook->all_ing[i] = NULL;
}

void	init_game_screen(struct game *cook)
{
	screen	**head = &((cook->screens)[GAME]);

	*head = NULL;
	init_sound(cook, 0, "res/Music/valid.wav");
	init_sound(cook, 1, "res/Music/wrong.wav");
	insert_end(head, init_background(ret_vec(0, 0),
	"res/Game_scene/game.png", BACKGROUND));
	init_player(cook);
	insert_end(head, init_background(ret_vec(0, 0),
	"res/Game_scene/Counter.png", BACKGROUND));
	insert_end(head, init_text(ret_vec(10, 10), 35, 2, "time left: "));
	init_valid(cook);
	init_points(head);
	init_target(head, 100);
	init_clock(head);
	init_tab(cook);
	init_music(head, "res/Music/game.ogg");
	init_all_ing(cook);
}

void	init_game(struct game *cook)
{
	cook->window = create_my_window(1100, 825);
	sfRenderWindow_setFramerateLimit(cook->window, 80);
	cook->clock = sfClock_create();
	sfRenderWindow_setMouseCursorVisible(cook->window, sfTrue);
	cook->current_screen = INTRO;
	cook->previous_screen = INTRO;
	cook->count = 0;
	cook->nb_client = 0;
	cook->client_num = 0;
	cook->score = false;
	cook->check = false;
	cook->send_order = false;
	init_intro_screen(cook);
	init_menu_screen(cook);
	init_game_screen(cook);
	init_pause_screen(cook);
	init_help_screen(cook);
	init_victory_screen(cook);
	init_defeat_screen(cook);
}