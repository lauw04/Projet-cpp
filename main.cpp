#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "Bacterie.h"
#include "Case.h"
#include "Environnement.h"
#include "Lignee_L.h"
#include "Lignee_S.h"
#include <vector>
using namespace std;

void test_bacterie();
void test_environnement();
void test_case();

int main(){
  cout << "Hello world !" << endl;
  test_bacterie();
	cout << endl;
  test_case();
	cout << endl;
	test_environnement();
  return 0;
}

void test_bacterie(){
	cout << "TEST BACTERIE" << endl;
	cout << "Test constructeur bactérie lignée L" << endl;
	Lignee_L b1(0.1, 0.1);
	cout << "Raa = " << b1.Raa() << endl;
	cout << "Rab = " << b1.Rab() << endl;

	cout << "Test constructeur bactérie lignée S" << endl;
	Lignee_S b2(0.1, 0.1);
	cout << "Rbb = " << b2.Rbb() << endl;
	cout << "Rbc = " << b2.Rbc() << endl;

	cout << "Test méthode métabolisme" << endl;
	vector<float> organites1 = b1.internal_c();
	vector<float> organites2 = b2.internal_c();
	for(vector<float>::const_iterator it = organites1.begin(); it != organites1.end(); ++it){
		cout << *it << endl;
	}
	for(vector<float>::const_iterator it = organites2.begin(); it != organites2.end(); ++it){
		cout << *it << endl;
	}
	cout << endl;
	double c_ext_a = b1.metabolism(0.5);
	double c_ext_b = b2.metabolism(0.2);
	cout << "Nouvelle concentration externe A : " << c_ext_a << endl;
	cout << "Nouvelle concentration externe B : " << c_ext_b << endl;
	vector<float> organites3 = b1.internal_c();
	vector<float> organites4 = b2.internal_c();
	for(vector<float>::const_iterator it = organites3.begin(); it != organites3.end(); ++it){
		cout << *it << endl;
	}
	for(vector<float>::const_iterator it = organites4.begin(); it != organites4.end(); ++it){
		cout << *it << endl;
	}

	cout << "Test getter w (fitness)" << endl;
	cout << "Fitness b1 : " << b1.w() << endl;
	cout << "Fitness b2 : " << b2.w() << endl;

  cout << "Test méthode division" << endl;
	b1.division();
	vector<float> organites5 = b1.internal_c();
	for(vector<float>::const_iterator it = organites5.begin(); it != organites5.end(); ++it){
		cout << *it << endl;
	}
	
	cout << "Test setter de concentration interne" << endl;
	b1.set_internal_c(organites1);
	for(vector<float>::const_iterator it = organites1.begin(); it != organites1.end(); ++it){
		cout << *it << endl;
	}
}

void test_environnement(){
	cout << "TEST ENVIRONNEMENT" << endl;

  Environnement env(4, 4, 0.5, 0.3, 8, 7, 0.5, 0.0);
  cout << "W = " << env.W() << endl;
  cout << "H = " << env.H() << endl;
  cout << "Ainit = " << env.Ainit() << endl;
  cout << "D = " << env.D() << endl;
  cout << "L = " << env.L() << endl;
  cout << "S = " << env.S() << endl;
  cout << "T = " << env.T() << endl;
  cout << "Pmut = " << env.Pmut() << endl;
  
  /*Environnement envi;
  cout << "W = " << envi.W() << endl;
  cout << "H = " << envi.H() << endl;
  cout << "Ainit = " << envi.Ainit() << endl;
  cout << "D = " << envi.D() << endl;
  cout << "L = " << envi.L() << endl;
  cout << "S = " << envi.S() << endl;
  cout << "T = " << envi.T() << endl;*/
}

void test_case(){
	cout << "TEST CASE" << endl;
	cout << " >> test ctor et getters" << endl;
	Case case1(5.);
	vector<float> organites = case1.external_c();
	cout << "external_c_ : " << endl;
	for(vector<float>::const_iterator it = organites.begin(); it != organites.end(); ++it){
		cout << *it << endl;
	}
	
	cout << " >> test is_empty()" << endl;
	cout << "case1.is_empty() : " << case1.is_empty() << endl;
	
	cout << " >> test setters" << endl;
	organites[1] = 2. ; organites[2] = 3.;
	case1.set_external_c(organites);
	vector<float> organites2 = case1.external_c();
	cout << "external_c : " << endl;
	for(vector<float>::const_iterator it = organites2.begin(); it != organites2.end(); ++it){
	cout << *it << endl;
	}
	
	case1.set_bacteria('L');
	cout << "case1.is_empty() : " << case1.is_empty() << " bacteria_ : " << case1.bacteria() << endl;
	
	cout << " >> Test reset" << endl;
	case1.reset(5.);
	organites = case1.external_c();
	for(vector<float>::const_iterator it = organites.begin(); it != organites.end(); ++it){
	cout << *it << endl;
	}

	cout << " >> Test death" << endl;
	cout << "case1.death() : " << case1.death() << endl;
	cout << case1.bacteria() << endl;
}
