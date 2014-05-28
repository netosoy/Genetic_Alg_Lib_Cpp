#include"GA_Mutation.hh"

int main(void){
	vector<int> genoma(VSIZE);
	cout<<"Creando genoma"<<endl;
	fill_vector(genoma);
	cout<<"GENOMA"<<endl;
	print_vector(genoma);
	cout<<"Modificando el genoma"<<endl;
	GaSwapMutation(genoma,3);
	GaInvertMutation(genoma,5);
	print_vector(genoma);
	}
