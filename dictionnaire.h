#ifndef DICO
#define DICO

#include "hachage.h"
#define TAILLE_LIGNE 100
#define TAILLE_MOT 50


void ChargerDico(Maj_t Maj[], const char * nom_fichier);
void SaisirChoix(int * pt_choix);
void Traduction();

#endif
