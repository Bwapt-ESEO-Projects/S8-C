#include "map.h"
#include "player.h"
#include "treasure.h"
#include "trap.h"
#include "pirate.h"
#include "types.h"

void game_init(Trap* traps[], Pirate* pirates[]);

void game_map_init(void);

void game_player_init(void);

void game_treasure_init(void);

void game_traps_init(Trap* traps[]);

void game_pirates_init(Pirate* pirates[]);

void game_trap_init(Trap* trap);

void game_pirate_init(Pirate* pirate);

void game_move_pirates(Pirate* pirates[]);

bool game_check_win(coordinate player, coordinate treasure);

bool game_check_trap(coordinate player, coordinate trap);

bool game_check_pirate(coordinate player, coordinate pirate);

void game_turn_reset(Pirate* pirates[]);

void game_check_ennemy(Trap* traps[], Pirate* pirates[]);

bool game_check_end(void);

void game_print(void);

void game_end(bool victory);

void game_free(Trap* traps[], Pirate* pirates[]);