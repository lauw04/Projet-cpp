#include <cstdio>
#include "Lignee_L.h"

//Constructors
Lignee_L::Lignee_L(double Raa, double Rab){
	Raa_ = Raa;
	Rab_ = Rab;
}

//Destructors

//Getters
double Lignee_L::Raa(){
	return Raa_;
}

double Lignee_L::Rab(){
	return Rab_;
}

//Setters

//Methods

double Lignee_L::metabolisme(double Aout){
	float A = c_interne_[0];
	c_interne_[0] += Aout*Raa_ - A*Rab_;
	c_interne_[1] += A*Rab_;
	return Aout*(1-Raa_);
}
