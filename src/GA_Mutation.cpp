#include "GA_Mutation.hh"

int randomInt(int min, int max){		//random number from min to max-1, not include max
	srand(time(NULL));
	int output = min + (rand() % (int)(max - min));
	return output;
	}	

void print_vector(vector<int> &V){
	//cout<<"The vector "<<VNAME(V)<<":"<<endl<<"[";
	cout<<"[ ";
	for(int i=0;i<(int) V.size();i++){
		cout<<V[i]<<" ";
		}
	cout<<"]"<<endl;
	}

void fill_vector(vector<int> &V){
	cout<<"enter the values of the vector"<<endl;
	for(int i=0;i<(int) V.size();i++){
		cin>>V[i];
		}
	}
void GaInvertMutation(vector<int> &V, int n){
	for(int i=0;i<n;i++){
		srand(time(NULL));
		//cout<<"generando numero aleatorio: "<<randomInt(0,(int) V.size())<<endl;
		V[randomInt(0,(int) V.size())]*=-1;
		}
	}
void swapPos(int i, int j, vector<int> &V){
	int aux = V[i];
	V[i]=V[j];
	V[j]=aux;
	}
void GaSwapMutation(vector<int> &V, int n){
	for(int i=0;i<n;i++){
		srand(time(NULL));
		swapPos(randomInt(0,(int) V.size()),randomInt(0,(int) V.size()),V);
		}
	}
void FlipMutation(vector<int> &V, int n) {
	
	int nVal=randomInt(0,n);
	for(int i=0;i<nVal;i++){
		srand(time(NULL));
		V[randomInt(0,(int) V.size())]=randomInt(0,20);
		}
	//vector<int> aux2((int) V.size());
	//aux2 = V;
	
	//	aux2[MutVar+1]=MutVar*8;
		
    //    aux2[MutVar-1]=MutVar-33;
		
	//	return aux2;
	}
