#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#define VSIZE 10

//declaración de métodos
int randomInt(int, int);
void print_vector(vector<int> &);
void fill_vector(vector<int> &);
void swapPos(int, int,vector<int> &);
void GaInvertMutation(vector<int> &, int);
void GaSwapMutation(vector<int> &, int);
