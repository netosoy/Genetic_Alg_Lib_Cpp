#include <string>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;
using std::string;

#define RANDOM_NUM ((float)rand()/(RAND_MAX+1))

/////////////////////////////////prototypes/////////////////////////////////////////////////////

vector<int> indiv1 (10);
vector<int> indiv2 (10);
vector<int> son;
vector<int> son2 (10);



int main()
{ 
    for (vector<int>::size_type i = 0; i < 9; i++)
    {
        cout << "Enter values for the 5 sized vector indiv1 on position: " << i+1 << ": "<< flush;
        cin >> indiv1[i];
	}
		cout << "\n\n\n\n"; 
	for (vector<int>::size_type n = 0; n < 9; n++)
    {
        cout << "Enter values for the 5 sized vector indiv2 on position: " << n+1 << ": "<< flush;
        cin >> indiv2[n];
	}
	
		son.reserve(indiv1.size() + indiv2.size() ); // preallocate memory
		son.insert( son.end(), indiv1.begin(), indiv1.end() );
		son.insert( son.end(), indiv2.begin(), indiv2.end() );
		cout << "\n\n" << "The Multivalue Crossover algorithm is gonna give the following sequence";

		for (int w=0; w<19; w++){
		cout<< son[w]<<", ";
	}
		CROSSOVER(indiv1, indiv2);
	return 0;
}


//---------------------------------- Crossover ---------------------------------------
void CROSSOVER(int x[], int y[]){
	int CROSSPOINT;
  /* initialize random seed: */
	srand (time(NULL));

  /* generate secret number between 1 and 10: */
	CROSSPOINT = rand() % 5 + 1;	
  //cout << CROSSPOINT;

switch(CROSSPOINT){
	
case 1:
son2[1]=x[1];
son2[2]=x[2];
son2[3]=x[3];
son2[4]=x[4];
son2[5]=y[5];
son2[6]=y[6];
son2[7]=y[7];
son2[8]=y[8];
son2[9]=y[9];
son2[10]=y[10];

for (int w=0; w<9; w++){
		cout << son2[w]<<", ";
	}

break;


case 2:

son2[1]=x[1];
son2[2]=x[2];
son2[3]=x[3];
son2[4]=x[4];
son2[5]=y[5];
son2[6]=y[6];
son2[7]=y[7];
son2[8]=y[8];
son2[9]=x[9];
son2[10]=x[10];

for (int w=0; w<9; w++){
		cout << son2[w]<<", ";
	}

break;

case 3:
son2[1]=x[1];
son2[2]=x[2];
son2[3]=y[3];
son2[4]=y[4];
son2[5]=y[5];
son2[6]=y[6];
son2[7]=x[7];
son2[8]=x[8];
son2[9]=x[9];
son2[10]=y[10];

for (int w=0; w<9; w++){
		cout << son2[w]<<", ";
	}

break;
/*
case 4:


break;

case 5:



break;

case 6:

break;

case 7:

break;

case 8:

break;

case 9:

break;

case 10:

break;
*/

default:
cout << "you should check what you entered";
break; 
}
}
