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



/*----------------------------------
 * Traduction :
 * 
 ------------------------------------*/

void Traduction()
{
	Maj_t maj[29];
	int choixMenu = 0;
	char txt[TAILLE_TEXTE];
	//char txt_trad[];
	char tmp[TAILLE_MOT];
	Maillon_t * pt_maillon=NULL;
	
	SaisirChoix(&choixMenu);
	
	while (choixMenu<1 && choixMenu>6)
	{
		switch (choixMenu)
		{
			case 1:
				ChargerDico();
				break;
			case 2:
				
				break;
			case 3:
				
				break;
			case 4:
				
				break;
			case 5:
				
				break;
			case 6:
				
				break;
			default:
				printf("Erreur de saisie, saisir un nombre entre 1 et 6\n");
				SaisirChoix(&choixMenu);
		}	
	}
	
	printf("Saisir le texte à traduire :\n");
	fgets(txt,TAILLE_TEXTE,stdin);
	txt[strlen(txt)-1]='\0';
	
	while (txt[0]!='\0')
	{
		Rechercher(strtok(txt, " "),&pt_maillon);
		printf(" %s", pt_maillon->trad);
	}
	printf("\n");
}


//~ const char langueSource, const char langueCible, Maj_t Maj[], char * texte

/*------------------------------------------------------------------------
 * Tradution : récupérer le type de traduction choisi par l'utilisateur
 * Entrée : pointeur sur choix
 ------------------------------------------------------------------------*/

void SaisirChoix(int * pt_choix)
{
	printf("\nSaisir le type de traduction :\n");
	
	printf("1) Ang/Esp\n");
	printf("2) Ang/Fra\n");
	printf("3) Esp/Ang\n");
	printf("4) Esp/Fra\n");
	printf("5) Fra/Ang\n");
	printf("6) Fra/Esp\n");
	
	scanf("%d%*c", pt_choix);
	
}
