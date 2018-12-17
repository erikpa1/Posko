/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erik
 *
 * Created on Utorok, 2018, decembra 11, 23:11
 */

#include "AppControll.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    
    try {
        AppControll control;
        control.Construct();
        control.Start();        
    } catch (std::exception)
    {
        
    }    

    return 0;
}

