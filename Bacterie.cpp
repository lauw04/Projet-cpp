#include <cstdio>
#include <cstdlib>
#include "Bacterie.h"

//Constructors

Bacterie::Bacterie(){
<<<<<<< HEAD
  Pdeath_ = 0.5;
=======
  Pdeath_ = 0.2;
>>>>>>> 673b2f4684bbed09b6bd782952c74673a8168dd2
	W_min_ = 0.001;
}

//Destructors
Bacterie::~Bacterie() = default;

//Getters

float Bacterie::W_min(){
  return W_min_;
}

float Bacterie::Pdeath(){
  return Pdeath_;
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
