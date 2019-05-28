#include "hachage.h"



/*----------------------
 * hash_string : 
 * 
 * 
 -------------------------*/ 

unsigned int hash_string(const char *str)
{ 
  unsigned int hash = 5381;                /*  fonction de hachage de D.J. Bernstein*/
  const char *s;
  for (s = str; *s; s++)
 	 hash = ((hash << 5) + hash) + tolower(*s);
  return (hash & 0x7FFFFFFF)%HASH_MAX;
}


/*---------------
 * Insertion : 
 * 
 ---------------*/

void Insertion(const char *str,const char * traduction, Liste_t Maj[]){
	unsigned int indice = hash_string(str);
	int taille_m = strlen(str);
	int taille_t = strlen(traduction);
	Maillon_t * pt_nouv = NULL;
	pt_nouv = (Maillon_t*)malloc(sizeof(Maillon_t));
	pt_nouv->mot =(char*)malloc(taille_m*sizeof(char));
	pt_nouv->trad =(char*)malloc(taille_t*sizeof(char));
	
	if (pt_nouv==NULL || pt_nouv->mot==NULL || pt_nouv->trad==NULL){ /* allocation a échouée */
		printf("problème d'allocation\n");
		exit(1); /* on sort du code */
	}
	if (Maj[indice]!=NULL){
		pt_nouv->suiv = Maj[indice];
	}
	Maj[indice] = pt_nouv;
	strcpy(pt_nouv->mot,str);
	strcpy(pt_nouv->trad, traduction);
}

/*---------
 * 
 ----------*/

void InitTab(Liste_t * tab, int taille){
	int i=0;
	for(i=0;i<taille;i++){
		tab[i]=NULL;
	}
}








