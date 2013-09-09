/*Algoritmo BeamSearch
 *
 *De maneira geral o algoritmo funciona da seguinte forma:
 *Para cada cidade visitada, teremos 5 possiveis caminhos.
 *Ex: A cidade atual é a 7, escolhemos as 5 cidades mais proximas da cidade 7.
 *Para cada cidade destas 5 escolhias, escolhemos as respectivas mais proximas.
 *Entao, somanos o caminho da cidade 7 até a sua mais proxima e a mais proxima desta ultima.
 *Escolhemos a menor soma e visitamos as duas cidades pertencentes a essa menor soma.
 *O algorimto é iterado, até acabarem as cidades.
 */

#include "beamsearch.h"

#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <list>
#include <algorithm> //find
#include <cstdlib>
#include <limits>

BeamSearch::BeamSearch()
{
    total_distance = 0;
}

void BeamSearch::readFile()
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


void BeamSearch::startTrip()
{
    int initialCity, currentCity, nextCity1, nextCity2;
    list<int>::iterator it;



    //coloca cidades para serem visitadas
    for(int i = 0; i < total_cities; i++)
    {

        remainCities.push_back(i);
    }


    initialCity = 0;
    currentCity = initialCity;

    while(!remainCities.empty() && remainCities.size() > 1)
    {
        availablePaths.clear();
        availablePaths2.clear();

        makeFirstAvailablePaths(currentCity);


        for(it = availablePaths.begin(); it != availablePaths.end(); it++)
        {
            makeSecondAvailablePaths(*it);

        }

        calculateBestNextCity(currentCity, nextCity1, nextCity2);

        mypath.push_back(make_pair(nextCity1, mycities[currentCity][nextCity1]));
        total_distance += mycities[currentCity][nextCity1];
        remainCities.remove(nextCity1);

        if(!remainCities.empty())
        {
            mypath.push_back(make_pair(nextCity2, mycities[nextCity1][nextCity2]));
            remainCities.remove(nextCity2);
            total_distance += mycities[nextCity1][nextCity2];
        }

        currentCity = nextCity2;


    }

    if(remainCities.size() == 1)
    {
        mypath.push_back(make_pair(remainCities.front(), mycities[currentCity][remainCities.front()]));
        total_distance += mycities[currentCity][remainCities.front()];
        remainCities.pop_front();
    }




}

void BeamSearch::makeFirstAvailablePaths(int initialCity)
{
    int currentBestCityToVisit;
    int minorPath = 9999999;
    int i, k, totalAvailablePaths;

    list<int>::iterator it1, it2;

    //melhores cidades para initalCity
    if(remainCities.size() >= 5) totalAvailablePaths = 5;
    else totalAvailablePaths = remainCities.size();

    for(k = 0; k < totalAvailablePaths; k++)
    {
        for(i = 0; i < total_cities; i++)
        {
            if(mycities[initialCity][i] < minorPath && initialCity != i)
            {
                it1 = find(remainCities.begin(), remainCities.end(), i);
                it2 = find(availablePaths.begin(), availablePaths.end(), i);

                if(*it1 == i && *it2 != i)
                {

                    minorPath = mycities[initialCity][i];
                    currentBestCityToVisit = i;
                }

            }
        }

        availablePaths.push_back(currentBestCityToVisit);
       // cout <<"melhor distancia1 de " << initialCity << " ate " << currentBestCityToVisit << " tamanho " << minorPath << " \n";
        minorPath = 99999;
    }


}

void BeamSearch::makeSecondAvailablePaths(int initialCity)
{
    int currentBestCityToVisit = 0;
    int minorPath = 9999999;
    int i;

    list<int>::iterator it1, it2;


    for(i = 0; i < total_cities; i++)
    {
        if(mycities[initialCity][i] < minorPath && initialCity != i)
        {
            it1 = find(remainCities.begin(), remainCities.end(), i);
            it2 = find(availablePaths2.begin(), availablePaths2.end(), i);

            if(*it1 == i && *it2 != i)
            {

                minorPath = mycities[initialCity][i];
                currentBestCityToVisit = i;
            }

        }
    }



    availablePaths2.push_back(currentBestCityToVisit);
    //cout <<"melhor distancia de " << initialCity <<" ate " << currentBestCityToVisit << " tamanho " << minorPath << " \n";
    minorPath = 99999;



}

void BeamSearch::calculateBestNextCity(int initialCity, int &nextCity1, int &nextCity2)
{
    int minorSum = 999999;
    int sum = 0;

    list<int>::iterator it, it2;

    for(it = availablePaths.begin(), it2 = availablePaths2.begin(); it != availablePaths.end(); it++, it2++)
    {
        sum += mycities[initialCity][*it];
        //cerr << "acessando soma it " << *it << "it2 " << *it2 << " \n";
        sum += mycities[*it][*it2];

        if(sum < minorSum) {
            minorSum = sum;
            nextCity1 = *it;
            nextCity2 = *it2;
        }

    }


}


void BeamSearch::printPath(int initialCity)
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

int BeamSearch::getTotalDistance()
{
    return total_distance;
}

