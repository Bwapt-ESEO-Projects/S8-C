#ifndef _PLAYER_H
#define _PLAYER_H

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "types.h"

extern bool player_movement(direction d);
extern void player_init(void);
extern coordinate player_get_pos(void);
extern uint8_t player_get_life(void);
extern void player_set_life(uint8_t life);
extern void player_print_life(void);
extern char player_load_current_case(void);
extern void player_store_current_case(char c);

extern bool player_get_can_move(void);
extern void player_set_can_move(bool can_move);

extern void player_new(void);
extern void player_free(void);

#endif