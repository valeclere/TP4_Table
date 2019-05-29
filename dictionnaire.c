#include "dictionnaire.h"

void ChargerDico(Liste_t Maj[], const char * nom_fichier){
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
