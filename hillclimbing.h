#ifndef HILLCLIMBING_H
#define HILLCLIMBING_H

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


class HillClimbing
{
    Matrix mycities;

    std::ifstream myfile;
    int total_cities;
    Path mypath;

public:
    HillClimbing();
    void readFile();
    void insertCity(int, int);
    void startTrip();
    void printCities();
    void printPath(int);
    int getTotalDistance();

private:

    list<int> remainCities;
    list<int> currentBufferCities;

    int total_distance;

    int visitNextCity(int);



    void makeBufferCities(int);
    void calculateDistances();
    int calculateTotalDistance();


};

#endif // HILLCLIMBING_H
