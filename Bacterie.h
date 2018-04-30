#ifndef BACTERIE_H
#define BACTERIE_H
#include <iostream>
#include <vector>
using namespace std;

class Bacterie{
  public:
  //Constructors

  //Destructors

  //Getters

  //Setters

  //Methods
  
  protected:
  //Attributs  
	double Pmut_; //la probabilité de mutation
	double Pdeath_; //la probabilité de mort
	float W_min_; //la fitness minimale
	vector<float> c_interne_; //vecteur de concentrations des métabolites dans la cellule (A, B, C)
};



#endif
