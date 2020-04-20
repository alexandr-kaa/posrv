#include <pthread.h>
#include <sys/neutrino.h>
#include <unistd.h>
using namespace std;
unsigned int thread_count=0;
void * thread_func (void * p_pause)
{
 int pause=* (unsigned int *) p_pause;
unsigned int thr = thread_count;
cout<<”Это поток ”<<thr<<endl;
sleep (pause);
cout<<”Поток” <<thr<< “ завершен”<<endl;
}
int main (int argc, char *[] argv)
{
 pthread_t     thr1, thr2;
unsigned int pause =0;
thread_count=1;
cout<<”Начинается основной поток main -”<<thread_count<<endl;
cout<<”Введите паузу для дочернего потока ”<<endl;
cin>>pause;
thread_count++;
cout<<endl<<”Создается первый дочерний поток”<<endl;
pthread_create(&thr1,NULL, thread_func, &pause);
pause+=10;
thread_count++;
cout<<endl<<” Создается второй дочерний поток”<<endl;
pthread_create(&thr2,NULL, thread_func, &pause);
cout<<”Значениe thr1”<<thr1<<” Значение thr2 “<<thr2<<endl;
pthread_join(thr2,NULL);
cout<<”Поток main завершен”<<endl;
return 0;
}