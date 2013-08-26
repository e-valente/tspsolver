#ifndef TS_H
#define TS_H

#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <list>
#include <vector>

using namespace std;

//typedef list<pair<int, int> > City;
typedef vector< vector<int> > Matrix;

class ts
{
   // City *mycities;

    Matrix mycities;

    std::ifstream myfile;
    int total_cities;

public:
    ts();
    ~ts();
    void readFile();
    void insertCity(int, int);
    void printCities();

private:


    void calculateDistances();
};

#endif // TS_H
