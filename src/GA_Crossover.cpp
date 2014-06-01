#include "GA_Crossover.hh"

/**
 * @brief This is a Genetic Algorithm library, in this document vector managment
 * methods and crossover methods are shown.
 * */
 
 /** 
  * @brief This method fill vector by the user
  * @param Manual input by user
  * @return Filled vector.
  * */
void fill_vector(vector<int> &V){
	cout<<"enter the values of the vector"<<endl;
	for(int i=0;i<V.size();i++){
		cin>>V[i];
		}
}

 /** 
  * @brief This method prints parents and son vector.
  * @param V[i] vector is recieved.
  * @return Printed vector.
  * */
  
void print_vector(vector<int> &V){
	cout<<"[ ";
	for(int i=0;i<V.size();i++){
		cout<<V[i]<<" ";
		}
	cout<<"]"<<endl;
	}

/** 
  * @brief Add crossover method, it adds or subtractc each input of the parents among them.
  * It depends of a random number: 0,1. 
  * @param parent[1] parent[2].
  * @return son vector.
  * */
vector<int> addCrossover(vector<int> &ptr1,vector<int> &ptr2){
	
	srand (time(NULL));
	int r = rand() %2;
	vector<int> son(ptr1.size());
	
	if(r==0){
/** @brief Add method.
 * */		
		for(vector<int>::size_type i=0;i<ptr1.size();i++){
			son[i]=ptr1[i]+ptr2[i];
			}
		}
else{
/** @brief Subtraction method.
 * */	
	for(vector<int>::size_type i=0;i<ptr1.size();i++){
		son[i]=ptr1[i]-ptr2[i];
		}
	}
	return son;

}

/** 
 * @brief Midpoint crossover. It consist to find a midpoint among parents vectors .
 * @param parent1 parent2
 * @return son vector
 * */
 
vector<int> midpointCrossover(vector<int> &parent1,vector<int> &parent2){
	vector<int> son(parent1.size());

for(vector<int>::size_type i=0;i<parent1.size();i++){
	son[i]=(parent1[i]+parent2[i])/2;
	}
	return son;
}


/**
 *  @brief Multivalue crossover method. It takes some inputs from one parent
 * and replace inputs in the other parent randomly.
 * @param parent1 parent2
 * @return son vector
**/

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
