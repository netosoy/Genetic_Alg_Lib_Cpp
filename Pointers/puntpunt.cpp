#include<iostream>
using namespace std;

int main(void){
  int num=14;
  int *ptr_num;
  int **ptr_ptr;
  ptr_num=&num;
  ptr_ptr=&ptr_num;

  cout<<"Funny Printings"<<endl;
  cout<<"\nImprimiendo ptr_num se tiene: "<<ptr_num<<endl;
  cout<<"\nImprimiendo ptr_ptr se tiene: "<<ptr_ptr<<endl;
  cout<<"\nImprimiendo *ptr_num se tiene: "<<*ptr_num<<endl;
  cout<<"\nImprimiendo &ptr_num se tiene: "<<&ptr_num<<endl;
  cout<<"\nImprimiendo *ptr_ptr se tiene: "<<*ptr_ptr<<endl;
  cout<<"\nImprimiendo **ptr_ptr se tiene: "<<**ptr_ptr<<endl;
  return 0;
}
