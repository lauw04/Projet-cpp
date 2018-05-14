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
  return c_interne_[2];
}

//Setters

//Methods

double Lignee_S::metabolisme(double Bout){
  float B = c_interne_[1];
	c_interne_[1] += Bout*Rbb_ - B*Rbc_;
	c_interne_[2] += B*Rbc_;
	return Bout*(1-Rbb_);
}
