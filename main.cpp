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

#define couleur(param) printf("\033[%sm",param)

void Rdiagram(int Tmin, int Tmax, float Amin, float Amax, int Pt, float Pa, float Pmut, float D);
void diagram(int Tmin, int Tmax, int Amin, int Amax, int Pt, int Pa, float Pmut);

//==============================
//    MAIN
//==============================

int main(int argc, char const *argv[])
{   
	start :
	cout << "Vous vous apretez a simuler le developpement cellulaire de deux lignees en situation de crossfeeging." << endl;
	//cout << "Pour effectuer une simulation, tapez 1." << endl;
	//cout << "Pour obtenir un diagramme de phase du systeme, tapez 2." << endl;
	//int n;
	//cin >> n;
	float D = 0.1;
	int t;
	//if(n==1){
		cout << "Veuillez entrer un temps de simulation : " << endl;
		cin >> t;
		cout << "C'est parti!" << endl;
		Environnement env;
		env.run(t);
		system("Rscript Chroniques.R Chroniques.txt Chroniques.jpeg");
		system("Rscript Fitness.R Fitness.txt Fitness.jpeg");
		
		cout << "Fin de la simulation. Visualisez les courbes de population des 2 genotypes dans le fichier Chroniques.jpeg." << endl;
		cout << "Visualisez les courbes de fitness moyenne des 2 genotypes dans le fichier Fitness.jpeg." << endl;
	//}
	/*else if(n==2){
		float Amin, Amax, iA, Pmut;
		int Tmin, Tmax, iT;
		cout << "Veuillez rentrer les valeurs suivantes, pour definir les axes du diaramme : Amin (>=0)" << endl;
		cin >> Amin;
		cout << "Amax (<=50) :" << endl;
		cin >> Amax;
		cout << "Increment pour Ainit : " << endl;
		cin >> iA;
		cout << "Tmin (>= 1): " << endl;
		cin >> Tmin;
		cout << "Tmax (<= 1500): " << endl;
		cin >> Tmax;
		cout << "Increment pour T : " << endl;
		cin >> iT;
		cout << "C'est parti!" << endl;
		
		Rdiagram(Tmin,Tmax,Amin,Amax,iT,iA,D);
		system("Rscript Plot_heatmap_p.R Rdiagram.txt Diagramme.pdf");
		
		cout << "Fin de la simulation. Visualisez le diagramme dans le fichier Diagramme.pdf." << endl;
	}
	else{
		cout << "Vous devez taper 1 ou 2 " << endl;
	}*/
	int again;
	cout << "Relancer le programme? Tapez 3. Sinon, n'importe quoi d'autre." << endl;
	cin >> again;
	if(again == 3){
		goto start;
	}
	cout << "Bye!" << endl;
    return 0;
}

//==============================
//    FUNCTIONS
//==============================

/**
 * Computes the final state of the simulations for each Ainit and T and write them in a file 
 * Parameters are the extremal values of the diagram axis, and the step for each one.
 * Mutation probability and diffusion constant are also asked
 */
/*void Rdiagram(int Tmin, int Tmax, float Amin, float Amax, int Pt, float Pa, float D){
	ofstream file("Rdiagram.txt", ios::out | ios::trunc);
	if(file){ 
		int cpt = 0;
		file << "Ainit " << "T " << "val" << endl;
		int nb_it = (Tmax-Tmin+Pt)/Pt*(Amax-Amin+Pa)/Pa;
		for(int T=Tmin; T<=Tmax; T+=Pt){
			for (float A=Amin; A<=Amax; A+=Pa){
				cpt++;
				cout << " Simulation " << cpt << " / " << nb_it << ", Ainit = " << A << " T = " << T;				
				Environnement env = Environnement(A,T,D,Pmut);
				float result = env.run_diagram(1000);
				file << A << " " << T << " " << result << endl;
				if (result==0){
					couleur("30");
					printf("			Extinction \n");
				}
				else if (result==1){
					couleur("31");
					printf("			Selection \n");
				}
				else{
					couleur("32");
					printf("			Cohabitation \n");
				}
				couleur("0");
			}
		}
		file.close();		
	}	
	else{
		cerr << "File opening error !" << endl;
	}
}*/