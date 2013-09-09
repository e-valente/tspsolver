#ifndef BESTFIRST_H
#define BESTFIRST_H

/*Algoritmo BestFirst
 */
/*Detalhes de implementacao sao baseados
 *do seguinte artigo:
 * https://s3.amazonaws.com/accredible_work/57/AIreport.pdf?1361153888
 */

#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <list>
#include <vector>
#include <queue>

using namespace std;

typedef list<pair<int, int> > Path;
typedef vector< vector<int> > Matrix;

class BestFirst
{
   // City *mycities;

    Matrix mycities;

    std::ifstream myfile;
    int total_cities;
    Path mypath;

public:
    BestFirst();
    void readFile();
    void insertCity(int, int);
    void startTrip();
    void printCities();
    void printPath(int);
    int getTotalDistance();

private:

    list<int> remainCities;
    int total_distance;

    int visitNextCity(int);



    void calculateDistances();
    int calculateTotalDistance();
};



#endif // BESTFIRST_H
