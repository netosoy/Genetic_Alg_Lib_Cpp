#include <iostream>
using namespace std;

int main(void){
  int n=10, *pnt_n;
  pnt_n=&n;
  cout<<"el valor de n es: "<<n<<endl;
  cout<<"\nla direccion del la variable n es: "<<&n<<endl;
  cout<<"\nel valor del puntero pnt_n es: "<<pnt_n<<endl;
  cout<<"\nel contenido al que apunta el puntero ptn_n es :"<<*pnt_n<<endl;
  //Arreglo
  int A[5]={1,3,5,7,9}, *pnt_A;
  pnt_A = A;
  cout<<"\n\nel valor del del arreglo A es: "<<A<<endl;
  cout<<"\nla direccion de memoria del entero A[0] es: "<<&A[0]<<endl;
  cout<<"\nla direccion de memoria del entero A[3] es: "<<&A[3]<<endl;
  cout<<"\nel valor del puntero pnt_A es: "<<pnt_A<<endl;
  cout<<"\nel contenido al que apunta el puntero pnt_A es: "<<*(pnt_A)<<endl;
  cout<<"\nsumar 3 al contenido apuntado por el punter pnt_A es: "<<*pnt_A+3<<endl;
  cout<<"\nel contenido apuntado por el puntero pnt_A+3 es: "<<*(pnt_A+3)<<endl;
}
