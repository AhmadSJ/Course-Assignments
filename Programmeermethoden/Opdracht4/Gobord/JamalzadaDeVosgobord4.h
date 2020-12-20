#ifndef __JamalzadaDeVosgobord4_h__
#define __JamalzadaDeVosgobord4_h__
#include "JamalzadaDeVosstapel4.h"

int leesgetal( );

class gobord{
	private:
		stapel Stapel; 
		bordvakje* ingang; 
		int hoogte, breedte; 
		char kl1; 
		char kl2; 
		int telSpeler; 
		int telPC;
		int rijNummer;
		int kolomNummer;
		int nZet;
		bool gedaan;
		void rits(bordvakje* boven, bordvakje* onder);
		bordvakje* maakRij(int aantal);

	public:
		gobord( );
		gobord(int hoogte, int breedte);
		~gobord( );
		bordvakje* gaNaar(int i, int j);
		int richting(char & kleur, int richting);
		long double mogelijkePartijen(int getal);
		void pcSpelDuizend( );		
		void mensSpel( );
		void terughalen( );
		void pcSpel( ); 
		void schoon( );
		void menu( );
		void kiesKleur( );
		void setDimensies( );
		void bouwBord( );
		void randomZet(char kleur);
		void mensZet( );
		void drukAf( );
		bool klaar( );
		bool gewonnen(char & kleur);
		void doeZet(int i, int j, char kl);
};
#endif


