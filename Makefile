##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## A Makefile for projetcs
##
CC	=	gcc

RM	=	rm -rf

CFLAGS	+=	-Wall -Wextra

CFLAGS	+=	-I./include

NAME	=	my_cook

SRCS	=	srcs/my_cook/main.c \
		srcs/my_cook/entity/create.c \
		srcs/my_cook/entity/display.c \
		srcs/my_cook/entity/display_ingredient.c \
		srcs/my_cook/entity/display_valid.c \
		srcs/my_cook/entity/display_player.c \
		srcs/my_cook/entity/sound.c \
		srcs/my_cook/entity/get_obj.c \
		srcs/my_cook/entity/move.c \
		srcs/my_cook/entity/score.c \
		srcs/my_cook/entity/text.c \
		srcs/my_cook/math/math.c \
		srcs/my_cook/math/generate_nbr.c \
		srcs/my_cook/game/clean_up.c \
		srcs/my_cook/game/free.c \
		srcs/my_cook/game/end_game.c \
		srcs/my_cook/game/event.c \
		srcs/my_cook/game/check_event.c \
		srcs/my_cook/game/check_keys.c \
		srcs/my_cook/game/check_keys_extra.c \
		srcs/my_cook/game/check_mouse.c \
		srcs/my_cook/game/error.c \
		srcs/my_cook/game/client.c \
		srcs/my_cook/game/clock.c \
		srcs/my_cook/game/create_window.c \
		srcs/my_cook/game/my_cook.c \
		srcs/my_cook/init/init_game.c \
		srcs/my_cook/init/init_menu.c \
		srcs/my_cook/init/init_valid.c \
		srcs/my_cook/init/init_intro.c \
		srcs/my_cook/init/init_pause.c \
		srcs/my_cook/init/init_help.c \
		srcs/my_cook/init/init_player.c \
		srcs/my_cook/init/init_victory.c \
		srcs/my_cook/init/init_defeat.c \
		srcs/my_cook/init/init_sound.c \
		srcs/my_cook/init/init_ingredients.c \
		srcs/my_cook/init/init_sprite.c \
		srcs/lists/create_list.c \
		srcs/lists/display_list.c \
		srcs/lists/free_list.c \
		srcs/lists/my_sort_list.c

OBJS	=	$(SRCS:.c=.o)

LIB =		-L./lib -lmy

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./lib/my
	$(CC) $(OBJS) -o $(NAME) $(LIB) -lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio

clean:
	$(RM) $(OBJS)
	make -C ./lib/my clean

fclean: clean
	$(RM) $(NAME)
	$(RM) lib/*.a
	make -C ./lib/my fclean


re: fclean all

.PHONY: all clean fclean re
