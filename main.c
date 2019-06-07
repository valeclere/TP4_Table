#include "dictionnaire.h"
#include "tests.h"
int main(void){
	
	/*----TEST creation----*/
	
	//~ Maj_t maj[29]; /*déclaration de la table Majeure */
	//~ InitTab(maj,29); /*initialisation : mettre NULL dans toutes les cases de MAJ*/
	
	//~ ChargerDico(maj, "Ang_Fra.txt");
	
	//~ char mot[10];
	//~ Maillon_t * pt_maillon=NULL;
	//~ strcpy(mot,"hello");
	
	//~ ChargerDico(maj,"anglais.txt");
	//~ if(RechercheMot(maj, mot,&pt_maillon)){
		//~ printf("OUE ON A TROUVE\n");
		//~ printf("pt_mot=%s .\n",pt_maillon->trad);
	//~ }
	//~ printf("FIN PROGRAMME\n");
	
	//Traduction();*/
	
	
	
	
	testInsertion();
	testRechercheMot();
	testChargerDico();
	/*-----FIN TEST----*/
	
	return 0;
}
