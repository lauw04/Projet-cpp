#ifndef CASE_H
#define CASE_H
#include <iostream>
#include "Bacterie.h"
#include <vector>
using namespace std;

class Case{
  public:
  //Constructors
  Case() = delete;
  Case(float Ainit);
  
  //Destructors

  //Getters
	vector<float> c_externe(); //retourne la concentration en organites A, B et C
	
  //Setters

  //Methods
  
  protected:
  //Attributs

	vector<float> c_externe_ = {0, 0, 0}; //Vecteur des concentrations en organites A, B et C dans la case hors des bactéries
	Bacterie* bacterie_; //Pointeur vers la bactérie éventuellement présente dans la case

};



#endif
