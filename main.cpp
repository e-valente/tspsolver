#include <iostream>
#include "bestfirst.h"
#include "hillclimbing.h"
#include "beamsearch.h"

using namespace std;

int main()
{
    BestFirst mybestfirst;
    HillClimbing myhillclimbing;
    BeamSearch mybeamsearch;


    /*Algoritmo BestFirst
     */
    /*Detalhes de implementacao sao baseados
     *do seguinte artigo:
     * https://s3.amazonaws.com/accredible_work/57/AIreport.pdf?1361153888
     */
    cout << "== Best First ==\n\n";
    mybestfirst.readFile();
    mybestfirst.startTrip();

    cout <<"\nTotal percorrido: " << mybestfirst.getTotalDistance() << "\n\n";



    /*Algoritmo HillClimbing
     *Detalhes sobre a implementacao em hillclimbing.cpp
     */
    cout << "== Hill Climbing ==\n\n";
    myhillclimbing.readFile();
    myhillclimbing.startTrip();
    myhillclimbing.printPath(0);

    cout <<"\nTotal percorrido: " << myhillclimbing.getTotalDistance() << "\n\n";


    /*Algoritmo BeamSearch
     *Detalhes sobre a implementacao em beamsearch.cpp
     */
    cout << "== Beam Search ==\n\n";
    mybeamsearch.readFile();
    mybeamsearch.startTrip();
    mybeamsearch.printPath(0);


    cout <<"\nTotal percorrido: " << mybeamsearch.getTotalDistance() << "\n";





    return 0;
}

