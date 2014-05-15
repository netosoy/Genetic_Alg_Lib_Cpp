#include<iostream>
using namespace std;

int main(void){
  int arreglo[]={1,3,5,7,9,11,13};
  int *puntero;
  puntero=arreglo;
  cout<<"El contenido del arreglo es: "<<endl;
  for(int i=0; i<7; i++){
      cout<<i<<".) "<<arreglo[i]<<endl;
    }
  cout<<"\n\n Las direcciones de memoria del puntero del arreglo son : "<<endl;
  for(int i=0; i<7; i++){
    cout<<i<<".) "<<puntero+i<<endl;
    }
  cout<<"\n\n Los contenidos de las direcciones apuntadas son: "<<endl;
  for(int i=0; i<7; i++){
    cout<<i<<".) "<<puntero[i]<<endl;
    }
  return 0;
}
