#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;
using std::string;

//------------------------variables declaration-----------------------------------------
int parent1 [10];
int parent2 [10];
int son [10];





int main(void){


//--------------------------parent1-----------------------------------------------------
cout << "Enter values for the 10 sized vector parent1 on position: " << ": "<< endl;
for (int i = 0; i < 9; i++)
    {   
        cin >> parent1[i];
	}

cout << "parent1: [";
for(vector<int>::size_type i=0;i<10;i++){
	cout << parent1[i] << ",";
 }
cout << "]" << "\n\n" << endl;


//-------------------------parent2----------------------------------------------------
cout << "Enter values for the 10 sized vector parent2 on position: " << ": "<< endl;
for (int i = 0; i < 9; i++)
    {   
        cin >> parent2[i];
	}

cout << "parent2: [";
for(int i=0;i<10;i++){
	cout << parent2[i] << ",";
 }
cout << "]" << "\n\n" << endl;

//-------------------------sum method------------------------------------------------

int parent1*, parent2*, son*;
for(int i = 0; i < 9; i++){   
     
	}



return 0;
}
