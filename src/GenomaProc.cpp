#include "GenomaProc.hh"


int randomInt(int min, int max){		//random number from min to max-1, not include max
	srand(time(NULL));
	int output = min + (rand() % (int)(max - min));
	return output;
	}

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
