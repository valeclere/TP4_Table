#include "hachage.h"

/*------------------------------------------------------------------------
 * hachage : module contenant toutes les fonctions pour manipuler la table
 -------------------------------------------------------------------------*/

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
	
	if(Maj!=NULL && mot[0]!='\0' && traduction[0]!='\0'){
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
	else{
		printf("Le tableau majeur n'a pas été initialisé!!!\n");
		printf("----OU----\n");
		printf("Le mot ou la traduction est vide\n");
	}
}


/*-----------------------------------------------------------------
 * InitTab : fonction qui permet d'initialiser la Table MAJ à NULL
 * Entrée : tab = la table majeure, taille = taille de MAJ
 ------------------------------------------------------------------*/

void InitTab(Maj_t * tab, int taille)
{
	int i=0; /* indice de parcours */
	for(i=0;i<taille;i++)
	{
		tab[i].sousTable = NULL; /* initialisation des sous tables */
		tab[i].cmpt = 0; /* initialisation du compteur de la sous table */
	}
}

/*-------------------------------------------------------------------------
 * RechercheMot : permet de rechercher une valeur dans la table
 * Entrée :
 * 		- maj = table majeure
 * 		- mot = valeur cherchée
 * 		- pt = pointeur sur la cellule si la valeur est trouvée
 * Sortie :
 * 		- trouve = booleen qui vaut true si le mot est trouvé false sinon
 -------------------------------------------------------------------------*/

bool RechercheMot(Maj_t maj[], char * mot, Maillon_t ** pt){
	unsigned int indice;
	bool trouve=false;  /*boolean qui permet d'indiquer si oui ou non on a trouvé le mot*/
	Liste_t tmp; /* pointeur de sous table qui permet de la parcourir */
	if(mot[0]!='\0' && maj!=NULL && pt != NULL){
		indice = hash_string(mot); /* on récupère l'indice de la sous table dans laquelle peut être le mot */
		tmp = maj[indice].sousTable;
		while(tmp!=NULL && strcmp(tmp->mot,mot)!=0 ){ /* on parcourt la sous table tant qu'on ne trouve pas le mot */
			tmp=tmp->suiv;
		}
		
		if(tmp!=NULL){ /* si on est pas à la fin de la sous table c'est qu'on a trouvé le mot */
			trouve = true;
			*pt = tmp; /* on stocke la cellule dans le pointeur en paramètre */
		}
	}
	else{
		printf("***Mot vide, table vide ou  pt non déclaré!!!***\n"); /* la table majeure est vide */
	}
	return trouve;
}


/*-----------------------------------------------
 * Libérer Maj : libération de la table majeure
 * Entrée : Maj = table majeure
 *-----------------------------------------------*/
 
void LibMaj(Maj_t Maj[])
{
	int i=0;
	for (i=0;i<29;i++)
	{
		if (Maj[i].sousTable!=NULL) /* s'il il y a une sous table */
		{
			LibSousTable(Maj[i].sousTable); /* on libère une sous table */
		}
	} 
	  
}

/*--------------------------------------------------
 * Liberer Sous Table : libération de la sous table
 * Entrée : SousTable = pointeur sur la sous table
 *--------------------------------------------------*/
 
void LibSousTable(Liste_t SousTable)
{
	
	Maillon_t * prec = SousTable;
	Maillon_t * cour = SousTable->suiv;
	
	while(cour!=NULL) /* parcours dans la sous table */
	{
		free(prec->mot); /* on libère le mot */
		free(prec->trad); /* on libère la traduction */
		free(prec); /* puis on libère la cellule */
		prec=cour;
		cour=cour->suiv; /* on se déplace sur la cellule suivante */
	}
	free(prec->mot);
	free(prec->trad);
	free(prec);
}



/*------------------------------------------------------------------
 * TailleMoy : permet d'afficher la taille moyenne des sous tables
 * Entrée : maj = table majeure
 -----------------------------------------------------------------*/

	 
void TailleMoy(Maj_t maj[])
{
	int somme = 0, i=0; /* somme = nombre total de mots dans les sous tables, i=indice tableau */
	float moyenne = 0; /* moyenne à afficher */
	if(maj!=NULL){
	for(i=0;i<29;i++)
	{
		somme+= maj[i].cmpt; /*on somme avec les valeurs dans les compteurs */
	}
	moyenne = somme/29.0;
	printf("\nPour ce dico, la taille moyenne des sous tables est : %.2f\n", moyenne);
	}
	else
	{
		printf("La table est vide donc impossible de calculer la moyenne :/\n"); /* si la table majeur est vide */
	}
}			



/*----------------------------------------------------------------------
 * affichageMaj : permet l'affichage de toutes les valeurs de la table
 * Entrée : maj = table majeure
 ----------------------------------------------------------------------*/ 
	 
void affichageMaj(Maj_t maj[])
{
	int i=0;
	int compteur=0; /* variable pour compter le nombre total de traductions (cellules) */
	Liste_t cour=NULL;
	for(i=0;i<29;i++){
		cour=maj[i].sousTable;
		while(cour!= NULL){ /* parcours de la sous table */
			printf("Mot: %s --> Traduction: %s\n",cour->mot,cour->trad);
			cour=cour->suiv;
			compteur++;
		}
	}
	printf("Ce dico contient %d traduction(s)\n",compteur); /* affichage du nombre de traductions */
}	 
	 
	 

