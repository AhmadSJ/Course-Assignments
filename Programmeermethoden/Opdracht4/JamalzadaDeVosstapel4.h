#ifndef __JamalzadaDeVosstapel4_h__
#define __JamalzadaDeVosstapel4_h__
#include "JamalzadaDeVosbordvakje4.h"

class vakje{
	public:
		vakje( );
		bordvakje* positie; 
		vakje* volgende; 
};

class stapel{
	public:
		stapel( );
		~stapel( );
		void zetOpStapel(bordvakje* p);
		void haalVanStapel(bordvakje* & hulp);
		bool isStapelLeeg( );
	private:
		vakje* bovenste;
};

#endif
