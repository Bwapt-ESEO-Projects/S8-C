#ifndef _MAP_H
#define _MAP_H

#include <stdint.h>
#include <stdbool.h>

#include "types.h"

extern void map_init(void);
extern void map_print();
extern char map_get_case(int x, int y);
extern void map_set_case(int x, int y, char c);
extern bool map_is_empty(int x, int y);

extern void map_new(void);
extern void map_free();

#endif