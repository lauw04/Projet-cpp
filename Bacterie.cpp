#include <cstdio>
#include "Bacterie.h"

//Constructors
Bacterie::Bacterie(float Pmut, float Pdeath, float W_min){
  Pmut_ = Pmut;
  Pdeath_ = Pdeath;
  W_min_ = W_min;
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

//Setters

//Methods
