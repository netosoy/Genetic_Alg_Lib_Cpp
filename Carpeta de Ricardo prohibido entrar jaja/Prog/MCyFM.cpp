#include <string>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using std::string;

//---------------------------------- Crossover ---------------------------------------


void print_vector(vector<int> &);

void fill_vector(vector<int> &);

vector<int> MultiValCross(vector<int> &, vector<int> &);


//-----------------------------------Flip Mutation-------------------------------------


vector<int> FMUT(vector<int> &);



//--------------------------------------Main-------------------------------------------

int main(){
	vector<int> indiv1(5);
	vector<int> indiv2(5);
	vector<int> son(5);
	cout<<"For the individual 1 -->"<<endl;
	fill_vector(indiv1);
	print_vector(indiv1);
	cout<<"\n\n";
	cout<<"For the individual 2 -->"<<endl;
	fill_vector(indiv2);
	//print_vector(indiv1);
	print_vector(indiv2);
	cout<<"\n\n";
	son = MultiValCross(indiv1, indiv2);
	cout<<"The Multivalue Crossover is gonna give the following sequence -->"<<endl;
	print_vector(son);
	cout<<"\n\n";
	cout<<"The Flip Mutation applied on the individuals offspring is gonna give the following mutated sequence-->"<<endl;
	son=FMUT(son);
	print_vector(son);
	return 0;
	}

void print_vector(vector<int> &V){
	cout<<"[ ";
	for(int i=0;i<V.size();i++){
		cout<<V[i]<<" ";
		}
	cout<<"]"<<endl;
	}

void fill_vector(vector<int> &V){
	
	for(int i=0;i<V.size();i++){
		cout<<"Enter the values for the vector on position #" << i+1 << ": "<<endl;
		cin>>V[i];
		}
	}
	
vector<int> MultiValCross(vector<int> &X, vector<int> &Y){
	vector<int> aux(X.size());
	srand (time(NULL));
	int crosspoint =rand() % X.size();
	cout<< "El valor de la variable para la posicion de cruce es:"<<crosspoint<<endl;
	for(int i=0; i<crosspoint; i++){
		aux[i]=X[i];
		}
	for(int i=crosspoint; i<X.size(); i++){
		aux[i]=Y[i];
		}
	return aux;
	}
	
vector<int> FMUT(vector<int>&V) {
	
	srand (time(NULL));
	int MutVar = rand() % V.size()-4 + (V.size()+2);
    cout<< "El valor de la variable para la posicion de mutacion es:"<<MutVar<<endl;
	vector<int> aux2(V.size());
	aux2 = V;
	
		aux2[MutVar+1]=MutVar*8;
		
        aux2[MutVar-1]=MutVar-33;
		
		return aux2;
	}
