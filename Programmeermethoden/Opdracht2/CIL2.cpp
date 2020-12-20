// Leonard Dijkshoorn		& 		Erik de Vos					11-10-2013
// s1455990							s1430750
// compiler: g++
// Programmeeropdracht 2: CIL

#include <fstream>	//Dit is nodig voor de in-uitvoer van de bestanden
#include <iostream>	//Dit is nodig voor de in-uitvoer van cin/cout
#include <string>	//Dit is nodig voor het herkennen van strings
#include <cstdlib>	//Dit is nodig voor het gebruik van exit(1)
#include <climits>	//Dit is om de INT_MAX zijn waarde te geven.
using namespace std;

void lychrel (int invoer){
	int number = 0;
	int inverse = 0;
	int z = 0;
	int teller = 0;

	number = invoer;

	while (number != inverse && INT_MAX - number > inverse){

		number = number + inverse;
		teller++;	//tellertje voor aantal iteraties

		inverse = 0;
		z = number;

      //omdraaien getal
		while (z != 0){
			inverse = inverse * 10 + z % 10;
			z = z / 10;
		}//while
	}//while

	if (number == inverse){
		cout << "Het getal " << invoer << " is geen lychrelgetal." << endl;
		cout << "Het aantal iteraties benodigd is: " << teller - 1 << endl << endl;
	}

	if (INT_MAX - number < inverse){
      cout << invoer << " is mogelijk een lychrel getal"
           << ", aantal iteraties: " << teller - 1 << endl << endl;
	}

}//void

void commentaar(){

	string fileNaam;
	string newfile;
	ifstream invoer;
	ofstream uitvoer;
	char kar = invoer.get();
	char prevkar = 'k';
	bool commentaar = false;
	bool semiCom = false;
	bool nieuweregel = false;
	int getal = 0;
	int d = 0;  //diepte na accolade
	int nStat = 0; //aantal statistieken
	int nRegels = 0; //aantal regels
	int nKar = 0;  //aantal ingelezen karakters
	int nPut = 0;  //aantal uitgevoerde karakters
	int nTab = 0;  //gewenste tabgrootte
	int teller = 0;

	cout << "Voer de naam van de file in dat u wilt laten bewerken" << endl;
	cin  >> fileNaam;

	invoer.open (fileNaam.c_str ());
	if (invoer.fail()){
		cout << "Het openen van de file is mislukt."<< endl;
		exit(1);
	}

	cout << "Geef een naam voor de nieuwe file." << endl;
	cin  >> newfile;
	uitvoer.open (newfile.c_str());

	if (uitvoer.fail()){
		cout << "Openen van nieuwe file mislukt."<< endl;
		exit (1);
	}

	cout << "Om de hoeveel regels wilt u statistieken zien?" << endl;
	cin >> nStat;
	cout << "Voer uw gewenste tabgrootte in." << endl;
	cin >> nTab;

	while (! invoer.eof ( )) {
		nKar++; //aantal gelezen karakters.

	   //Verwerkt commentaar
		if (kar == '/' && prevkar != '/')
			semiCom = true;

		if (prevkar == '/' &&  kar != '/')	{
			if (commentaar == false){
				uitvoer.put (prevkar);
			}
			semiCom = false;
		}

		if (prevkar == '/' && kar == '/')
			commentaar = true;

		if ( kar == '\n' ) {
			commentaar = false;
			semiCom = false;
		}
      //Verwerkt tabs en spaties op nieuwe regel.
		if (prevkar == '\n') {
			nieuweregel = true;
		}

		if (kar != ' ' && kar != '\t')
			nieuweregel = false;

      //verwijdert commentaar en spaties/tabs op nieuwe regel.
		if ( commentaar == false && nieuweregel == false)
		{
			if (semiCom == false ) {
				uitvoer.put (kar);
				nPut++;
			}
		}
      //gelezen getallen worden gemaakt.
		if (kar >= '0' && kar <= '9' && commentaar == false) {
			getal = getal * 10 + kar - '0';
		}
      //stuurt het getal naar lychrelcontrole
		else if (getal > 0 && commentaar == false) {
			lychrel(getal);
			getal = 0;
		}

		if (kar == '{')
			d++ ;
		if (kar == '}')
			d-- ;

		if (kar == '\n') {
			nRegels++;
			teller = 0;
			while (teller < (nTab * d))
			{
				teller++;
				uitvoer.put(' ');
			}
		}

		prevkar = kar;
		kar = invoer.get();

		if (nRegels % nStat == 0 && prevkar == '\n') {
			cout << "Het aantal ingelezen karakters is " << nKar << endl;
			cout << "Het aantal afgedrukte karakters is " << nPut << endl
				  << endl;
		}
	}//while

	cout << "Het aantal ingelezen karakters is " << nKar << endl;
	cout << "Het aantal afgedrukte karakters is " << nPut << endl << endl;

	invoer.close();
	uitvoer.close();
}//void

int main(){

	commentaar ();

	return 0;
}














