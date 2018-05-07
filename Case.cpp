#include <iostream>
#include <vector>
#include "Case.h"
#include "Bacterie.h"
using namespace std;

//Constructors
Case::Case(float Ainit){
	c_externe_[0] = Ainit;
	bacterie_ = nullptr;
}

//Destructors

//Getters
vector<float> Case::c_externe(){
	return c_externe_;
}

//Setters
void Case::set_c_externe(vector<float> c_externe){
	for(int i = 0; i < 3; ++i){
		c_externe_[i] = c_externe[i];
	}
}

/*void Case::set_bacterie(){

}*/

//Methods
bool Case::is_empty(){
	if (bacterie_ = nullptr){
		return true;
	return false;
	}
}
