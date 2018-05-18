#ifndef LIGNEE_S_H
#define LIGNEE_S_H
#include <iostream>
#include "Bacterie.h"

class Lignee_S : public Bacterie{
  public:
  //Constructors
  Lignee_S(double Rbb, double Rbc);

  //Destructors
  virtual ~Lignee_S();

  //Getters
  double Rbb();
  double Rbc();
  double w(); //Fitness

  //Setters

  //Methods
  double metabolism(double out);
  int nature();
  
  protected:
  //Attributs  
	double Rbb_;
	double Rbc_;
};



#endif
