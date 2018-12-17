/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Data.h
 * Author: Erik
 *
 * Created on Pondelok, 2018, decembra 17, 14:58
 */

#ifndef DATA_H
#define DATA_H



#endif /* DATA_H */

using namespace std;

struct data {
    
    vector<string> * datapool;
    pthread_mutex_t * mutex;
    pthread_cond_t * condt;
    int lastIndex = 0;
    
};
