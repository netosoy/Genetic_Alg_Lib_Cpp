/** @brief This libraries are needed to run some methods from GA_Crossover.cpp
 * */

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

/** @brief here we define vector size
 * **/
  
#define VSIZE 10

using namespace std;
using std::string;

/** @brief Each method is called and is shown kind of type it returns.
 * Vector managment and crossover methods are shown.
 * */
void print_vector(vector<int> &);
void fill_vector(vector<int> &);
vector<int> addCrossover(vector<int> &,vector<int> &);
vector<int> midpointCrossover(vector<int> &,vector<int> &);
vector<int> MultiValCross(vector<int> &, vector<int> &);


