#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;
using std::string;

//------------------------variables declaration-----------------------------------------
vector<int> parent1 (10);
vector<int> parent2 (10);
vector<int> son (10);
int b,c,d, son;
//------------------------midpoint method------------------------------------------------




int main(void){
	


//int round(float c);
//cout << c+1<< endl;

//------------------------parent1-----------------------------------------------------
cout << "Enter values for the 10 sized vector parent1 on position: " << ": "<< endl;
for (vector<int>::size_type i = 0; i < 9; i++)
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
for (vector<int>::size_type i = 0; i < 9; i++)
    {   
        cin >> parent2[i];
	}

cout << "parent2: [";
for(vector<int>::size_type i=0;i<10;i++){
	cout << parent2[i] << ",";
 }
cout << "]" << "\n\n" << endl;
 
//----------------midpoint method cases---------------------------------------------

//----------------a=b---------------------------------------------------------------

if (a==b){
	cout << a;
}

//-------------------a||b=0---------------------------

if (a||b=0){
	if(a=0){
		c = b/2;
        int round(float c);
        cout << c+1<< endl;     //We include +1 because round always round number to minor valor
    }
    else
    c = a/2;
    int round(float c);
    cout << c+1<< endl;
}

//---------------------a!=b-------------------------------

if (a!=b){
	c=a-b;
	int abs(int c);
	d=c/2;
	int round(float d);
	if (a > b){
		son = b+d+1;
	}
	else
	son = a+d+1;
	cout <<son<<endl;
}



 return 0;

}
