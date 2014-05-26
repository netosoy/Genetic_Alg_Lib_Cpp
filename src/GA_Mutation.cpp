#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <algorithm>
//#include "Platform.hh"
//#include "Threading.hh"
//#include "Random.hh"

#define VNAME(x)  #x 
#define VSIZE 10

using namespace std;
int randomInt(int, int);
void print_vector(vector<int> &);
void fill_vector(vector<int> &);
void swapPos(int, int,vector<int> &);
void GaInvertMutation(vector<int> &, int);
void GaSwapMutation(vector<int> &, int);

//vector<int> A(7);
vector<int> B(VSIZE);

int main(void){
	srand (time(NULL));
	vector<int> A(VSIZE);
	//print_vector(A);
	fill_vector(A);
	GaInvertMutation(A,VSIZE);
	cout<<"inverse muted vector A"<<endl;
	print_vector(A);
	cout<<"swap muted vector A"<<endl;	
	GaSwapMutation(A,VSIZE);
	print_vector(A);
	}
	
int randomInt(int min, int max){
	int output = min + (rand() % (int)(max - min));
	return output;
	}	

void print_vector(vector<int> &V){
	//cout<<"The vector "<<VNAME(V)<<":"<<endl<<"[";
	cout<<"[ ";
	for(int i=0;i<V.size();i++){
		cout<<V[i]<<" ";
		}
	cout<<"]"<<endl;
	}

void fill_vector(vector<int> &V){
	cout<<"enter the values of the vector"<<endl;
	for(int i=0;i<V.size();i++){
		cin>>V[i];
		}
	}
void GaInvertMutation(vector<int> &V, int n){
	for(int i=0;i<n;i++){
		//cout<<"generando numero aleatorio: "<<randomInt(0,V.size())<<endl;
		V[randomInt(0,V.size())]*=-1;
		}
	}
void swapPos(int i, int j, vector<int> &V){
	int aux = V[i];
	V[i]=V[j];
	V[j]=aux;
	}
void GaSwapMutation(vector<int> &V, int n){
	for(int i=0;i<n;i++){
		swapPos(randomInt(0,V.size()),randomInt(0,V.size()),V);
		}
	}

