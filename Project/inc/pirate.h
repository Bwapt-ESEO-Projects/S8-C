#ifndef _PIRATE_H
#define _PIRATE_H

#include "types.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Pirate_t Pirate;

extern void pirate_init(Pirate *pirate);

extern coordinate pirate_get_pos(Pirate *pirate);

extern bool pirate_movement(Pirate *pirate, coordinate player);

extern bool pirate_get_all_can_move(Pirate *pirates[]);

extern void pirate_set_all_can_move(Pirate *pirates[], bool can_move);

extern bool pirate_get_can_move(Pirate *pirate);

extern void pirate_set_can_move(Pirate *pirate, bool can_move);

extern char pirate_load_current_case(Pirate *pirate);

extern void pirate_store_current_case(Pirate *pirate, char c);

struct Pirate_t *pirate_new(void);

extern void pirate_free(Pirate *pirate);

#endif