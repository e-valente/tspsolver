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
    int currentDistance;


    //coloca cidades para serem visitadas
    for(int i = 0; i < total_cities; i++)
    {

        remainCities.push_back(i);
    }


    initialCity = 0;

    makeBufferCities(initialCity);

    list<int>::iterator it;

    cout << "bufers \n";

    for(it = currentBufferCities.begin(); it != currentBufferCities.end(); it++)
    {
        cout << *it;

    }



    for(int i = 0; i < total_cities; i++)
    {
        while(!currentBufferCities.empty())
        {
            tmpCity = currentBufferCities.front();
            currentBufferCities.pop_front();
            if(mycities[i][tmpCity] < minorPath ) {
               // cout <<"comparando distancia de " << i << " ate " << tmpCity <<" vale " <<mycities[i][tmpCity] << "\n";
                currentBestCityToVisit = tmpCity;
                minorPath = mycities[i][tmpCity];
            }


        }

    }

}


void HillClimbing::makeBufferCities(int currentCity)
{
    list<int>::iterator it;
    int bufferCity, sizeOfRemainCities, sizeCount;
    int count = 0;

    sizeOfRemainCities = remainCities.size();

    if(sizeOfRemainCities > 2) sizeCount = 3;
    else if(sizeOfRemainCities == 2) sizeCount = 2;
    else if(sizeOfRemainCities ==  1) sizeCount = 1;
    else if(sizeOfRemainCities == 0) sizeCount = 0;



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
        }

    }
}

