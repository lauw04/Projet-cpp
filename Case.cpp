#include <iostream>
#include <vector>
#include "Case.h"
#include "Bacterie.h"
#include "Lignee_L.h"
#include "Lignee_S.h"
using namespace std;

//Constructors

Case::Case(){
	external_c_[0] = 23;
	bacteria_ = nullptr;
}

//Destructors
Case::~Case(){
	if(bacteria_ != nullptr){
		delete bacteria_;
	}
}

//Getters
vector<float> Case::external_c(){
	return external_c_;
}

Bacterie* Case::bacteria(){
	return bacteria_;
}

//Setters
void Case::set_external_c(vector<float> c_externe){
	for(int i = 0; i < 3; ++i){
		external_c_[i] = external_c_[i];
	}
}

void Case::set_bacteria(char type){
	if (type == 'L'){
		bacteria_ = new Lignee_L(0.1, 0.1);
	}
	else {
		bacteria_ = new Lignee_S(0.1, 0.1);
	}
}


//Methods
bool Case::is_empty(){
	if (bacteria_ == nullptr){
		return true;
	}
	return false;
}

void Case::reset(float Ainit){
	external_c_ = {Ainit, 0., 0.};
}

// Renvoie 0 s'il n'y a pas eu de mort, 1 si une cellule L est morte, 2 si une cellule S est morte
int Case::death(){
	char line;
	if (bacteria_){
		if (bacteria_ -> nature() == 1){
			line = 'L';
		}
		else{
			line = 'S';
		}
		float number = 0;
  	srand(time(NULL));
  	number = (float)rand() / (float)RAND_MAX;
		vector<float> metabolites = bacteria_ -> internal_c();
		if (number < bacteria_ -> Pdeath()){
			for (int i=0; i<3; ++i){
				external_c_[i] += metabolites[i];
			}
			delete bacteria_;
			bacteria_ = nullptr;
		}
	}
	if (line == 'L'){
		return 1;
	}
	else if (line == 'S'){
		return 2;
	}
	return 0;
}

void Case::metabolism(){
	if (bacteria_){
		if(bacteria_ -> nature() == 1){
			external_c_[0] = bacteria_ -> metabolism(external_c_[0]);
		}
		else{
			external_c_[1] = bacteria_ -> metabolism(external_c_[1]);
		}
	}
}
