#include "tests.h"

/*----------------------------------------------------------------------------------------------------
 * test : module contenant les tests de toutes les fonctions du TP
 * 
 * La fonction Traduction() n'est pas testé car elle contient une saisie de l'utilisateur.
 * Cependant elle ne fait que réutiliser les autres fonctions du TP qui ont été testé.
 * De plus Traduction a le format d'un menu et peut donc être testé en lançant l'executable.
 ------------------------------------------------------------------------------------------------------*/


void testInsertion(){
	char *mot="bonjour";
	char *traduction="hello";
	Maj_t maj[29];
	InitTab(maj,29);
	printf("----DEBUT TEST DE LA FONCTION INSERTION----\n");
	printf("----------------------------\n");
	printf("Cas Basic : on donne les bons paramètre à la fonction\n");
	Insertion(mot,traduction,maj);
	printf("le programme continue à s'exécuter sans problème\nles allocations ont bien fonctionnés\n");
	printf("----------------------------\n");
	printf("Cas 1 : on donne à la fonction que des arguments vide ou nul\n");
	Insertion("","",NULL);
	printf("----------------------------\n");
	printf("Cas 2 : on donne à la fonction des mot vide et maj initialisé\n");
	Insertion("","",maj);
	printf("----------------------------\n");
	LibMaj(maj);
	printf("----FIN TEST DE LA FONCTION INSERTION----\n\n");
}

void testRechercheMot(){
	char *mot="computer";
	char *fauxMot="cheval";
	Maj_t maj[29];
	Maillon_t * pt_maillon=NULL;
	InitTab(maj,29);
	ChargerDico(maj,"Ang_Fra.txt");
	printf("----DEBUT TEST DE LA FONCTION RECHERCHE MOT----\n");
	printf("----------------------------\n");
	printf("On remplit la table avec le fichier Ang_Fra.txt\n");
	printf("----------------------------\n");
	printf("Cas Basic : on recherche un mot qui existe dans la table\n");
	if(RechercheMot(maj,mot,&pt_maillon)) printf("le mot: %s a été trouvé dans maj.\n",mot);
	else printf("le mot: %s NON trouvé dans maj.\n",mot);
	printf("----------------------------\n");
	printf("Cas 1 : on recherche un mot qui N'existe PAS dans la table\n");
	if(RechercheMot(maj,fauxMot,&pt_maillon)) printf("le mot: %s a été trouvé dans maj.\n",fauxMot);
	else printf("le mot: %s NON trouvé dans maj.\n",fauxMot);
	printf("----------------------------\n");
	printf("Cas 2: on donne a la fonction des paramètre null ou vide\n");
	RechercheMot(NULL,"",NULL);
	LibMaj(maj);
	printf("----FIN TEST DE LA FONCTION RECHERCHE MOT----\n\n");
}

void testChargerDico(){
	Maj_t maj[29];
	InitTab(maj,29);
	printf("----DEBUT TEST DE LA FONCTION CHARGER DICO----\n");
	printf("----------------------------\n");
	printf("Cas Basic : on charge un dico dans un fichier normale\n");
	ChargerDico(maj,"Ang_Fra.txt");
	affichageMaj(maj);
	printf("----------------------------\n");
	printf("Pour les autre cas on considère que les fichiers sont bien rempli (non vide, sans erreur)\n");
	printf("----------------------------\n");
	LibMaj(maj);
	printf("----FIN TEST DE LA FONCTION CHARGER DICO----\n\n");
}

void testTailleMoy(){
	Maj_t maj[29];
	InitTab(maj,29);
	ChargerDico(maj,"Ang_Fra.txt");
	printf("----DEBUT TEST DE LA FONCTION TAILLE MOY----\n");
	printf("----------------------------\n");
	printf("On remplit la table avec le fichier Ang_Fra.txt\n");
	printf("Cas de base: on veut connaitre la moyenne d'une table majeure qui existe\n");
	TailleMoy(maj);
	printf("----------------------------\n");
	printf("Cas 1: On donne une table vide à la fonction\n");
	TailleMoy(NULL);
	printf("----------------------------\n");
	LibMaj(maj);
	printf("----FIN TEST DE LA FONCTION TAILLE MOY----\n\n");
		
}
