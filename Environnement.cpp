#include <cstdio>
#include <cstdlib>
#include "Environnement.h"


//Constructors
Environnement::Environnement (int W, int H, double Ainit, Case** grille, float D, float L, float S, float T){
  W_ = W; 
  H_ = H;
  Ainit_ = Ainit; 
  grille_ = grille; 
  D_= D; 
  L_= L; 
  S_ = S; 
  T_ = T;

}
    
//Destructors

//Setters
   
//Getters
int Environnement::W(){
  return W_;
}

int Environnement::H(){
  return H_;
}    

double Environnement::Ainit(){
  return Ainit_;
}

Case** Environnement::grille(){
	return grille_;
}


float Environnement::D(){
  return D_;
}

float Environnement::L(){
  return L_;
}

float Environnement::S(){
  return S_;
}

float Environnement::T(){
  return T_;
}

//Methods
/*void Environnement::reset(){
	bacteries_={Ainit,0.,0.};
}*/
//Attributs


