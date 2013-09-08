#include <iostream>
#include "bestfirst.h"
#include "hillclimbing.h"

using namespace std;

int main()
{
    BestFirst mybestfirst;
    HillClimbing myhillclimbing;


    /*Algoritmo BestFirst
     */
    cout << "== Best First ==\n\n";
    mybestfirst.readFile();
    mybestfirst.startTrip();

    cout <<"\nTotal percorrido: " << mybestfirst.getTotalDistance() << "\n\n";



    /*Algoritmo HillClimbing
     */
    cout << "== Hill Climbing ==\n\n";
    myhillclimbing.readFile();
    myhillclimbing.startTrip();
    myhillclimbing.printPath(0);

    cout <<"\nTotal percorrido: " << myhillclimbing.getTotalDistance() << "\n";



    return 0;
}

