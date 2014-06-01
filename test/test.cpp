#include "GA_Mutation.hh"

int main(void){
	int gen1[VSIZE]={0,1,2,3,4,5,6,7,8,9};
	int gen2[VSIZE]={9,8,7,6,5,4,3,2,1,0};
	int gen3[VSIZE]={0,2,4,6,8,10,12,14,16,18};
	vector<int> genoma1(&gen1[0], &gen1[0]+10);
	vector<int> genoma2(&gen2[0], &gen2[0]+10);
	vector<int> genoma3(&gen3[0], &gen3[0]+10);
	/*cout<<"Creando genoma1"<<endl;
	fill_vector(genoma1);
	cout<<"Creando genoma2"<<endl;
	fill_vector(genoma2);
	cout<<"Creando genoma3"<<endl;
	fill_vector(genoma3);*/
	cout<<"GENOMA1"<<endl;
	print_vector(genoma1);
	cout<<"GENOMA2"<<endl;
	print_vector(genoma2);
	cout<<"GENOMA3"<<endl;
	print_vector(genoma3);
	cout<<"Modificando el genoma1"<<endl;
	GaSwapMutation(genoma1,9);
	print_vector(genoma1);
	cout<<"Modificando el genoma2"<<endl;
	GaInvertMutation(genoma2,9);
	print_vector(genoma2);
	cout<<"Modificando el genoma3"<<endl;
	FlipMutation(genoma3,9);
	print_vector(genoma3);
	}
