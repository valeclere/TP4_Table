#include "dictionnaire.h"

/*------------------------------------------------------------------------
 * dictionnaire : module contenant les lectures de fichiers dictionnaires
 -------------------------------------------------------------------------*/



/*------------------------------------------------------------------------------------------------------------
 * ChargerDico : permet de récupérer les traductions d'un fichier texte et de les mettre dans la table
 * Entrée : 
 * 		- Maj = table majeure
 * 		- nom_fichier
 ------------------------------------------------------------------------------------------------------------*/

void ChargerDico(Maj_t Maj[], const char * nom_fichier)
{
	FILE * fichier = NULL; /* pointeur sur le fichier */
	char ligne[TAILLE_LIGNE]; /* chaine de caractère pour saisir une ligne du fichier */
	char mot[TAILLE_MOT]; /* chaine de caracatère pour récupérer le mot */
	char traduction[TAILLE_MOT]; /* chaine de caracatère pour récupérer la traduction */
	
	fichier = fopen(nom_fichier,"r");
	
	if (fichier == NULL) /* Problème d'ouverture qu'on signale avec un message d'erreur */
	{
		printf("erreur d'ouverture du dico\n");
		exit(0); /* on quitte le programme */
	}
	
	else
	{	
		while(fgets(ligne,TAILLE_LIGNE,fichier)) /* on utilise fgets pour détecter la fin du fichier car fgets retourne NULL lorsque il ne peut plus saisir */
		{
			ligne[strlen(ligne)-1]='\0'; /* on transforme la saisie en chaine de caractère */
			strcpy(mot,strtok(ligne,";")); /* on sépare avec le ; pour récuperer le mot et la traduction à l'aide de strtok */
			strcpy(traduction,strtok(NULL,"\0"));
			Insertion(mot,traduction,Maj); /* on insère le mot et la traduction dans la table */
		}
		fclose(fichier);
	}
}


/*------------------------------------------------------------------------------------------------------
 * Traduction : programme permettant différents types de traduction en Ang/Esp/Fra à l'aide d'un menu
 ------------------------------------------------------------------------------------------------------*/

void Traduction()
{
	Maj_t maj[29]; /* déclaration de la table majeure */
	int choixMenu = 0; /* entier pour saisir le choix de l'utilisateur */
	char txt[TAILLE_TEXTE]; /* chaine de caractere pour saisir le texte à traduire */
	char tmp[TAILLE_MOT]; /* chaine de caractere pour stocker successivement les mots de txt (texte à traduire) séparés par le caractère espace ' ' */
	Maillon_t * pt_maillon=NULL; /* pointeur permettant de récupérer la cellule recherchée dans la table */
	char * cour_txt=NULL; /* pointeur de parcours du texte à traduire */
	
	InitTab(maj,29); /* on initialise la table majeure */
	
	printf("\nWelcome/Bienvenue/Bienvenida !\n");
	
	while (choixMenu!= 7)
	{
		choixMenu = 0; /* on réinitialise à chaque fois au cas où SaisirChoix ne marche pas */
		SaisirChoix(&choixMenu); /* on affiche le menu et on récupère le choix de l'utilisateur */
		
		/* selon le choix on charge le bon dictionnaire */
		switch (choixMenu)
		{
			case 1:
				ChargerDico(maj, "Ang_Esp.txt");
				break;
			case 2:
				ChargerDico(maj, "Ang_Fra.txt"); /* fichier contenant le plus de mots, donc plus intéressant pour tester */
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
			case 7:
				printf("\nSee you/À bientôt/Hasta pronto !\n");
				break;
			default:
				printf("Erreur de saisie, saisir un nombre entre 1 et 7\n");
				SaisirChoix(&choixMenu);
				break;
		}
		
		if (choixMenu != 7) /* Si l'utilisateur n'a pas quitté */
		{
			TailleMoy(maj);	/* on affiche la taille moyenne des sous tables (question bonus)*/		
				
			printf("\nSaisir le texte à traduire : ");
			fgets(txt,TAILLE_TEXTE,stdin); /* on récupère le texte à traduire */
			txt[strlen(txt)-1]='\0'; /* on le transforme en chaine de caractère */
			strcpy(tmp, strtok_r(txt, " ", &cour_txt)); /* on sépare les mots grâce aux espaces en utilisant strtok_r */ /* strtok_r permet de récupérer un pointeur sur la suite de la chaine de caractère */
		
			printf("Traduction : ");
			
			while (*cour_txt!='\0') /* tant qu'on est pas à la fin du texte à traduire */
			{
				
				if (RechercheMot(maj, tmp,&pt_maillon)) /* si le mot à traduire existe dans la table */ 
				{
					printf(" %s", pt_maillon->trad); /* on affiche la traduction */
				}
				else printf(" [mot_inconnu]"); /* sinon on affiche "mot inconnu" */
				
				strcpy(tmp, strtok_r(NULL, " ", &cour_txt)); /* puis on récupère le mot suivant à traduire */
			}
			
			
			if (RechercheMot(maj, tmp,&pt_maillon)) /* pour le dernier mot */
				{
					printf(" %s", pt_maillon->trad);
				}
			else printf(" [mot_inconnu]");
			printf("\n");
			
			LibMaj(maj); /* on libère la table majeure et les sous tables */
			InitTab(maj,29); /* on réinitialise la table majeure */
		}
	}
	
}




/*------------------------------------------------------------------------
 * Tradution : récupérer le type de traduction choisi par l'utilisateur
 * Entrée : pointeur sur le choix de l'utilisateur
 ------------------------------------------------------------------------*/

void SaisirChoix(int * pt_choix)
{
	printf("\nSaisir le type de traduction :\n");
	
	/* Affichage du menu */
	
	printf("1) Ang_Esp\n");
	printf("2) Ang_Fra\n");
	printf("3) Esp_Ang\n");
	printf("4) Esp_Fra\n");
	printf("5) Fra_Ang\n");
	printf("6) Fra_Esp\n");
	printf("7) Quitter\n");
	
	scanf("%d%*c", pt_choix); /* récupération du choix */
	//~ fflush(stdout);
}
