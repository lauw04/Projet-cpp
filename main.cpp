#include <iostream>
#include <cstdio>
#include "Bacterie.h"
#include "Case.h"
#include "Environnement.h"
using namespace std;

void test_constructor_bacterie();
void test_constructor_environnement();

int main(){
  cout << "Hello world !" << endl;
  test_constructor_bacterie();
  test_constructor_environnement();
  return 0;
}

void test_constructor_bacterie(){
  Bacterie bact(0, 0.02, 0.001);
  cout << "Pmut = " << bact.Pmut() << endl;
  cout << "Pdeath = " << bact.Pdeath() << endl;
  cout << "W_min = " << bact.W_min() << endl;
}

void test_constructor_environnement(){
  Environnement env(10, 12, 0.5, 0.3,0.8,0.7,0.5);
  cout << "W = " << env.W() << endl;
  cout << "H = " << env.H() << endl;
  cout << "Ainit = " << env.Ainit() << endl;
  //cout << "grille = " << env.grille() << endl;
  cout << "L = " << env.L() << endl;
  cout << "S = " << env.S() << endl;
  cout << "T = " << env.T() << endl;
}
