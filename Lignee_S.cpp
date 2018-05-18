#include <cstdio>
#include "Lignee_S.h"

//Constructors
Lignee_S::Lignee_S(double Rbb, double Rbc){
	Rbb_ = Rbb;
	Rbc_ = Rbc;
}

//Destructors

//Getters
double Lignee_S::Rbb(){
	return Rbb_;
}

double Lignee_S::Rbc(){
	return Rbc_;
}

double Lignee_S::w(){
	if (internal_c_[2] > W_min_){
		return internal_c_[2];
	}
	else{
		return 0;
	}
}

//Setters

//Methods

double Lignee_S::metabolism(double Bout){
  float B = internal_c_[1];
	internal_c_[1] += Bout*Rbb_ - B*Rbc_;
	internal_c_[2] += B*Rbc_;
	return Bout*(1-Rbb_);
}

int Lignee_S::nature(){
	return 2; //2 pour lignée S
}
