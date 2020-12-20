#include <iostream>
#include <cstdlib>

using namespace std;

char inlezen () {

	char kar = cin.get();
	
	while (kar == '\n')
		kar = cin.get();
	
	while (kar == 'C')
		kar = cin.get();
		
	return kar;
				
}


void menu() {

    char kar = '@';     
    while (kar != 's' && kar != 'S') {
	 	   cout << "s(C)hoon, (R)andom (P)arameters, S(toppen)\n" << endl;
		 
		   kar = inlezen();
				
    		switch (kar) {
    			case 'C':
    			case 'c':
    				cout << "hier moet nog ge-Schoond-d worden\n" << endl;
    				break;
    			case 'R':
    			case 'r':
    				cout << "random-number generator\n" << endl;
    				break;
    			case 'P':
    			case 'p':
    				//submenu();
    				cout << "submenu en T terugnaarhoofdmenu\n" << endl;
    				break;
    			case 'S':
    			case 's':
    				cout << "afsluiten programma\n" << endl;
    				
    				break;
    	
    	
    		}
    	
    }
    	
 }   
    
    
int main ( ) {   

	menu();
    
   return 0;
}
