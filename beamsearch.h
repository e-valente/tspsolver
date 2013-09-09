#ifndef BEAMSEARCH_H
#define BEAMSEARCH_H

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


class BeamSearch
{
    Matrix mycities;

    std::ifstream myfile;
    int total_cities;
    Path mypath;

public:
    BeamSearch();
    void readFile();
    void insertCity(int, int);
    void startTrip();
    void printCities();
    void printPath(int);
    int getTotalDistance();

private:

    list<int> remainCities;
    list<int> availablePaths;
    list<int> availablePaths2;

    int total_distance;

    void makeFirstAvailablePaths(int);
    void makeSecondAvailablePaths(int);
    void calculateBestNextCity(int, int&, int&);



};

#endif // BEAMSEARCH_H
