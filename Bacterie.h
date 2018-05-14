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
  vector<float> c_interne();
	virtual double w() = 0;

  //Setters
  void set_c_interne(vector<float> c);

  //Methods
  virtual double metabolisme(double out) = 0;
  vector<float> division();
  virtual int nature() = 0;
  
  protected:
  //Attributs  
	float Pmut_; //la probabilité de mutation
	float Pdeath_; //la probabilité de mort
	float W_min_; //la fitness minimale
	vector<float> c_interne_ = {1,2,3}; //vecteur de concentrations des métabolites dans la cellule (A, B, C)
};



#endif
