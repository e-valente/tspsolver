/*Algoritmo HillClimbing
 *De maneira geral o algoritmo funciona da seguinte forma:
 *Para cada cidade visitada ex: cidade 3, escolhe-se as
 *4 cidades mais adjacentes, no caso 1 e 2 (`a esquerda) e 4 e 5
 *(à direita). Dessas 4 cidades, nenhuma delas pode ter sido visitada,
 *caso isso ocorra, ex: cidade 1 ja foi visitada, escolhemos a zero
 *(vizinho a esquerda) e assim sucessivamente.
 *Para o mesmo exemplo, se a cidade 5 ja estiver sido visitada,
 *escolhemos a 6 (vizinho mais a direita), etc.
 */

#include "hillclimbing.h"


#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <list>
#include <algorithm> //find
#include <cstdlib>
#include <limits>

HillClimbing::HillClimbing()
{
    total_distance = 0;

}

void HillClimbing::readFile()
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


void HillClimbing::startTrip()
{
    int initialCity, tmpCity, currentBestCityToVisit;
    int minorPath = 9999999;

    //coloca cidades para serem visitadas
    for(int i = 0; i < total_cities; i++)
    {

        remainCities.push_back(i);
    }


    initialCity = 0;

    makeBufferCities(initialCity);

    list<int>::iterator it;


    /*
    cout << "bufers \n";
    for(it = currentBufferCities.begin(); it != currentBufferCities.end(); it++)
    {
        cout << *it;

    }
    */

    while(!remainCities.empty())
    {


        while(!currentBufferCities.empty())
        {
            tmpCity = currentBufferCities.front();
            currentBufferCities.pop_front();
            if(mycities[initialCity][tmpCity] < minorPath ) {
               // cout <<"comparando distancia de " << i << " ate " << tmpCity <<" vale " <<mycities[i][tmpCity] << "\n";
                currentBestCityToVisit = tmpCity;
                minorPath = mycities[initialCity][tmpCity];
            }




        }

        mypath.push_back(make_pair(currentBestCityToVisit, minorPath));
        total_distance += minorPath;

       // cout <<" iserindo de " << initialCity << " ate " << currentBestCityToVisit << " dist " << minorPath << "\n";

        remainCities.remove(currentBestCityToVisit);
        currentBufferCities.clear();
        makeBufferCities(currentBestCityToVisit);
        initialCity = currentBestCityToVisit;
        minorPath = 9999999;

    }



}


void HillClimbing::makeBufferCities(int currentCity)
{
    list<int>::iterator it;
    int bufferCity, sizeOfRemainCities, sizeCount;
    int count = 0;


    sizeOfRemainCities = remainCities.size();

    if(sizeOfRemainCities > 2) {
        sizeCount = 3;
        while(count < sizeCount){
            bufferCity = currentCity + count + 1;

            if(bufferCity >= total_cities) {
                bufferCity = 0;
                currentCity = 0;
            }

            it = find(remainCities.begin(), remainCities.end(), bufferCity);
            if(*it == bufferCity)
            {
                currentBufferCities.push_back(bufferCity);
                count++;
            } else currentCity++;

        }
    }
    else if(sizeOfRemainCities == 2) {
        currentBufferCities.push_back(remainCities.front());
        currentBufferCities.push_back(remainCities.back());
    }
    else if(sizeOfRemainCities ==  1) currentBufferCities.push_back(remainCities.front());

}

int HillClimbing::getTotalDistance()
{
    return total_distance;
}

void HillClimbing::printPath(int initialCity)
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

