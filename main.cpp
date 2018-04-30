#include <iostream>
#include <cstdio>
#include "Bacterie.h"
#include "Case.h"
#include "Environnement.h"
using namespace std;

void test_constructor_bacterie();

int main(){
  cout << "Hello world !" << endl;
  test_constructor_bacterie();
  return 0;
}

void test_constructor_bacterie(){
  Bacterie bact(0, 0.02, 0.001);
  cout << "Pmut = " << bact.Pmut() << endl;
  cout << "Pdeath = " << bact.Pdeath() << endl;
  cout << "W_min = " << bact.W_min() << endl;
}
