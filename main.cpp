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
void test_case();

int main(){
  cout << "Hello world !" << endl;
  test_bacterie();
	cout << endl;
  test_case();
  return 0;
}

void test_bacterie(){
	cout << "Test constructeur bactérie lignée L" << endl;
	Lignee_L b1(0.1, 0.1);
	cout << "Raa = " << b1.Raa() << endl;
	cout << "Rab = " << b1.Rab() << endl;

	cout << "Test constructeur bactérie lignée S" << endl;
	Lignee_S b2(0.1, 0.1);
	cout << "Rbb = " << b2.Rbb() << endl;
	cout << "Rbc = " << b2.Rbc() << endl;

	cout << "Test méthode métabolisme" << endl;
	vector<float> organites1 = b1.c_interne();
	vector<float> organites2 = b2.c_interne();
	for(vector<float>::const_iterator it = organites1.begin(); it != organites1.end(); ++it){
		cout << *it << endl;
	}
	for(vector<float>::const_iterator it = organites2.begin(); it != organites2.end(); ++it){
		cout << *it << endl;
	}
	cout << endl;
	double c_ext_a = b1.metabolisme(0.5);
	double c_ext_b = b2.metabolisme(0.2);
	cout << "Nouvelle concentration externe A : " << c_ext_a << endl;
	cout << "Nouvelle concentration externe B : " << c_ext_b << endl;
	vector<float> organites3 = b1.c_interne();
	vector<float> organites4 = b2.c_interne();
	for(vector<float>::const_iterator it = organites3.begin(); it != organites3.end(); ++it){
		cout << *it << endl;
	}
	for(vector<float>::const_iterator it = organites4.begin(); it != organites4.end(); ++it){
		cout << *it << endl;
	}
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
