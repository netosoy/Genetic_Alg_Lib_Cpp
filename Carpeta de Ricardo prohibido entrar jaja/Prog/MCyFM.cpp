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

/////////////////////////////////////////////prototypes/////////////////////////////////////////////////////


vector<int> indiv1 ;
int sizeindiv1;
vector<int> indiv2 ;
int sizeindiv2;
vector<int> son;
vector<int> son2 ;
//vector<int>::iterator it;


//---------------------------------- Crossover ---------------------------------------
void CROSSOVER(vector<int>x, vector<int>y, int size){
	int CROSSPOINT;
	double vectorDivisor;
  /* initialize random seed: */
	srand (time(NULL));

  /* generate secret number between 1 and 4: */
	CROSSPOINT = rand() % 4 + 1;	
    cout << "The number of croospoints is: " << CROSSPOINT<<endl;

switch(CROSSPOINT){
	
case 1:

son2.resize(size);
vectorDivisor = floor((son2.size())/2 + 0.5);
son2.insert(son2.begin(), x.begin(), x.end());
son2.insert(son2.begin()+vectorDivisor, y.begin(),y.end());
//Mando 9999999999999999999999999999999999999999999999999999999999999
//Se divide vector a la mitad y si es necesario se redondea y se rellena con vector1 y vector2 por partes iguales

break;

case 2:

//Se divide vector entre tres, se redondea y se rellena con v1, v2, v1

break;

case 3:

//Se divide vector entre 4

break;

case 4:
//Se divide en 5 (habria que pedir que el numero de genes "sizeindiv1" y "sizeindiv2" no sea menor a 10)
break;

default:
cout << "you should check what you entered";
break; 
}
}

//------------------------------------------Flip Mutation---------------------------------------------
int FMUT(int a) {
	
	int MutVar = rand() % 4 + 1;
	if (MutVar<son2.size() && a<son2.size()){
		
		for (int i=0; i<=MutVar; i++){
		son2[(2*i)]=MutVar + a;
		
		son2[(2*i)+1]=a-MutVar+3;
	}
	}
	else {
		return 0;
	}
	
	return 0;
	
}


int main()
{
	cout<< "Enter the number of genes for individual's 1 chromosome" << endl;
	cin >> sizeindiv1;
	
	cout<< "Enter the number of genes for individual's 2 chromosome" << endl;
	cin >> sizeindiv2;
	
	indiv1.resize (sizeindiv1);
	indiv2.resize (sizeindiv2);
	
    for (vector<int>::size_type i = 0; i < sizeindiv1; i++)
    {
        cout << "Enter values for the vector indiv1 on position: " << i+1 << ": "<< flush;
        cin >> indiv1[i];
	}
		cout << "\n\n\n\n"; 
	for (vector<int>::size_type n = 0; n < sizeindiv2; n++)
    {
        cout << "Enter values for the vector indiv2 on position: " << n+1 << ": "<< flush;
        cin >> indiv2[n];
	}
	
		son.reserve(indiv1.size() + indiv2.size() ); // preallocate memory
		son.insert( son.begin(), indiv1.begin(), indiv1.end() );
		son.insert( son.end(), indiv2.begin(), indiv2.end() );
		cout << "\n\n" << "The Multivalue Crossover algorithm is gonna give the following sequence for son\n\n";

		for (int w=0; w<19; w++){
		cout<< son[w]<<", ";
	}
	
		//CROSSOVER(indiv1, indiv2, sizeindiv1);
		//FMUT(CROSSPOINT);
	
	return 0;
}



