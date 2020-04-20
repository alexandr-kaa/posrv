#include <unistd.h>
#include <iostream>
using namespace std;
void main (void)
{
  cout<<”Начало программы”<<endl;
 if(fork())
 cout << “Это процесс-родитель”<<endl;
else
 cout<<”Это процесс-потомок”<<endl;
sleep(10);
}