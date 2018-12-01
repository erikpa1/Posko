
#include <iostream>
#include "AppControll.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //includnute pre vlakna
#include <unistd.h>


int main()
{
	//AppControll app;
	//app.Construct();
	//std::cout << "Server going to start" << std::endl;
	//app.Start();	




	return 0;
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


typedef struct arguments {
	const int arraySize;
	int firstFreeIndex;
	int* arrayOfFibNumbers;
	pthread_mutex_t* mutex; //je zadefinovany ako smernik aby mi nevznikala kopia je to pri mutexoch nebezpecne moze to robit problemy
	pthread_cond_t* condition; //podmienkova premenna hovori ci bol pridany novy prvok
} ARGUMENTS;

//vypocita n-te fibonaciho cislo
int getFibNumber(int n) {
	if (n < 2)
	{
		return 1;
	}
	else
	{
		return getFibNumber(n - 1) + getFibNumber(n - 2);
	}
}

//funkcia ktoru ma vlakno vykonavat
void* computeFibNumbers(void* arg) {
	ARGUMENTS* p = (ARGUMENTS*)arg; //premenna berie veci z argumentov ... ktore sa vlozia do premennej p
	pthread_mutex_lock(p->mutex);
	while (p->firstFreeIndex < p->arraySize) {
		pthread_mutex_unlock(p->mutex);
		int fibIndex = rand() % 41;
		int fibNumber = getFibNumber(fibIndex); // ukladam si fibonaciho cislo pred kriticku cast lebo ma byt co najrychlesia
		//medzi lockom a unlockom by malo byt minimalizovane mnozstvo kodu
		//vlakno ktore mutex uzamkne ho musi aj odomknut
		pthread_mutex_lock(p->mutex); //zamknutie mutexu pred kritickou sekciou
		p->arrayOfFibNumbers[p->firstFreeIndex] = fibNumber; //vypocita fib cislo a vlozi ho na i tu poziciu
		p->firstFreeIndex++;
		pthread_mutex_unlock(p->mutex); //odomnknutie mutexu pred kritickou castou
		pthread_cond_signal(p->condition); //signalizuje ci bol pridany novy prvok do pola
	}
	return NULL;
}

//funkncia z vlakna bude sucastne citat a vypisovat na obrazovku cisla z pola pocas toho ako ina funkcia ich tam zapisuje. Chceme aby sa vypis robil priebezne a nie cely na konci.
void printOneFibNumber(void* arg) {
	ARGUMENTS* p = (ARGUMENTS*)arg;
	int i = 0;
	while (i < p->arraySize) { //p->firstFreeIndex sa modifikuje mal by som ju chranit mutexom        
		//pomocov mutexu zabezpecujem pristup k vzdielanej pamati lebo mam viacej vlakien
		//poomocov podmienkovej premennej cakam kym sa splni nejaka podmienka aby som tam nemusel mat nekonecny cyklus
		pthread_mutex_lock(p->mutex);//lockujem mutex pred p->firstFreeIndex lebo sa pocas kodu meni
		while (i >= p->firstFreeIndex) {
			pthread_cond_wait(p->condition, p->mutex); //ak plati tato podmienka zacni cakat na podmienke p->condition a odomkni p->mutex ... on odomkne mutex, caka na signalizacu, skoci nas5 a otvori mutex
		}
		pthread_mutex_unlock(p->mutex);

		printf("%d Fib Number is %d\n", i, p->arrayOfFibNumbers[i]);
		i++;
	}

}

void printFibNumbers(int fibNumbers[], int fibNumbersCount) {
	for (int i = 0; i < fibNumbersCount; i++) {
		printf("%d. Fib Number is %d\n", i, fibNumbers[i]);
	}
}

int main(int argc, char** argv) {
	pthread_t thread1;
	pthread_t thread2;//premenna pre vlakno nieco ako int len iny datovy typ
	pthread_t thread3;
	pthread_mutex_t mutex; //zaviedol som si mutex musim ho este inicializovat
	pthread_mutex_init(&mutex, NULL);//potrebna inicializacia mutexu
	pthread_cond_t condition; //tak isto ako mutex najprv zadeklarujem potokm inicializujem
	pthread_cond_init(&condition, NULL);

	int fibNumbersCount = 40;
	int* fibNumbers = malloc(sizeof(int) * fibNumbersCount); //pole ktore bude obsahovat fibonaciho cisla

	ARGUMENTS pThread1 = { fibNumbersCount, 0, fibNumbers, &mutex, &condition }; //inicializacia struktury

	pthread_create(&thread1, NULL, computeFibNumbers, &pThread1); //vytvori sa vlakno nastavia sa atributy a co ma robit
	pthread_create(&thread2, NULL, computeFibNumbers, &pThread1);
	pthread_create(&thread3, NULL, printOneFibNumber, &pThread1);



	pthread_join(thread1, NULL); //treba vlakno joinut
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	//tu sa konci praca s vlaknami treba mutex znicit
	pthread_mutex_destroy(&mutex);//znicenie mutexu
	pthread_cond_destroy(&condition);

	free(fibNumbers);

	return (EXIT_SUCCESS);
}

