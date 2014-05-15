#include<iostream>
using namespace std;

struct bola{
  int mass;
  int diameter;
  char color[];
};

void init_bola(bola *ptr, int mass, int dia){
  //ptr->mass=mass;   //estas dos líneas son equivalentes
  (*ptr).mass=mass;
  ptr->diameter=dia;
  ptr->color="Rojo";
};

void get_mass(bola *ptr){
  cout<<"la masa de la bola es :"<<ptr->mass<<endl;
};

void get_color(bola *ptr){
  cout<<"el color de la bola es :";
    for(int i=0; i<5; i++)
      cout<<ptr->color[i];
  cout<<endl;
};

int main(void){
  bola mibola;
  bola *ptr_bola;
  ptr_bola=&mibola;
  init_bola(ptr_bola,5,20);
  get_mass(ptr_bola);
  get_color(ptr_bola);
  return 0;
}
