//Dit is een programma geschreven door Ahmad Jamalzada en Erik de Vos.
//Onze code is opgesplitst in 6 bestanden, waaronder drie headerfiles (zie
//lateX verslag voor onze uitleg voor deze keuze). De namen van deze bestanden
//zijn: JamalzadaDeVoshoofd4.cc, JamalzadaDeVosgobord4.cc,
//JamalzadaDeVosgobord4.h, JamalzadaDeVosstapel4.cc, JamalzadaDeVosstapel4.h,
//JamalzadaDeVosbordvakje4.h.
//Onze code genereert een interactief Gomoku-spel in de terminal, waarin
//allerlei wijzigingen kunnen worden aangebracht. De compiler die wij hebben
//gebruikt is g++(GCC 4.8.1). Als editor hebben wij gedit gebruikt.
//Ons project hebben wij op 6 December 2013 afgerond.
//Onze studentennummers zijn: Erik: 1430750  Ahmad: 1145657

#include <iostream>
#include "JamalzadaDeVosgobord4.h"

using namespace std;

void infoblokje( ){
	cout << endl << "Dit programma is geschreven door Ahmad Jamalzada en Erik "
		 << "de Vos\nWij zijn eerstejaars Natuurkunde studenten.\n"
		 << "Dit programma is gemaakt voor de vierde opdracht van het vak\n"
		 << "Programmeermethoden. Het is afgerond op 6 December 2013.\n"
		 << "U kunt met dit programma het spel Gomoku spelen tegen een"
		 << " computer.\nOok kunt u de computer tegen zichzelf laten spelen."
		 << endl << endl;
}

int main( ){
	infoblokje( );
	gobord Gobord;
	Gobord.menu( );

	return 0;
}


