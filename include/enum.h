/*
** EPITECH PROJECT, 2018
** enum.h
** File description:
** enum header file
*/

#ifndef ENUM_H_
#define ENUM_H_

enum	letter {
	KEY_O,
	C,
	S,
	P,
	H,
	V,
	T
};

enum button_type {
	OVER,
	CLICK,
	NORMAL
};

enum obj_type {
	CLIENT,
	PLAY,
	EXIT,
	OK,
	WRONG,
	SKIP,
	SOUND_WRONG,
	SOUND_VALID,
	HELP_BUTTON,
	MENU_BUTTON,
	BACKGROUND,
	TARGET,
	SCORE,
	COUNTER,
	BACK,
	TEXT,
	MUSIC,
	SOUND,
	LAST
};

enum screen_type {
	INTRO,
	MENU,
	GAME,
	VICTORY,
	DEFEAT,
	PAUSE,
	HELP,
	SCREEN_SIZE
};

#endif /* !ENUM_H_ */