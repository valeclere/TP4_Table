#ifndef HACHAGE
#define HACHAGE

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define HASH_MAX 29

typedef struct Maillon_s{
	char * mot;
	char * trad;
	struct Maillon_s * suiv;
} Maillon_t, * Liste_t;

unsigned int hash_string(const char *str);
void Insertion(const char *str,const char * traduction, Liste_t Maj[]);
void InitTab(Liste_t * tab, int taille);
#endif
