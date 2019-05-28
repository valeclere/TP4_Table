#include "hachage.h"

int main(){
	
	Liste_t Maj[29];
	InitTab(Maj,29); //mettre NULL partout dans le tableau (boucle for)
	
	Insertion("truc", "thing", Maj);
	Insertion("voiture", "car", Maj);
	Insertion("eau", "agua", Maj);
	
	
	return 0;
}
