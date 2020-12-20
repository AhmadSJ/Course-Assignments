#include <iostream>
#include <cstdlib>

using namespace std;

int leesgetal(int bovengrens) {
	char numb = cin.get();
	
	int getal = 0;
	
	while (numb == '\n')
		numb = cin.get();
		
	while (numb != '\n'){
		if (numb <= '9' && numb >= '0'){
			getal = 10 * getal + (numb - '0');	
			if (getal > bovengrens)
				getal = getal / 10;	
		}
		numb = cin.get();
		}
	return getal;
}

char inlezen() {

	char kar = cin.get();
	
	while (kar == '\n')
		kar = cin.get();
		
	return kar;	
}

class nonogram {
	private:
		bool A[50][50];
		bool zwart;
		bool wit;
		int hoogte;
		int breedte;
		int percentage;
		int iCursor;
		int jCursor;
		int i;
		int j;
	
	public:
		nonogram();
		int randomgetal();
		int setpercentage();
		int setheight();
		int setbreedte();
		void randomvullen();
		void drukaf();
		void schoon();
		void Cursor(char invoer);
		void toggel();
		void zwartwitneutraal(char invoering);
};

nonogram::nonogram(){
	hoogte = 10;
	breedte = 10;
	percentage = 70;
	iCursor = 0;
	jCursor = 0;
	zwart = false;
	wit = false;
}

int nonogram::randomgetal() {
	static int randgetal = 42;
	randgetal = ( 221 * randgetal + 1 ) % 1000;
	
	return randgetal;
}

int nonogram::setpercentage(){
	percentage = leesgetal(100);
	cout << percentage << endl;
	
	return percentage;
}

int nonogram::setheight(){
	hoogte = leesgetal(50);
	cout << hoogte << endl;
	return hoogte;
}

int nonogram::setbreedte(){
	breedte = leesgetal(50);
	cout << breedte << endl;
	return breedte;
}

void nonogram::randomvullen(){
	
	for (i = 0; i < hoogte; i++){
		for (j = 0; j < breedte; j++){
			if (randomgetal() % 101 < percentage)
				A[i][j] = true;
			else 
				A[i][j] = false;
		}
	}					
}


	

void nonogram::drukaf(){
	for (i = 0; i < hoogte; i++){
		for ( j = 0; j < breedte; j++ ){
			if ( i == iCursor && j == jCursor)
				cout << '*' << " ";
			else if ( A[i][j] )
				cout << "X" << " ";
			else 
				cout << "_" << " ";
			
		}
		cout << endl;
	}
}

void nonogram::schoon(){
	
	for (i = 0; i < hoogte; i++){
		for (j = 0; j < breedte; j++){
			A[i][j] = false;
		}
	}					
}

void nonogram::Cursor(char invoer){
	switch (invoer){
		case 'a':
			if (jCursor != 0)
				jCursor = jCursor - 1;
				
			break;
		case 's':
			if (iCursor != hoogte -1)
				iCursor = iCursor + 1;
			break;
		case 'd':
			if (jCursor != breedte - 1)
				jCursor = jCursor + 1;	
			break;
		case 'w': 
			if (iCursor != 0)
				iCursor = iCursor - 1;	
			break;
		}
		

	if (zwart == true)
		A[iCursor][jCursor] = true;
		
	else if (wit == true)
		A[iCursor][jCursor] = false;
	
	
	
}

void nonogram::zwartwitneutraal(char invoering){

	switch (invoering){
		case 'Z': case 'z':
			zwart = true;
			wit = false;
			break;
		case 'W': case 'w':
			wit = true;
			zwart = false;
			break;
		case 'N': case 'n':
			zwart = false;
			wit = false;
			break;
	}
}	

void nonogram::toggel(){
	if (A[iCursor][jCursor])
		A[iCursor][jCursor] = false;
	else 
		A[iCursor][jCursor] = true;
}

			
void submenu(nonogram & nono) {
	char kar = '@';
	while (kar != 't' && kar != 'T') {
		nono.drukaf();
		cout << "(B)reedte, (H)oogte, (P)ercentage random invullen"
		     << ", (T) om terug te gaan, Verplaatsen cursor: nieuwe punt (Z)wart"
		     << "(W)it of O(n)verandert" << endl;
		
		kar = inlezen();
		
		switch (kar) {
			case 'H':
			case 'h':
				cout << "Voer uw gewenste hoogte in\n" << endl;
				nono.setheight();
				cout << endl;
				break;
			case 'B':
			case 'b':
				cout << "Voer uw gewenste breedte in\n" << endl;
				nono.setbreedte();
				break;
			case 'P':
			case 'p':
				cout << "Voer een percentage in [max 100]\n" << endl;
				nono.setpercentage();
				break;
			case 'Z': case 'z': case 'W': case 'w': case 'n': case 'N':
				nono.zwartwitneutraal(kar);
				break;
				
		}
	}
}

/*void nonogram::zwartCursor(char invoer)
		switch (invoer){
		case 'a':
			if (jCursor != 0)
				jCursor = jCursor - 1;
				A[iCursor][jCursor] = true;
			break;
		case 's':
			if (iCursor != hoogte -1)
				iCursor = iCursor + 1;
				A[iCursor][jCursor] = true;
			break;
		case 'd':
			if (jCursor != breedte - 1)
				jCursor = jCursor + 1;
				A[iCursor][jCursor] = true;
			break;
		case 'w': 
			if (iCursor != 0)
				iCursor = iCursor - 1;
				A[iCursor][jCursor] = true;
			break;
		}
}*/

void menu() {
	nonogram nono;
	nono.schoon();
   char kar = '@';     
   while (kar != 'o' && kar != 'O') { 
   	nono.drukaf();
		cout << "s(C)hoon, (R)andom (P)arameters, St(o)ppen\n"
			  << "Cursor naar: links = a, rechts = d, beneden = s, boven = w"
			  << endl;	
	
		kar = inlezen();
		
    	switch (kar) {
    		case 'C':
    		case 'c':
    			cout << "De array is geschoond\n" << endl;
    			nono.schoon();
    			break;
    		case 'R':
    		case 'r':
    			nono.randomvullen();
    			break;
    		case 'P':
    		case 'p':
    			submenu(nono);
    			break;
    		case 'O':
    		case 'o':
    			cout << "Afsluiten programma\n" << endl;
    			break;
    		case 'w': case 'a': case 's': case 'd':
    			nono.Cursor(kar);
    			break;
    		case 't':
    			nono.toggel();
    			break;
    	}
    }
}


int main ( ) { 
	
	menu();
	
	
   return 0;
}






    

