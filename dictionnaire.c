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
	char * cour_txt=NULL;
	
	SaisirChoix(&choixMenu);
	
	while (choixMenu<1 && choixMenu>6)
	{
		switch (choixMenu)
		{
			case 1:
				ChargerDico(maj, "Ang_Esp.txt");
				break;
			case 2:
				ChargerDico(maj, "Ang_Fra.txt");
				break;
			case 3:
				ChargerDico(maj, "Esp_Ang.txt");
				break;
			case 4:
				ChargerDico(maj, "Esp_Fra.txt");
				break;
			case 5:
				ChargerDico(maj, "Fra_Ang.txt");
				break;
			case 6:
				ChargerDico(maj, "Fra_Esp.txt");
				break;
			default:
				printf("Erreur de saisie, saisir un nombre entre 1 et 6\n");
				SaisirChoix(&choixMenu);
		}	
	}
	
	printf("Saisir le texte à traduire :\n");
	fgets(txt,TAILLE_TEXTE,stdin);
	txt[strlen(txt)-1]='\0';
	strcpy(tmp, strtok_r(txt, " ", &cour_txt));

	
	while (cour_txt[0]!='\0')
	{
		printf("[Traduction] TMP====%s====\n",tmp);
		if (RechercheMot(maj, tmp,&pt_maillon))
		{
			printf(" %s", pt_maillon->trad);
		}
		else printf(" [mot_inconnu]");
		strcpy(tmp, strtok_r(NULL, " ", &cour_txt));
	}
	
	if (RechercheMot(maj, tmp,&pt_maillon))
		{
			printf(" %s", pt_maillon->trad);
		}
	else printf(" [mot_inconnu]");
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
	
	printf("1) Ang_Esp\n");
	printf("2) Ang_Fra\n");
	printf("3) Esp_Ang\n");
	printf("4) Esp_Fra\n");
	printf("5) Fra_Ang\n");
	printf("6) Fra_Esp\n");
	
	scanf("%d%*c", pt_choix);
}
