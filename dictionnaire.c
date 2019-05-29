#include "dictionnaire.h"

void ChargerDico(Maj_t Maj[], const char * nom_fichier){
	FILE * fichier = NULL;
	char ligne[TAILLE_LIGNE];
	char mot[TAILLE_MOT];
	char traduction[TAILLE_MOT];
	
	fichier = fopen(nom_fichier,"r");
	
	if (fichier == NULL)
	{
		printf("erreur d'ouverture du dico\n");
		exit(0);
	}
	
	else
	{	
		while(fgets(ligne,TAILLE_LIGNE,fichier)) /* on utilise fgets pour détecter la fin du fichier car fgets retourne NULL lorsque il rencontre un problème */
		{
			ligne[strlen(ligne)-1]='\0';
			strcpy(mot,strtok(ligne,";"));
			strcpy(traduction,strtok(NULL,"\0"));
			printf("[ChargerDico] : mot== -%s- et traduction == -%s-\n", mot, traduction);
			Insertion(mot,traduction,Maj);
		}
		fclose(fichier);
	}
}

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
	else printf("Mot %s non trouvé :/\n",mot);
	return trouve;
}


/*Version Val
	else
	{	
		fgets(ligne,TAILLE_LIGNE,fichier);
		ligne[strlen(ligne)-1]='\0';
		strcpy(mot,strtok(ligne,";"));
		strcpy(traduction,strtok(NULL,"\0"));
		
		while(!feof(fichier))
		{
			printf("[ChargerDico] : mot== -%s- et traduction == -%s-\n", mot, traduction);
			Insertion(mot,traduction,Maj);
			fgets(ligne,TAILLE_LIGNE,fichier);
			ligne[strlen(ligne)-1]='\0';
			printf("-------------------%s----------------------",ligne); //
			strcpy(mot,strtok(ligne,";"));
			strcpy(traduction,strtok(NULL,"\0")); //problème ---> voir valgrind
		}
		fclose(fichier);
	}
	* 
*/
