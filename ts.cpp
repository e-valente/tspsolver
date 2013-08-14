#include "ts.h"

#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <list>
#include <cstdlib>

ts::ts()
{
    mycities = new City;

}

void ts::insertCity(int x, int y)
{
    mycities->push_back(std::make_pair(x, y));
}

void ts::printCities()
{
    City::iterator i;

    for(i = mycities->begin(); i != mycities->end(); i++)
        std::cout << "x coordenate: " << (*i).first << "\ny coordenate: " << (*i).second << std::endl;
}

void ts::readFile()
{
    char output[100];
    int x, y;
    myfile.open("cities.txt");

    if(myfile.is_open())
    {
        while(!myfile.eof())
        {
            myfile >> output;
            x = atoi(output);

            myfile >> output;
            y = atoi(output);

            std::cout << "inserindo " << x << " " << y << "\n";
            insertCity(x, y);



           // std::cout <<" " <<  output;
        }

    }

    myfile.close();


}
