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



/*void openenBestand (ifstream & invoer,ofstream & uitvoer)
{

}//void*/

void commentaar ()
{
	//In de functie lychrelGetallen wordt gecontroleert of een ingelezen getal
	//een lychrelgetal is, dit en het (max) aantal iteraties wordt gecout.
	//Hier worden prevkar en kar gedeclareerd, prevkar is het vorige karakter
	//en kar is het huidige karakter wat wordt gelezen. Ook worden hier
	//booleans gedeclareerd en geinitialiseerd, incommentaar wil zeggen dat er
	//nu karakters worden gelezen, die in het commentaar staan.
	//PotentieelCommentaar betekent dat er karakters worden gelezen die
	//wellicht behoren tot het commentaar.
	//inWit betekent dat er karakters worden gelezen die ofwel spaties en tabs
	//zijn aan het begin van een regel terwijl er nog geen andere karakters
	//voorgekomen zijn. Deze whitespaces 	worden niet afgedrukt.
	//Ook worden getal, d, z, inTel en uitTel geinitialiseerd
	//(waarover later meer (cliffhanger))


	string fileNaam;
	string newfile;
	ifstream invoer;
	ofstream uitvoer;
	//Hier wordt aan de gebruiker gevraagd welke file verbonden moet worden met
	//de invoer. Hierna wordt dit bestand ook daadwerkelijk daarmee gekoppeld.
	cout << "Voer de naam in van de file die u wilt openen."<< endl;
	cin  >> fileNaam;
	//Als het bestand niet kan worden geopend wordt dit vermeld en stopt
	//het programma.
	invoer.open (fileNaam.c_str ( ));
	if (invoer.fail( )) {
		cout << "Openen van het ingevoerde bestand is mislukt."<< endl;
		exit(1);
	}//if

	//Hier wordt aan de gebruiker gevraagd welke naam het nieuwe bestand krijgt,
	//dit nieuwe bestand wordt aangemaakt en de uitvoer komt hierin te staan.
	cout << "Voer de gewenste naam in van de file die voor u wordt"
		 << " gemaakt." << endl;
	cin  >> newfile;
	uitvoer.open (newfile.c_str ( ));
	//Als het de uivoer niet in het nieuwe bestand kan komen,
	//dan wordt dit vermeld.
	if (uitvoer.fail( )) {
		cout << "Openen van het uitgaande bestand is mislukt."<< endl;
		exit (1);
	}//if














	void lychrelGetallen (int nummer);
	char prevkar, kar = invoer.get ( );
	bool incommentaar = false, potentieelCommentaar = false, inWit = false;
	int getal = 0, d = 0, infoScherm = 0, aantalRegels = 0;
	int inTel = 0, uitTel = 0, inTab = 0, z = 0;

	cout << "Om de hoeveel regels wilt u de statistieken zien?" << endl;
	cout << "Voer dit in in gehele getallen." << endl;
	cin >> infoScherm;
	cout << "Welke tabgrootte wilt u voor het aan te maken bestand?" << endl;
	cout << "Voer dit in in gehele getallen." << endl;
	cin >> inTab;

	//Zolang het eindteken van het de invoer niet is bereikt,
	//zal het programma doorgaan.
	while (! invoer.eof ( )) {

		//inTel wordt elke keer dat de while-loop wordt doorlopen verhoogt,
		//en telt hiermee dus het aantal ingelezen karakters.
		inTel++;

		//Hier wordt aangegeven wanneer de ingelezen karakters tot
		//het commentaar behoren. Zolang dit het geval is worden deze karakters
		//niet afgedrukt.
		if (kar == '/' && prevkar != '/')
			potentieelCommentaar = true;
		if (prevkar == '/' &&  kar != '/')	{
			if (!incommentaar){
				uitvoer.put (prevkar);
			}//if
			potentieelCommentaar = false;
		}//if

		if (prevkar == '/' && kar == '/')
			incommentaar = true;

		if ( kar == '\n' ) {
			incommentaar = false;
			potentieelCommentaar = false;
		}//if

		//Hier worden de spaties en tabs aan het begin van elke zin herkent,
		//zolang er nog geen ander karakter dan een van deze twee is
		//tegengekomen blijft de functie inWit true. Zolang dit het geval is
		//worden deze karakters niet afgedrukt.
		if (prevkar == '\n') {
			inWit = true;
		}//if

		if (kar != ' ' && kar != '\t')
			inWit = false;

		//Hier wordt bepaald dat wanneer de boolean inCommentaar en inWit beide
		//niet true zijn, de ingelezen karakters worden ingevoerd. Hierdoor
		//wordt het commentaar niet afgedrukt, net als de spaties/tabs aan het
		//begin van een regel.
		if ( !incommentaar && !inWit)
		{
			if (!potentieelCommentaar ) {
				uitvoer.put (kar);
				uitTel++;
			}//if
		}//if

		//Hier worden opeenvolgende getallen ingelezen, wanneer de
		//'getallenreeks' stopt. Wordt het getal naar de functie
		//lychrelgetallen gestuurd.
		if (kar >= '0' && kar <= '9' && !incommentaar) {
			getal = getal * 10 + kar - '0';
		}//if

		else if (getal > 0 && !incommentaar) {
			lychrelGetallen (getal);
			getal = 0;
			//Hier wordt de waarde van getal weer op nul gesteld voor
			//het volgende getal wat de functie gaat doorlopen.
		}//else if

		//Hier wordt aangegeven dat wanneer er een openingsaccolade wordt
		//herkend, de diepte met één wordt verhoogd. En wanneer een
		//sluitaccolade wordt herkend, wordt deze diepte juist met één verlaagd.
		if (kar == '{')
			d++ ;
		if (kar == '}')
			d-- ;

		//Hier wordt het aantal in te voeren spaties aan het begin van een regel
		//bepaald aan de hand van de huidige diepte (d) en de ingevoerde
		//tabgrootte (inTab).
		if (kar == '\n') {
			aantalRegels++;
			z = 0;
			while (z < (inTab * d))
			{
				z++;
				uitvoer.put(' ');
			}
		}

		//Hier wordt de prevkar de kar, en de kar weer de invoer.get()
		//waardoor het volgende karakter gelezen wordt.
		prevkar = kar;
		kar = invoer.get( );

		//Hier wordt om de ingevoerde hoeveelheid regels na een regelovergang
		//het aantal ingelezen en afgedrukte karakters afgedrukt, bijgehouden
		//met de tellers inTel en uitTel.
		if (aantalRegels % infoScherm == 0 && prevkar == '\n') {
			cout << "Het aantal ingelezen karakters is " << inTel << endl;
			cout << "Het aantal afgedrukte karakters is " << uitTel << endl
				 << endl;
		}
	}//while
		//Hier worden de statistieken aan het eind nog eens weergeven.
	cout << "Het aantal ingelezen karakters is " << inTel << endl;
	cout << "Het aantal afgedrukte karakters is " << uitTel << endl << endl;

	invoer.close ( );	//Dit sluit de invoer.
	uitvoer.close ( );	//Dit sluit de uitvoer.
}//void



void lychrelGetallen (int x)
{
	//Hier worden nummer, omgekeerde, b en tel gedeclareerd en geintialiseerd op
	//nul. x is het getal wat eerder in de functie commentaar is gevormd.
	int nummer = 0, omgekeerde = 0, b = 0, tel = 0;

	//Hier wordt omgekeerde 0 gesteld voor de volgende keer.
	omgekeerde = 0;
	nummer = x;

	//Zolang het nummer niet gelijk is aan het omgekeerde blijft
	//de functie lopen als de INT_MAX nog niet is bereikt.
	while (nummer != omgekeerde && INT_MAX - nummer > omgekeerde) {

		//Zolang het geen palindroom is, wordt het nummer opgeteld met het
		//omgekeerde van het nummer en dit samen wordt dan het nieuwe nummer.
		nummer = nummer + omgekeerde;
		tel++;	//Hier wordt het aantal iteraties na elke keer met 1 opgeteld.

		omgekeerde = 0;	//Dit zorgt dat het omgekeerde weer de waarde 0 krijgt.
		b = nummer;		//Hier wordt b gelijk gesteld aan het originele nummer.

		//Als b en dus het nummer geen nul is wordt het getal omgedraaid
		while (b != 0)	{
			omgekeerde = omgekeerde * 10 + b%10;
			b = b/10;
		}//while
	}//while

	//Dit geeft een boodschap als het getal een palindroom is.
	//Ook geeft het hierbij het aantal iteraties en het begingetal.
	if (nummer == omgekeerde) {
		cout << "Het getal " << x << " is geen lychrelgetal." << endl;
		cout << "Het aantal iteraties benodigd is: " << tel - 1 << endl << endl;
	}//if

	//Dit geeft een boodschap als het palindroom nog niet is gevonden binnen
	//INT_MAX en geeft het maximaal uitgevoerde iteraties aan en het begingetal.
	if (INT_MAX - nummer < omgekeerde) {
		cout << "Het getal " << x << " is waarschijnlijk een " <<
				"lychrelgetal." << endl;
		cout << "Het maximaal aantal uitgevoerde iteraties is: " <<tel-1<< endl
			 << endl;
	}//if
}//void

int main ( )
{
	//De functie openenBestand, koppelt het te bewerken bestand aan de invoer.
	//Ook koppelt deze functie de uitvoer aan een uitvoerbestand.
	//De functie commentaar verwijdert het commentaar uit het invoerbestand.
	//Ook zorgt deze functie ervoor dat er goed wordt ingesprongen in het
	//uitvoerbestand. En in deze functie worden gehele getallen ingelezen, welke
	//naar de functie lychrelGetallen worden doorgestuurt.
	//void openenBestand (ifstream & invoer,ofstream & uitvoer);
	//void commentaar ();


	//openenBestand (invoer, uitvoer);
	commentaar ();

	return 0;
}// main














