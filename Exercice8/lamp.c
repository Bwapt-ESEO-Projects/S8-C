#include "lamp.h"

typedef enum
{
    OFF,
    ON
} EtatLampe;

static EtatLampe etat;

extern void Lampe_boutON()
{
    if (etat == OFF)
    {
        etat = ON;
        Ampoule_allumer();
    }
}

extern void Lampe_boutOFF()
{
    if (etat == ON)
    {
        etat = OFF;
        Ampoule_eteindre();
    }
}
extern void Lampe_new()
{
    TRACE("Construction etat %d \n", etat);
    etat = OFF;
    Ampoule_new();
}
extern void Lampe_free()
{
    TRACE("Destruction \n");
    Ampoule_free();
    etat = OFF;
}