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

    cout <<"\nTotal percorrido: " << mybestfirst.getTotalDistance() << "\n";



    /*Algoritmo HillClimbing
     */
    cout << "== Hill Climbing ==\n\n";
    myhillclimbing.readFile();
    myhillclimbing.startTrip();

    //cout <<"\nTotal percorrido: " << mybestfirst.getTotalDistance() << "\n";



    return 0;
}

