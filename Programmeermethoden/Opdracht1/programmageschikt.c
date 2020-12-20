#include <iostream>
#include <cstdlib>


using namespace std;

int main()
{
	int jaar_gebruiker;
	int maand_gebruiker;
	int dag_gebruiker;
	int dagvdweek_gebruiker;
	int jaar_referentie = 1901;
	int maand_referentie = 1;
	int dag_referentie = 1;
	int verschil_jaren;
	int verschil_maanden;
	int verschil_dagen;
	int dageninjaar = 365;
    int dagen_in_maand[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	srand (42);

	cout << "Voer je geboortejaar in" << endl;

	cin >> jaar_gebruiker;

	if ((jaar_gebruiker < 1912) || (jaar_gebruiker > 2003)){
		cout << "Je bent niet geschikt" << endl;
		return 1;
	}
   else
        cout << "Voer je geboortemaand in" << endl;

   cin >> maand_gebruiker;

   if ((jaar_gebruiker != 2003 ) && (jaar_gebruiker != 1912))
        cout << "Voer je geboortedag in" << endl;

   else if ( ((jaar_gebruiker == 2003) && (maand_gebruiker > 9)) || ((jaar_gebruiker == 1912) && (maand_gebruiker < 9))){
		cout << "Je bent niet geschikt" << endl;
		return 1;
		}
		  else cout << "Voer je geboortedag in" << endl;

          cin >> dag_gebruiker;

          if ( ((jaar_gebruiker == 2003) && (maand_gebruiker == 9) && (dag_gebruiker < 20) ) || ((jaar_gebruiker == 1912) && (maand_gebruiker == 9) && (dag_gebruiker > 20) ))
            cout << "Op welke dag van de week ben je geboren?" << endl;

          else if (( (jaar_gebruiker == 2003) && (maand_gebruiker == 9) && (dag_gebruiker >= 20)) || ( (jaar_gebruiker == 1912) && (maand_gebruiker == 9) && (dag_gebruiker <= 20))){

                cout << "Niet Geschikt" << endl;
                    return 1;
		   }



    if (jaar_gebruiker > jaar_referentie)
        verschil_jaren = (jaar_gebruiker - jaar_referentie) * (dageninjaar);

    if (maand_gebruiker > maand_referentie)
        verschil_maanden = (maand_gebruiker - maand_referentie);





	return 0;
}
