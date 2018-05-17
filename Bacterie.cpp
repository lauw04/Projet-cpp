#include <cstdio>
#include <cstdlib>
#include "Bacterie.h"

//Constructors
Bacterie::Bacterie(float Pmut, float Pdeath, float W_min){
  Pmut_ = Pmut;
  Pdeath_ = Pdeath;
  W_min_ = W_min;
}

Bacterie::Bacterie(){
	Pmut_ = 0.0;
	Pdeath_ = 0.02;
	W_min_ = 0.001;
}

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

vector<float> Bacterie::internal_c(){
	return internal_c_;
}

//Setters

void Bacterie::set_internal_c(vector<float> c){
	for (int i=0; i<3; ++i){
		internal_c_[i] = c[i];
	}
}

//Methods

vector<float> Bacterie::division(){
	for (int i=0; i<3; ++i){
		internal_c_[i] /= 2;
	}
	return internal_c_;
}
