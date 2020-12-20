#include <iostream>
#include <cstdlib>
#include <cmath>


using namespace std;

int main()
{

    srand (42);
    int x;
    int y;
    int z;

    x = rand () % 999 + 100;
    y = rand () % 999 + 100;

    float r = x + (float)rand()/(float)RAND_MAX;
    float s = y + (float)rand()/(float)RAND_MAX;

    float cijfer1 = floorf(r * 100) / 100;
    float cijfer2 = floorf(s * 100) / 100;

    cout << cijfer1 << "    " << cijfer2 << endl;

    while ((x + y) > 1000){

    }

    return 0;
}
