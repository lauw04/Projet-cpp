#include <cstdio>
#include "Lignee_L.h"

//Constructors
Lignee_L::Lignee_L(double Raa, double Rab){
	Raa_ = Raa;
	Rab_ = Rab;
}

//Destructors
Lignee_L::~Lignee_L() = default;

//Getters
double Lignee_L::Raa(){
	return Raa_;
}

double Lignee_L::Rab(){
	return Rab_;
}

double Lignee_L::w(){
	if (internal_c_[1] > W_min_){
		return internal_c_[1];
	}
	else{
		return 0;
	}
}

//Setters

//Methods

double Lignee_L::metabolism(double Aout){
	float A = internal_c_[0];
	internal_c_[0] += Aout*Raa_ - A*Rab_;
	internal_c_[1] += A*Rab_;
	return Aout*(1-Raa_);
}

int Lignee_L::nature(){
	return 1; //1 pour lignée L
}
