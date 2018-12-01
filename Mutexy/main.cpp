/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erik
 *
 * Created on December 1, 2018, 10:54 PM
 */

#include <cstdlib>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
      
/*
 * 
 */

struct arguments {
    const int arraySize;
    int firstFreeIndex;
    int* arrayOfFibNumbers;
    pthread_mutex_t* mutex;
    pthread_cond_t* condition;
};

void* computeFibNumbers(void* arg)
{
    arguments * p = (arguments*)arg;
    pthread_mutex_lock(p->mutex);
    int fibIndex = rand() % 41;
      
}

int getFinNumber(int n)
{
    if (n < 2)
    {
        return 1;
    } else {
        return getFinNumber(n-1) + getFinNumber(n-2);
    }
    
}



int main(int argc, char** argv) {
    
    while(true)
    {
        cout << "Ahoj" << endl;
    }


    return 0;
}

