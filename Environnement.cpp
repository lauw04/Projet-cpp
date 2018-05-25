#include <cstdio>
#include <iostream>
#include <cstdlib>
#include "Environnement.h"
#include "Case.h"

//Constructors
Environnement::Environnement(){
  W_ = 32; 
  H_ = 32;
  Ainit_ = 23; 
  D_= 0.1; 
  L_= W_*H_/2; 
  S_ = W_*H_/2; 
  T_ = 500;
	grid_ = new Case* [W_];
	for(int i=0; i<W_; ++i){
		grid_[i] = new Case[H_];
	}
	fill_grid();
	t_simul_ = 5000;
}

Environnement::Environnement (int W, int H, double Ainit, float D, int L, int S, float T, int t_simul){
  W_ = W; 
  H_ = H;
  Ainit_ = Ainit;
  D_= D; 
  L_= L; 
  S_ = S; 
  T_ = T;
	grid_ = new Case* [W_];
	for(int i=0; i<W_; ++i){
		grid_[i] = new Case[H_];
	}
	fill_grid();
	t_simul_ = t_simul;
}
    
//Destructors

Environnement::~Environnement(){
	for(int i =0; i<H_; ++i){
		if (grid_[i]!=nullptr){
			delete[] grid_[i];
		}
	}
	delete[] grid_;
}

//Setters
void Environnement::fill_grid(){
	int countL = 0;
	int countS = 0;
	char remain;
	srand(time(NULL));
	for(int i=0; i<W_; ++i){
		for(int j=0; j<H_; ++j){
			if(countL < W_*H_/2 && countS < W_*H_/2){
				int random = rand()%2 +1;
				if (random==1){
					grid_[i][j].set_bacteria('L');
					countL++;
				}
				else {
					grid_[i][j].set_bacteria('S');
					countS++;
				}
				
				if(countL == W_*H_/2){
					remain = 'S';
				}
				if(countS == W_*H_/2){
					remain = 'L';
				}
			}
			else {
				grid_[i][j].set_bacteria(remain);
				if(remain == 'L'){
					countL++;
				}
				if(remain == 'S'){
					countS++;
				}
			}
		}
	}
}

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

Case** Environnement::grid(){
	return grid_;
}


float Environnement::D(){
  return D_;
}

int Environnement::L(){
  return L_;
}

int Environnement::S(){
  return S_;
}

float Environnement::T(){
  return T_;
}

//Methods
void Environnement::reset(){
  for (int i=0; i<H_; ++i){
    for (int j=0; j<W_; ++j){
      grid_[i][j].reset(Ainit_);
      }
    }
}

void Environnement::death(){
	int case_death;
	for (int i=0; i<H_; ++i){
		for (int j=0; j<W_; ++j){
			case_death = grid_[i][j].death();
			if (case_death == 1){
				L_--;
			}
			if (case_death == 2){
				S_--;
			}
		}
	}
}

void Environnement::run(){
	for (int t=0; t<t_simul_; ++t){
		if (t%(T_) == 0){
			reset();
		}
		diffusion();
		death();
		//competition();
		if (L_ == 0 && S_ == 0){
			return 0; //Extinction
		}
		else if (L_ != 0 && S_ != 0){
			return 1; //Cohabitation
		}
		else if (L_ != 0 && S_ == 0){
			return 2; //Exclusion
		}			
	}
}
