#include "hachage.h"
#include "dictionnaire.h"

int main(){
	
	/*----TEST creation----*/
	
	Liste_t Maj[29]; /*déclaration de la table Majeure */
	InitTab(Maj,29); /*initialisation : mettre NULL dans toutes les cases de MAJ*/
	
	ChargerDico(Maj,"anglais.txt");
	
	/*Insertion("test","test",Maj);*/
	
	/*-----FIN TEST----*/
	
	return 0;
}
