#ifndef LIGNEE_L_H
#define LIGNEE_L_H
#include <iostream>
#include "Bacterie.h"

class Lignee_L : public Bacterie{
  public:
  //Constructors
  Lignee_L(double Raa, double Rab);

  //Destructors
  virtual ~Lignee_L();

  //Getters
  double Raa();
  double Rab();
	double w(); //Fitness

  //Setters

  //Methods
	double metabolism(double out);
  int nature();
  
  protected:
  //Attributs  
	double Raa_;
	double Rab_;
	
};



#endif
