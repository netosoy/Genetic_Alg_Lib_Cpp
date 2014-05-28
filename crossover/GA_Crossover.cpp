#include "GA_Crossover.hh"


void fill_vector(vector<int> &V){
	cout<<"enter the values of the vector"<<endl;
	for(int i=0;i<V.size();i++){
		cin>>V[i];
		}
}

void print_vector(vector<int> &V){
	cout<<"[ ";
	for(int i=0;i<V.size();i++){
		cout<<V[i]<<" ";
		}
	cout<<"]"<<endl;
	}

vector<int> addCrossover(vector<int> &ptr1,vector<int> &ptr2){
	
	srand (time(NULL));
	int r = rand() %2;
	vector<int> son(ptr1.size());
	
	if(r==0){//-------------------------sum method-----------------------------------
		for(vector<int>::size_type i=0;i<ptr1.size();i++){
			son[i]=ptr1[i]+ptr2[i];
			}
		}
else{//-------------------------minus method---------------------------------
	for(vector<int>::size_type i=0;i<ptr1.size();i++){
		son[i]=ptr1[i]-ptr2[i];
		}
	}
	return son;

}

vector<int> midpointCrossover(vector<int> &parent1,vector<int> &parent2){
	vector<int> son(parent1.size());

for(vector<int>::size_type i=0;i<parent1.size();i++){
	son[i]=(parent1[i]+parent2[i])/2;
	}
	return son;
}


//--------------------Multivalue crossover------------------------------------

vector<int> MultiValCross(vector<int> &parent1, vector<int> &parent2){
	vector<int> son(parent1.size());
	srand (time(NULL));
	int crosspoint =rand()%((unsigned int)parent1.size());
	cout<< "El valor de la variable para la posicion de cruce es:"<<crosspoint<<endl;
	for(int i=0; i<crosspoint; i++){
		son[i]=parent1[i];
		}
	for(int i=crosspoint; i<parent1.size(); i++){
		son[i]=parent2[i];
		}
	return son;
	}
