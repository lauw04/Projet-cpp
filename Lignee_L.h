#ifndef LIGNEE_L_H
#define LIGNEE_L_H
#include <iostream>
#include "Bacterie.h"

class Lignee_L : public Bacterie{
  public:
  //Constructors
  Lignee_L(double Raa, double Rab);

  //Destructors

  //Getters
  double Raa();
  double Rab();

  //Setters

  //Methods
  
  protected:
  //Attributs  
	double Raa_;
	double Rab_;
	
};



#endif
