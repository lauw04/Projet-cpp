#ifndef BACTERIE_H
#define BACTERIE_H
#include <iostream>
#include <vector>
using namespace std;

class Bacterie{
  public:
  //Constructors
  Bacterie();
	Bacterie(float Pmut, float Pdeath, float W_min);

  //Destructors

  //Getters
	float Pmut();
	float Pdeath();
	float W_min();

  //Setters

  //Methods
  
  protected:
  //Attributs  
	float Pmut_; //la probabilité de mutation
	float Pdeath_; //la probabilité de mort
	float W_min_; //la fitness minimale
	vector<float> c_interne_; //vecteur de concentrations des métabolites dans la cellule (A, B, C)
};



#endif
