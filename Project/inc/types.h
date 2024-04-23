#ifndef _TYPES_H
#define _TYPES_H

#include <stdint.h>

#define PLAYER_SYMBOL 'j'
#define TREASURE_SYMBOL ' '
#define TRAP_SYMBOL ' '
#define PIRATE_SYMBOL 'p'
#define EMPTY_SYMBOL ' '

#define LIGNE 10
#define COLONNE 10

#define NB_TRAP 5
#define NB_PIRATE 2

typedef struct {
    uint8_t x;
    uint8_t y;
} coordinate;

typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT
} direction;

#endif