#ifndef ENVIRONNEMENT_H_
#define ENVIRONNEMENT_H_

#include <cstdio>
#include <cstdlib>
#include "Case.h"

class Environnement {
	
	public :
	//Constructors
  Environnement() = delete;
  Environnement(int W, int H, double Ainit, float D, float L, float S, float T);
    //Destructors

    //Setters
    
    //Getters
  int W();
  int H();
  double Ainit();
  Case** grille();
  float D();
  float L();
  float S();
  float T();

    //Methods
    
  protected :
		//Attributs
		int W_; //la grille
		int H_; //la grille
		double Ainit_; //Concentration de glucose initial
		Case** grille_; //grille 2D
		float D_; //Taux de diffusion
		float L_; //Nombre bactéries issues de la souche L
		float S_; //Nombre bactéries issues de la souche S
		float T_; //Pas de temps où les concentrations sont mises à zéro
		
};

#endif
