#include "hachage.h"



/*-------------------------------------------------------------------------
 * hash_string : fonction de hachage
 * Entrée : clé chaine de caractère
 * Sortie : indice correspondant à la position de la sous table dans MAJ
 -------------------------------------------------------------------------*/ 

unsigned int hash_string(const char *str)
{ 
  unsigned int hash = 5381;                /*  fonction de hachage de D.J. Bernstein*/
  const char *s;
  for (s = str; *s; s++)
 	 hash = ((hash << 5) + hash) + tolower(*s);
  return (hash & 0x7FFFFFFF)%HASH_MAX;
}


/*----------------------------------------------------------------------------------------------------
 * Insertion : insère le mot et la traduction dans la sous table obtenue avec la fonction de hachage
 * Entrée : mot (=clé), traduction, le tableau MAJ (table majeure) qui contient les sous tables
 ----------------------------------------------------------------------------------------------------*/

void Insertion(char *mot, char * traduction, Maj_t Maj[])
{
	unsigned int indice = hash_string(mot); /*on récupère l'indice correspondant à la position de la sous table dans MAJ*/
	int taille_m = strlen(mot);
	int taille_t = strlen(traduction);
	Maillon_t * pt_nouv = NULL;
	
	pt_nouv = (Maillon_t*)malloc(sizeof(Maillon_t)); /* allocation d'un maillon qui contient le mot, la traduction et un pointeur sur le maillon suivant */
	pt_nouv->mot = (char*)malloc((taille_m+1)*sizeof(char));
	pt_nouv->trad = (char*)malloc((taille_t+1)*sizeof(char));
	
	strcpy(pt_nouv->mot,mot);
	strcpy(pt_nouv->trad, traduction);
	pt_nouv->suiv = NULL;
	
	if (pt_nouv==NULL || pt_nouv->mot==NULL || pt_nouv->trad==NULL) /* allocation a échouée */
	{ 
		printf("problème d'allocation\n");
		exit(1); /* on sort du code */
	}
	if (Maj[indice].sousTable!=NULL) /* si la sous table existait déjà on chaine avec le nouveau maillon */
	{ 
		pt_nouv->suiv = Maj[indice].sousTable;
	}
	Maj[indice].sousTable = pt_nouv; /* on insère le nouveau maillon en début de sous table */
	Maj[indice].cmpt++; 		      /*incrémentation du compteur de la sous table*/
}

/*-----------------------------------------------------------------
 * InitTab : fonction qui permet d'initialiser la Table MAJ à NULL
 * Entrée : tab = La table majeure, taille = taille de MAJ
 ------------------------------------------------------------------*/

void InitTab(Maj_t * tab, int taille)
{
	int i=0;
	for(i=0;i<taille;i++)
	{
		tab[i].sousTable = NULL;
		tab[i].cmpt = 0;
	}
}

/*-----------------
 * RechercheMot
 ----------------*/

bool RechercheMot(Maj_t maj[], char * mot, Maillon_t ** pt){
	unsigned int indice = hash_string(mot);
	bool trouve=false;  /*boolean qui permet d'indiquer si oui ou non on a trouvé le mot*/
	Liste_t tmp = maj[indice].sousTable;
	
	while(tmp!=NULL && strcmp(tmp->mot,mot)!=0 ){
		tmp=tmp->suiv;
	}
	
	if(tmp!=NULL){
		trouve = true;
		*pt = tmp;
	}
	//else printf("Mot %s non trouvé :/\n",mot);
	return trouve;
}


/*-------------
 * Libérer Maj
 *-------*/
 
void LibMaj(Maj_t Maj[])
{
	int i=0;
	for (i=0;i<29;i++)
	{
		if (Maj[i].sousTable!=NULL)
		{
			LibSousTable(Maj[i].sousTable);
		}
	} 
	  
}

/*---------
 * Liberer Sous Table
 *------------*/
 
void LibSousTable(Liste_t SousTable)
{
	
	Maillon_t * prec = SousTable;
	Maillon_t * cour = SousTable->suiv;
	
	while(cour!=NULL)
	{
		printf("mot %s, trad %s\n",prec->mot,prec->trad);
		free(prec->mot);
		free(prec->trad);
		free(prec);
		prec=cour;
		cour=cour->suiv;
	}
	printf("mot %s, trad %s\n",prec->mot,prec->trad);
	free(prec->mot);
	free(prec->trad);
	free(prec);
}
	 
	 
	 
	 
	 
	 
	 
	 

