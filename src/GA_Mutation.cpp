#include "GenomaProc.hh"
#include "GA_Mutation.hh"

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
