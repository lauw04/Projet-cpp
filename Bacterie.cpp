#include <cstdio>
#include <cstdlib>
#include "Bacterie.h"

//Constructors
Bacterie::Bacterie(float Pmut, float Pdeath, float W_min){
  Pmut_ = Pmut;
  Pdeath_ = Pdeath;
  W_min_ = W_min;
}

Bacterie::Bacterie() = default;

//Destructors

//Getters
float Bacterie::Pmut(){
  return Pmut_;
}

float Bacterie::Pdeath(){
  return Pdeath_;
}

float Bacterie::W_min(){
  return W_min_;
}

vector<float> Bacterie::c_interne(){
	return c_interne_;
}

//Setters

void Bacterie::set_c_interne(vector<float> c){
	for (int i=0; i<3; ++i){
		c_interne_[i] = c[i];
	}
}

//Methods

vector<float> Bacterie::division(){
	for (int i=0; i<3; ++i){
		c_interne_[i] /= 2;
	}
	return c_interne_;
}
