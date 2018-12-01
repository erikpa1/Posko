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


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //includnute pre vlakna
#include <unistd.h>
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


int getFinNumber(int n)
{
    if (n < 2)
    {
        return 1;
    } else {
        return getFinNumber(n-1) + getFinNumber(n-2);
    }
    
}

void* computeFibNumbers(void* arg)
{
    arguments * p = (arguments*)arg;
    pthread_mutex_lock(p->mutex);
    while(p->firstFreeIndex < p->arraySize)
    {
        pthread_mutex_unlock(p->mutex);
        int fibIndex = rand() % 41;
        int fibNumber = getFinNumber(fibIndex);
        pthread_mutex_lock(p->mutex);
        p->arrayOfFibNumbers[p->firstFreeIndex] = fibNumber;
        p->firstFreeIndex++;
        pthread_mutex_unlock(p->mutex);
        pthread_cond_signal(p->condition);
    }
    
    return NULL;      
}

void * printOneFibNumber(void * arg)
{
    arguments * p = (arguments*)arg;
    int i = 0;
    while(i < p->arraySize)
    {
        pthread_mutex_lock(p->mutex);
        while(i >= p->firstFreeIndex)
        {
            pthread_cond_wait(p->condition, p->mutex);
        }
        pthread_mutex_unlock(p->mutex);

         cout << i << " Fib nubmer is " << p->arrayOfFibNumbers[i] << endl;
    }
    
    return NULL;
}


void printFibNumbers(int fibNumbers[], int fibNumbersCount)
{
    for (int i = 0; i < fibNumbersCount; i++)
    {
        cout << i << " Fib nubmer is " << fibNumbers[i] << endl;
    }
    
}


int main(int argc, char** argv) {
    
    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_t condition;
    pthread_cond_init(&condition, NULL);
    
    int fibNumbersCount = 40;
    int * fibNumbers = new int[fibNumbersCount];
    
    arguments pthread1 = {fibNumbersCount, 0, fibNumbers, &mutex, &condition};
    
    pthread_create(&thread1, NULL, computeFibNumbers, &pthread1);
    pthread_create(&thread2, NULL, computeFibNumbers, &pthread1);
    pthread_create(&thread3, NULL, printOneFibNumber, &pthread1);
    
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&condition);
    
    delete [] fibNumbers;
    

    return 0;
}

