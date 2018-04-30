#ifndef CASE_H
#define CASE_H
#include <iostream>
#include "Bacterie.h"
#include <vector>
using namespace std;

class Case{
  public:
  //Constructors

  //Destructors

  //Getters

  //Setters

  //Methods
  
  protected:
  //Attributs

	vector<float> c_externe_; //Vecteur des concentrations en organites A, B et C dans la case hors des bactéries
	Bacterie* bacterie_; //Pointeur vers la bactérie éventuellement présente dans la case

};



#endif
