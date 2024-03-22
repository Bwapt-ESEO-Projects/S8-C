typedef enum
{
    OFF_S = 0,
    ON_S
} Etat;

typedef enum
{
    BOUTOFF_E = 0,
    BOUTON_E,
    STOP_E
} Entree;

static Etat etatLampe;

// pour des raisons de lisibilité du transparent, les « extern » ne sont pas mis
void Lampe_boutON() 
{ 
    Lampe_run(BOUTON_E); 
}

void Lampe_boutOFF() 
{ 
    Lampe_run(BOUTOFF_E); 
}

void Lampe_new()
{ 
    /*allocation mémoire and co*/
} 
// parfois new et start sont joints
void Lampe_start() 
{ 
    etatLampe = OFF_S; 
}

void Lampe_stop() 
{ 
    Lampe_run(STOP_E); 
} 
// parfois free et stop sont joints
void Lampe_free()
{ 
    /*désallocation mémoire and co*/
}

void Lampe_run(Entree entreeLampe) /* version incomplète sans gestion du stop... */
{
    switch (etatLampe)
    {
    case OFF_S: /* Lampe éteinte */
        switch (entreeLampe)
        {
        case BOUTOFF_E:
            break;
        case BOUTON_E:
            etatLampe = ON_S;
            Ampoule_allumer();
            break;
        }
        break;
    case ON_S: /* Lampe allumée */
        switch (entreeLampe)
        {
        case BOUTOFF_E:
            etatLampe = OFF_S;
            Ampoule_eteindre();
            break;
        case BOUTON_E:
            break;
        }
        break;
    }
}