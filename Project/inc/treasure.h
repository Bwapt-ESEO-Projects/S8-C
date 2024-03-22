#ifndef _TREASURE_H
#define _TREASURE_H

#include <stdint.h>
#include <types.h>

extern void treasure_new(void);
extern void treasure_free(void);
extern void treasure_init(void);
extern coordinate treasure_get_pos(void);

#endif