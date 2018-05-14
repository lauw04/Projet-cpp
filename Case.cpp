#include <iostream>
#include <vector>
#include "Case.h"
#include "Bacterie.h"
#include "Lignee_L.h"
#include "Lignee_S.h"
using namespace std;

//Constructors
Case::Case() = default;

Case::Case(float Ainit){
	c_externe_[0] = Ainit;
	bacterie_ = nullptr;
}

//Destructors

//Getters
vector<float> Case::c_externe(){
	return c_externe_;
}

Bacterie* Case::bacterie(){
	return bacterie_;
}

//Setters
void Case::set_c_externe(vector<float> c_externe){
	for(int i = 0; i < 3; ++i){
		c_externe_[i] = c_externe[i];
	}
}

void Case::set_bacterie(char type){
	if (type == 'L'){
		bacterie_ = new Lignee_L(0.1, 0.1);
	}
	else {
		bacterie_ = new Lignee_S(0.1, 0.1);
	}
}


//Methods
bool Case::is_empty(){
	if (bacterie_ == nullptr){
		return true;
	}
	return false;
}

void Case::reset(float Ainit){
	c_externe_ = {Ainit, 0., 0.};
}

// Renvoie 0 s'il n'y a pas eu de mort, 1 si une cellule L est morte, 2 si une cellule S est morte
int Case::death(){
	char lignee;
	if (bacterie_){
		if (bacterie_ -> nature() == 1){
			lignee = 'L';
		}
		else{
			lignee = 'S';
		}
		float nombre = 0;
  	srand(time(NULL));
  	nombre = (float)rand() / (float)RAND_MAX;
		vector<float> organites = bacterie_ -> c_interne();
		if (nombre < bacterie_ -> Pdeath()){
			for (int i=0; i<3; ++i){
				c_externe_[i] += organites[i];
			}
		}
		bacterie_ = nullptr;
	}
	if (lignee == 'L'){
		return 1;
	}
	else if (lignee == 'S'){
		return 2;
	}
	return 0;
}
