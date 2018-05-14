#include <cstdio>
#include <iostream>
#include <cstdlib>
#include "Environnement.h"
#include "Case.h"

//Constructors
Environnement::Environnement (int W, int H, double Ainit, float D, int L, int S, float T){
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
}
    
//Destructors

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
					grid_[i][j].set_bacterie('L');
					countL++;
				}
				else {
					grid_[i][j].set_bacterie('S');
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
				grid_[i][j].set_bacterie(remain);
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

//destructor

Environnement::~Environnement(){
  for(int i =0; i<H_; ++i){
    if (grid_[i]!=nullptr){
      delete[] grid_[i];
      }
    }
  delete[] grid_;
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

void Environnement::diffusion(){
	Case** grid_copy;
	grid_copy = new Case* [W_];
	for(int i=0; i<W_; ++i){
		grid_copy[i] = new Case[H_];
	}
	for (int i=0; i<H_; ++i){
		for (int j=0; j<W_; ++j){
			vector<float> old_c_externe = grid_copy[i][j].c_externe();
			vector<float> new_c_externe = grid_copy[i][j].c_externe();
			for (int k=-1; k<2; ++k){
				for (int l=-1; l<2; ++l){
					int y = 0; //horizontal
					int x = 0; //vertical
					if (i+k > H_-1){
						x = 0;
					}
					else if (i+k < 0){
						x = H_-1;
					}
					else{
						x = i+k;
					}
					if (j+l > W_-1){
						y = 0;
					}
					else if (j+l < 0){
						y = W_-1;
					}
					else{
						y = j+l;
					}
					if (k != 0 && l != 0){
						for (int m=0; m<3; ++m){
							new_c_externe[m] = new_c_externe[m] + D_*(grid_copy[x][y].c_externe()[m]);
						}
					}
				}
			}
			for (int m=0; m<3; ++m){
				new_c_externe[m] = new_c_externe[m] - 9*D_*old_c_externe[m];
			}
			grid_[i][j].set_c_externe(new_c_externe);
		}
	}
	for (int i=0; i<H_; ++i){
		delete[] grid_copy[i];
	}
	delete[] grid_copy;
	
					
}
