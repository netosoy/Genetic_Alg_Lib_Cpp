#include "GA_Crossover.hh"

int main(void){
	vector<int> padre1(10);
	vector<int> padre2(10);
	
	cout << "LLENANDO PADRE1" << endl;
	fill_vector(padre1);
	cout << "LLENANDO PADRE2" << endl;
	fill_vector(padre2);
	
	cout << " PADRE1" << endl;
	print_vector(padre1);
	cout << " PADRE2" << endl;
	print_vector(padre2);
	
	vector<int> hijo1(10);
	vector<int> hijo2(10);
	
	hijo1 = addCrossover(padre1,padre2);
	hijo2 = midpointCrossover(padre1,padre2);
	
	cout << " HIJO1" << endl;
	print_vector(hijo1);
	cout << " HIJO2" << endl;
	print_vector(hijo2);
	
	
	return 0;
	
	}
