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

void print_vector(vector<int> &);
void fill_vector(vector<int> &);
vector<int> MultiValCross(vector<int> &, vector<int> &);



int main(){
	vector<int> indiv1(5);
	vector<int> indiv2(5);
	vector<int> son(5);
	fill_vector(indiv1);
	print_vector(indiv1);
	fill_vector(indiv2);
	print_vector(indiv1);
	print_vector(indiv2);
	son = MultiValCross(indiv1, indiv2);
	print_vector(son);
	return 0;
	}

void print_vector(vector<int> &V){
	cout<<"[ ";
	for(int i=0;i<V.size();i++){
		cout<<V[i]<<" ";
		}
	cout<<"]"<<endl;
	}

void fill_vector(vector<int> &V){
	cout<<"enter the values of the vector"<<endl;
	for(int i=0;i<V.size();i++){
		cin>>V[i];
		}
	}
vector<int> MultiValCross(vector<int> &X, vector<int> &V){
	vector<int> aux(X.size());
	int crp =rand() % X.size();
	for(int i=0; i<crp;i++){
		aux[i]=X[i];
		}
	for(int i=crp; i<X.size();i++){
		aux[i]=V[i];
		}
	return aux;
	}
