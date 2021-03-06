#include <cstdio>
#include <iostream>
#include <cstdlib>
#include "Environnement.h"
#include "Case.h"
#include <fstream>

#define couleur(param) printf("\033[%sm",param)

//Constructors
Environnement::Environnement(){
  W_ = 32; 
  H_ = 32;
  Ainit_ = 23; 
  D_= 0.1; 
  L_= W_*H_/2; 
  S_ = W_*H_/2; 
  T_ = 500;
  Pmut_ = 0.0;
	grid_ = new Case* [W_];
	for(int i=0; i<W_; ++i){
		grid_[i] = new Case[H_];
	}
	fill_grid();
	t_simul_ = 5000;
}

Environnement::Environnement (int W, int H, float D, int L, int S, int T, int t_simul, float Pmut){
  W_ = W; 
  H_ = H;
  Ainit_ = 23;
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

int Environnement::T(){
  return T_;
}

float Environnement::Pmut(){
  return Pmut_;
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
			vector<float> old_external_c = grid_copy[i][j].external_c();
			vector<float> new_external_c = grid_copy[i][j].external_c();
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
							new_external_c[m] = new_external_c[m] + D_*(grid_copy[x][y].external_c()[m]);
						}
					}
				}
			}
			for (int m=0; m<3; ++m){
				new_external_c[m] = new_external_c[m] - 9*D_*old_external_c[m];
			}
			grid_[i][j].set_external_c(new_external_c);
		}
	}
	for (int i=0; i<H_; ++i){
		delete[] grid_copy[i];
	}
	delete[] grid_copy; 					
}

void Environnement::competition(){
  for (int i=0; i<H_;++i){ //hauteur
    for (int j=0; j<W_; j++){ //largeur
      if(grid_[i][j].is_empty()== true){ //look for empty case
        int max_fitness=0;
        int v_max;
        int h_max;
        //browser neighbourhood
        for (int l=-1; l<2;l++){ //hauteur
          for (int k=-1; k<2; k++){ //largeur
            if(!(k==0 && l==0)){
              int v;
              int h;
              //edge conditions
              if (i+l>H_-1){
                h=0;
              }
              else if (i+l<0){
                h=H_-1;
              }
              else{
                h=i+l;
              }

              if (j+k>W_-1){
                v=0;
              }
              else if (j+k<0){
                v=W_-1;
              }
              else{
                v= j+k;
              }
              

              //test if the neighbourhood case contains a cell
              if(grid_[h][v].is_empty() == false){
              //the neighbourhood case contains a cell
              //looks for the neighbouring cell with highest fitness
                if((grid_[h][v].bacteria())->w() > max_fitness){
                  max_fitness = (grid_[h][v].bacteria())->w();
                  //cout  << "fitness max" << max_fitness << endl;
                  h_max= h;
                  v_max= v;
                }
              }
            }
          }
        }
        //cout << (grid_[h_max][v_max].bacteria())->nature() << endl;
        //cout << h_max << " " << v_max << endl;
        if(max_fitness>0){ //the dividing cell will mutate
          float number = (float)rand() / (float)RAND_MAX;
          //fill the case with adequate cell (mutating...)
          char c;
          if((grid_[h_max][v_max].bacteria())->nature() == 1){ //if case contains L
            if(number >= Pmut_){
              c='L';
            }
            else{
              c='S';
              L_--;
              S_++;
            }
          }
          else{ //if case contains S
            if(number >= Pmut_){
              c='S';
            }
            else{
              c='L';
              S_--;
              L_++;
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
          if (c=='L'){
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

void Environnement::metabolism(){
	for (int i=0; i<H_; ++i){
		for (int j=0; j<W_; ++j){
			grid_[i][j].metabolism();
		}
	}
}


int Environnement::show(){
	for (int i=0; i<H_; i++){
		for(int j=0; j<W_; j++){
			if((grid_[i][j].bacteria())->nature() == 1){
				couleur("34");
				printf("a ");
				couleur("0");
			}
			else if((grid_[i][j].bacteria())->nature() == 2){
				couleur("31");
				printf("b ");
				couleur("0");
			}
			else{
				cout << "  ";
			}
		}
		cout << endl;
	}
	if(S_==0){
		if(L_==0){
			cout << "Extinction" << endl;
			return 0;
		}
		else{
			cout << "Exclusion" << endl;
			return 1;
		}
	}
	else{
		if(L_==0){
			cout << "Selection" << endl;
			return 1;
		}
		else{
			cout << "Cohabitation" << endl;
			return 2;
		}
	}
}

/**
 * returns 0 in case of extinction, 1 in case of exclusion and 2 in case of cohabitation
 **/
int Environnement::state(){
	if(S_ == 0 and L_ ==0){
		return 0;
	}
	if(L_== 0 or S_ == 0){
		return 1;
	}
	return 2;
}


int Environnement::run(int t){
	ofstream file("Chroniques.txt", ios::out | ios::trunc);
	ofstream file2("Fitness.txt", ios::out | ios::trunc);
	int nb = 0;
	int sumL;
	int sumS;
	if(file){  
		file2 << "t " << "meanL " << "meanS" << endl; 
		file << "t " << "L_ " << "S_" << endl;
		show();
		
		for (int k=0; k<t; k++){
			cout << k << endl;
			if(k%(T_) == 0){
				reset();
			}
			
			sumL = 0;
			sumS = 0;
			for (int i=0; i<H_; i++){
				for(int j=0; j<W_; j++){
					if(grid_[i][j].is_empty()!=1){
						if((grid_[i][j].bacteria())->nature()==1){
							sumL += (grid_[i][j].bacteria())->w();
						}
						else{
							sumS += (grid_[i][j].bacteria())->w();
						}
					}
				}
			}
			file2 << k << " " << sumL/L_ << " " << sumS/S_ << endl;
				diffusion();
				death();
				competition();
				nb = show();
			  	for(int i=0; i<10; ++i){
					metabolism();
				}
				file << k << " " << L_ << " " << S_ << endl;
				if(nb == 0){
					break;
				}
		}
		file.close();
		file2.close();
	}	
	else{
		cerr << "File opening error !" << endl;
	}
	return nb;			
}
