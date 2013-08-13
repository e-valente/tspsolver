#include "ts.h"

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
