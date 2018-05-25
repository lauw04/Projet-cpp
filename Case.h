#ifndef CASE_H
#define CASE_H
#include <iostream>
#include "Bacterie.h"
#include <vector>
using namespace std;

class Case{
  public:
  //Constructors
  Case();
  Case(float Ainit);
  
  //Destructors*
  ~Case();

  //Getters
	vector<float> external_c(); //retourne la concentration en organites A, B et C
	Bacterie* bacteria(); // retourne un pointeur vers la bactérie qui est dans la case
	
  //Setters
	void set_external_c(vector<float> external_c);
	void set_bacteria(char type); //ajoute une cellule étant donné son génotype
	
  //Methods
  bool is_empty(); //determine si la case contient une bactérie ou non.
  void reset(float Ainit); //re-initialise les concentration dans chaque cellule
  int death();
	void metabolism();

  protected:
  //Attributs

	vector<float> external_c_ = {0, 0, 0}; //Vecteur des concentrations en organites A, B et C dans la case hors des bactéries
	Bacterie* bacteria_; //Pointeur vers la bactérie éventuellement présente dans la case

};



#endif
