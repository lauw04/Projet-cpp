#ifndef ENVIRONNEMENT_H_
#define ENVIRONNEMENT_H_

#include <cstdio>
#include <cstdlib>
#include "Case.h"

class Environnement {
	
	public :
	//Constructors
  Environnement() = delete;
  Environnement(int W, int H, double Ainit, float D, int L, int S, float T);
  //Destructors

  //Setters
    
  //Getters
  int W();
  int H();
  double Ainit();
  Case** grid();
  float D();
  int L();
  int S();
  float T();
  
  //destructor
  ~Environnement();

  //Methods
  void fill_grid(); //remplit de manière aléatoire la grille avec des cellule L et S.  
  void reset();
	void death();
    
  protected :
	//Attributs
	int W_; //la grille
	int H_; //la grille
	double Ainit_; //Concentration de glucose initial
	Case** grille_; //grille 2D
	float D_; //Taux de diffusion
	int L_; //Nombre bactéries issues de la souche L
	int S_; //Nombre bactéries issues de la souche S
	float T_; //Pas de temps où les concentrations sont mises à zéro
		
};

#endif
