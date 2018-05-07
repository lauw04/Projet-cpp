#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "Bacterie.h"
#include "Case.h"
#include "Environnement.h"
#include "Lignee_L.h"
#include "Lignee_S.h"
using namespace std;

void test_constructeur_bacterie();
void test_constructeur_lignee_L();

int main(){
  cout << "Hello world !" << endl;
  test_constructeur_bacterie();
	test_constructeur_lignee_L();
  return 0;
}

void test_constructeur_bacterie(){
  Bacterie bact(0, 0.02, 0.001);
  cout << "Pmut = " << bact.Pmut() << endl;
  cout << "Pdeath = " << bact.Pdeath() << endl;
  cout << "W_min = " << bact.W_min() << endl;
}

void test_constructeur_lignee_L(){
	Lignee_L bact(0.1, 0.1);
	cout << "Raa = " << bact.Raa() << endl;
	cout << "Rab = " << bact.Rab() << endl;
}
