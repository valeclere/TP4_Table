#ifndef DICO
#define DICO

#include "hachage.h"
#include <stdbool.h>
#define TAILLE_LIGNE 100
#define TAILLE_MOT 50


void ChargerDico(Maj_t Maj[], const char * nom_fichier);
bool RechercheMot(Maj_t maj[], char * mot, Maillon_t ** pt);

#endif
