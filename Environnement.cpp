#include <cstdio>
#include <cstdlib>
#include "Environnement.h"
#include "Case.h"

//Constructors
Environnement::Environnement (int W, int H, double Ainit, float D, float L, float S, float T){
  W_ = W; 
  H_ = H;
  Ainit_ = Ainit; 
  D_= D; 
  L_= L; 
  S_ = S; 
  T_ = T;
	grille_ = new Case* [W_];
	for(int i=0; i<W_; ++i){
		grille_[i] = new Case[H_];
	}
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
    
//Attributs


