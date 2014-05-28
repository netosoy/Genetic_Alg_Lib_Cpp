#include "GA_Mutation.hh"

int randomInt(int min, int max){
	srand (time(NULL));
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

