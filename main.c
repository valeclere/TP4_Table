#include "dictionnaire.h"
#include "tests.h"

/*-------------------------------------------------------------------------
 * Pour rendre notre TP plus claire nous utilisons un menu dans le main().
 * On peut ainsi accéder aux fonctionnalités suivantes :
 * 		- le test de toutes les fonctions;
 * 		- le traducteur.
 * 
 * ATTENTION seule la fonction Traduction n'est pas testée
 * Car nous avons créé un menu qui permet de l'utiliser et de la tester
 -------------------------------------------------------------------------*/

int main(void)
{
	int choix = 0;
	
	printf("Bienvenue dans le TP4 de SDD\n");
	
	while (choix!=3)
	{
		printf("\n");
		printf("1) Réaliser les tests des fonctions\n");
		printf("2) Utiliser le traducteur\n");
		printf("3) Quitter\n");
		printf("\nVeuillez saisir votre choix : ");
		
		scanf("%d%*c",&choix);
	
		switch (choix)
		{
			case 1: /* tests de toutes les fonctions */
				testInsertion();
				printf("\n");
				testRechercheMot();
				printf("\n");
				testChargerDico();
				printf("\n");
				testTailleMoy();
				printf("\n");
				break;
				
			case 2:
				Traduction(); /* traducteur */
				break;
			
			case 3:
				printf("\nÀ bientôt !\n");
				break;
	
			default:
				printf("Le choix saisi est incorrect, merci de resaisir\n");
				break;
		}
	}
			
	return 0;
}
