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

void test_constructor_bacterie();
void test_environnement();

int main(){
  cout << "Hello world !" << endl;
  test_bacterie();
	cout << endl;
  test_case();
	test_environnement();
  return 0;
}

void test_bacterie(){
	cout << "Test constructeur bactéries" << endl;
  Bacterie b1(0, 0.02, 0.001);
  cout << "Pmut = " << b1.Pmut() << endl;
  cout << "Pdeath = " << b1.Pdeath() << endl;
  cout << "W_min = " << b1.W_min() << endl;

	cout << "Test constructeur bactérie lignée L" << endl;
	Lignee_L b2(0.1, 0.1);
	cout << "Raa = " << b2.Raa() << endl;
	cout << "Rab = " << b2.Rab() << endl;

	cout << "Test constructeur bactérie lignée S" << endl;
	Lignee_S b3(0.1, 0.1);
	cout << "Rbb = " << b3.Rbb() << endl;
	cout << "Rbc = " << b3.Rbc() << endl;
}

void test_environnement(){
  Environnement env(10, 12, 0.5, 0.3,0.8,0.7,0.5);
  cout << "W = " << env.W() << endl;
  cout << "H = " << env.H() << endl;
  cout << "Ainit = " << env.Ainit() << endl;
  //cout << "grille = " << env.grille() << endl;
  cout << "L = " << env.L() << endl;
  cout << "S = " << env.S() << endl;
  cout << "T = " << env.T() << endl;
}

void test_case(){
	Case case1(5.);
	vector<float> organites = case1.c_externe();
	cout << "c_externe : " << endl;
	for(vector<float>::const_iterator it = organites.begin(); it != organites.end(); ++it){
		cout << *it << endl;
	}
	cout << "test isEmpty()" << endl;
	cout << "case1.isEmpty() : " << case1.isEmpty() << endl;

}
