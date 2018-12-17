/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erik
 *
 * Created on December 17, 2018, 11:39 PM
 */

#include <cstdlib>
#include "AppControll.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    AppControll app;
    app.Construct();
    app.Start();
    app.Destruct();

    return 0;
}

