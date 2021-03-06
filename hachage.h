#ifndef HACHAGE
#define HACHAGE

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define HASH_MAX 29


/*----------------------------------------------------------------------------------------
 * Maillon_t = cellule contenant le mot, sa traduction et un pointeur suiv pour chainer.
 *
 *  Liste_t = pointeur sur un Maillon_t.
 ----------------------------------------------------------------------------------------*/

typedef struct Maillon_s{
	char * mot;
	char * trad;
	struct Maillon_s * suiv;
} Maillon_t, * Liste_t;


/*----------------------------------------------------------------------------------
 * Maj_t = élément de la table majeur constitué de la sous table et de son compteur
 -----------------------------------------------------------------------------------*/ 

typedef struct maj_s{
	Liste_t sousTable;
	int 	cmpt;
}Maj_t;


unsigned int hash_string(const char *str);
void Insertion(char *mot, char * traduction, Maj_t Maj[]);
void InitTab(Maj_t * tab, int taille);
bool RechercheMot(Maj_t maj[], char * mot, Maillon_t ** pt);
void LibMaj(Maj_t Maj[]);
void LibSousTable(Liste_t SousTable);
void TailleMoy(Maj_t maj[]);
void affichageMaj(Maj_t maj[]);
#endif
