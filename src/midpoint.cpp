#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <algorithm>



using namespace std;
using std::string;

//------------------------variables declaration-------------------------
vector<int> parent1 (10);
vector<int> parent2 (10);
vector<int> son (10);


//------------------------midpoint method-------------------------------




int main(void){
	
	


//------------------------parent1---------------------------------------
cout << "Enter values for the 10 sized vector parent1 on position: " << ": "<< endl;
for (vector<int>::size_type i = 0; i < 10; i++)
    {   
        cin >> parent1[i];
	}

cout << "parent1: [";
for(vector<int>::size_type i=0;i<10;i++){
	cout << parent1[i] << ",";
 }
cout << "]" << "\n\n" << endl;


//-------------------------parent2--------------------------------------
cout << "Enter values for the 10 sized vector parent2 on position: " << ": "<< endl;
for (vector<int>::size_type i = 0; i < 10; i++)
    {   
        cin >> parent2[i];
	}

cout << "parent2: [";
for(vector<int>::size_type i=0;i<10;i++){
	cout << parent2[i] << ",";
 }
cout << "]" << "\n\n" << endl;
 
//----------------midpoint method---------------------------------------
for(vector<int>::size_type i=0;i<10;i++){
	son[i]=(parent1[i]+parent2[i])/2;
}

	cout << "Son vector is:" << endl;
	cout << "[";
	for(vector<int>::size_type i=0;i<10;i++){
		cout << son[i] << ",";
	}
	cout << "]" << "\n\n" << endl;

 return 0;

}
