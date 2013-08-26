#include "ts.h"

#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <list>
#include <cstdlib>

using namespace std;


ts::ts()
{
    //mycities = new City;

}

ts::~ts()
{
    //delete [] mycities;
}


void ts::insertCity(int x, int y)
{
    //mycities->push_back(std::make_pair(x, y));
}


void ts::printCities()
{

    cout << "\n\n";

    for(int i = 0; i < total_cities; i++)
    {
        for(int j = 0; j < total_cities; j++)
        {
            cout << mycities[i][j] << " ";
        }

        cout << endl;
    }

}

void ts::readFile()
{
    char output[100];

    myfile.open("in.txt");

    myfile >> output;
    total_cities = atoi(output);


    //resize -> rows
    mycities.resize(total_cities);

    //resize ->cols
    for(int i = 0; i < total_cities; i++)
    {
        mycities[i].resize(total_cities);
    }


    for(int i = 0; i < total_cities; i++)
    {
        for(int j = 0; j < total_cities; j++)
        {
            myfile >> output;
            mycities[i][j] = atoi(output);

        }
    }



    cout << "total de cidade vale: " << total_cities;

    myfile.close();


}
