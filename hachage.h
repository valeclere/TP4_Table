#ifndef HACHAGE
#define HACHAGE

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define HASH_MAX 29
#define TAILLE_TEXTE 200

typedef struct Maillon_s{
	char * mot;
	char * trad;
	struct Maillon_s * suiv;
} Maillon_t, * Liste_t;

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

#endif
