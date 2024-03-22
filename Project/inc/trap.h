#ifndef _TRAP_H
#define _TRAP_H

#include "types.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct Trap_t Trap;

extern void trap_init(Trap *trap);
extern coordinate trap_get_pos(Trap *trap);

struct Trap_t *trap_new(void);
extern void trap_free(Trap *trap);

#endif