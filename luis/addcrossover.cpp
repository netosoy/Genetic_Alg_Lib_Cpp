#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;
using std::string;


int main(void){

//------------------------variables declaration-----------------------------------------
int parent1 [10];
int *ptr1;
ptr1=parent1;
int parent2 [10];
int *ptr2;
ptr2=parent2;
int son [10];
//int *ptrS;
//ptrS=son;

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

//------------------------random selection------------------------------

//-------------------------sum method-----------------------------------

for(vector<int>::size_type i=0;i<10;i++){
	son[i]=ptr1[i]+ptr2[i];
}

cout << "Son vector is:" << endl;
for(int i=0;i<10;i++){
	cout << son[i] << ",";
 }
cout << "]" << "\n\n" << endl;

//-------------------------minus method---------------------------------
for(vector<int>::size_type i=0;i<10;i++){
	son[i]=ptr1[i]-ptr2[i];
}

cout << "Son vector is:" << endl;
for(int i=0;i<10;i++){
	cout << son[i] << ",";
 }
cout << "]" << "\n\n" << endl;
return 0;
}
