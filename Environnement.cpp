#include <cstdio>
#include <iostream>
#include <cstdlib>
#include "Environnement.h"
#include "Case.h"

//Constructors
Environnement::Environnement (int W, int H, double Ainit, float D, int L, int S, float T, float Pmut){
  W_ = W; 
  H_ = H;
  Ainit_ = Ainit; 
  D_= D; 
  L_= L; 
  S_ = S; 
  T_ = T;
  Pmut_ = Pmut;
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

float Environnement::Pmut(){
  return Pmut_;
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

void Environnement::competition(){
  for (int i=0; i<H_;++i){
    for (int j=0; j<W_; j++){
      if(grid_[i][j].is_empty()== true){ //look for empty case
        int max_fitness=0;
        int v_max =0;
        int h_max=0;
        //browser neighbourhood
        for (int k=-1; k<2;k++){
          for (int l=-1; l<2; l++){
            if(k!=0 && l!=0){
              int v=0;
              int h=0;
              //edge conditions
              if (i+k>H_-1){
                v=0;
              }
              else if (i+k<0){
                v=H_-1;
              }
              else{
                v= i+k;
              }
              if (j+l>W_-1){
                h=0;
              }
              else if (j+l<0){
                h=W_-1;
              }
              else{
                h=j+1;
              }
              //test if the neighbourhood case contains a cell
              if( grid_[h][v].is_empty() == false){ //the neighbourhood case contains a cell
              //looks for the neighbouring cell with highest fitness
                if((grid_[h][v].bacteria())->w()>max_fitness){
                  max_fitness = (grid_[h][v].bacteria())->w();
                  h_max= h;
                  v_max= v;
                }
              }
            }
          }
        }
        if(max_fitness>0){
          float number;
          //the dividing cell will mutate
          number = (float)rand() / (float)RAND_MAX;
          //fill the case with adequate cell (mutating...)
          char c;
          if((grid_[h_max][v_max].bacteria())->nature() == 1){ //if case contains L
            if(number >= Pmut_){
              c='l';
            }
            else{
              c='s';
            }
          }
          else{ //if case contains S
            if(number >= Pmut_){
              c='s';
            }
            else{
              c='l';
            }
          }
          vector <float> metabolites = (grid_[h_max][v_max].bacteria())->division();
          if(number >= Pmut_){
            delete grid_[h_max][v_max].bacteria();
            grid_[h_max][v_max].set_bacteria(c);
            (grid_[h_max][v_max].bacteria())->set_internal_c(metabolites);
          }
       
          grid_[i][j].set_bacteria(c);
          (grid_[i][j].bacteria())->set_internal_c(metabolites);
          if (c=='l'){
            L_++;
          }
          else{
            S_++;
          }
        }
      }
    }
  }
}
       
        
      
                
                
       
