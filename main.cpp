#include<iostream>
#include "add.h"

using namespace std;


int main()
{
  logo();
  int M_M_S,C_C_S,B_S;
  cout<<"Enter the Main Memory Size (in bytes):- ";
  cin>>M_M_S;
  cout<<"Enter the Cache Size (in bytes):- ";
  cin>>C_C_S;
  cout<<"Enter the Block Size (in bytes):- ";
  cin>>B_S;

  Cache a1(M_M_S,C_C_S,B_S); 
  a1.printStats();
  int temp;
  cout<<"Enter the no.of Memory Addresses to check:- ";
  cin>>temp;
  for(int i=0;i<temp;i++)
  {
    cout<<"Enter the Memroy Address (in Decimal):- ";
    cin>>temp; 
    a1.accessMemory(temp);
  }
}
