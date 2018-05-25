#ifndef BACTERIE_H
#define BACTERIE_H
#include <iostream>
#include <vector>
using namespace std;

class Bacterie{
  public:
  //Constructors
  Bacterie();

  //Destructors

  //Getters
	float W_min();
  vector<float> internal_c();
	virtual double w() = 0;
	float Pdeath();

  //Setters
  void set_internal_c(vector<float> c);

  //Methods
  virtual double metabolism(double out) = 0;
  vector<float> division();
  virtual int nature() = 0;
  
  protected:
  //Attributs  
	float W_min_; //la fitness minimale
	float Pdeath_;
	vector<float> internal_c_ = {1,2,3}; //vecteur de concentrations des métabolites dans la cellule (A, B, C)
};



#endif
