#include <iostream>
#include <Planche.h>
#include <ctime>


/**
 * @file main.cpp
 * @author Mauranyapin Jean-Baptiste 
 * @auhor Derory Quentin
 * @version 1.0
 * @date 13 novembre 2014
 * */


int main(){

  srand(time(NULL));

  Planche jeu(5);
  
  jeu.simulation(1000);

  return 0;
}
