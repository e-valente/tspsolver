#include "bestfirst.h"


#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <list>
#include <algorithm> //find
#include <cstdlib>
#include <limits>

using namespace std;


BestFirst::BestFirst()
{
    //mycities = new City;

}


void BestFirst::printCities()
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

void BestFirst::readFile()
{
    char output[100];

    myfile.open("in.txt");

    myfile >> output;
    total_cities = atoi(output);


    //resize -> rows
    mycities.resize(total_cities);

    //resize ->cols and update or remain cities
    for(int i = 0; i < total_cities; i++)
    {
        mycities[i].resize(total_cities);

       // remainCities.push_back(i);
    }


    for(int i = 0; i < total_cities; i++)
    {
        for(int j = 0; j < total_cities; j++)
        {
            myfile >> output;
            mycities[i][j] = atoi(output);

        }
    }

    myfile.close();

}

void BestFirst::startTrip()
{
    int initialCity, bestInitialCity;
    int minorPath = 9999999;
    int currentDistance;


    //coloca cidades para serem visitadas
    for(int i = 0; i < total_cities; i++)
    {

        remainCities.push_back(i);
    }


    for(int i = 0; i < total_cities; i++)
    {
        initialCity = i;

        while(!remainCities.empty()){
            initialCity = visitNextCity(initialCity);
        }

        currentDistance = calculateTotalDistance();

        if(minorPath > currentDistance)
        {
            minorPath = currentDistance;
            total_distance = currentDistance;
            bestInitialCity = initialCity;
        }

        //coloca cidades para serem visitadas
        for(int j = 0; j < total_cities; j++)
        {

            remainCities.push_back(j);
        }

        mypath.clear();


    }

   // cout <<"melhor sair da cidade " << bestInitialCity << "ditancia total: " << minorPath << endl;

    //coloca cidades para serem visitadas
    for(int j = 0; j < total_cities; j++)
    {

        remainCities.push_back(j);
    }

    initialCity = bestInitialCity;

    while(!remainCities.empty()){
        initialCity = visitNextCity(initialCity);
    }


    printPath(bestInitialCity);



}

int BestFirst::visitNextCity(int city)
{
    int minorDistance = 99999;
    int nextCity = 99999;

    list<int>::iterator it;

    for(int i = 0; i < total_cities; i++)
    {

        it = find(remainCities.begin(), remainCities.end(), i);

        //cout << "comparando " << mycities[i][city] << " com " << minorDistance << endl;
        //cout << "valor de it " << *it << " valor de city e de i " << city << " " << i << endl;
        if(mycities[i][city] < minorDistance && mycities[i][city] > 0 && (*it == i))
        {

            minorDistance = mycities[i][city];
            nextCity = i;
        }

    }

    mypath.push_back(make_pair(nextCity, minorDistance));

    remainCities.remove(nextCity);



    return nextCity;

}

int BestFirst::calculateTotalDistance()
{
    Path::iterator it;
    int totalDistance = 0;

    for(it = mypath.begin(); it != mypath.end(); it++)
    {
      //  cout << "Cidade: " << (*it).first << " Distancia: " << (*it).second << endl;
        totalDistance += (*it).second;
    }

    return totalDistance;

}

void BestFirst::printPath(int initialCity)
{
    Path::iterator it;
    int i, currentCity;

    currentCity = initialCity;

    for(it = mypath.begin(), i = 0; it != mypath.end(); it++, i++)
    {
        cout << i + 1 << " - cidade " << currentCity << " ate cidade "
             << (*it).first << " - dist " << (*it).second << endl;
        currentCity = (*it).first;
    }



}

int BestFirst::getTotalDistance()
{
    return total_distance;
}
