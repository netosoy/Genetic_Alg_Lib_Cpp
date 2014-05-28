#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

 
#define VSIZE 10

using namespace std;
using std::string;

void print_vector(vector<int> &);
void fill_vector(vector<int> &);
vector<int> addCrossover(vector<int> &,vector<int> &);
vector<int> midpointCrossover(vector<int> &,vector<int> &);
vector<int> MultiValCross(vector<int> &, vector<int> &);


