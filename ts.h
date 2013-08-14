#ifndef TS_H
#define TS_H

#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <list>


typedef std::list<std::pair<int, int> > City;

class ts
{
    City *mycities;
    std::ifstream myfile;

public:
    ts();
    void readFile();
    void insertCity(int, int);
    void printCities();

private:


    void calculateDistances();
};

#endif // TS_H
