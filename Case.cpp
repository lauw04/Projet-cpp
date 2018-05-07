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

//Methods
