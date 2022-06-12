
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
int count=5;
sem_t ml;
sem_t m2;
pthread_mutex_t mutex;
void *thread1(void *arg){
int i=0;
for(i=0 ; i<10;i++){
sem_wait(&m1);
count+=5;
sem_post(&m2);}
}
void *thread2 (void *arg){
int i=0;
for( i=0 ; i<10;i++){
sem_wait(&m2);
printf( "count=%d\n", count);
sem_post(&m1);
}
}
int main()
{
pthread_t thr1;
pthread_t thr2 ;
int ret;
ret=sem_init(&m1,0,1);
if ( ret!=0)
{
printf ( "sem_init error ! " );
exit(0) ;
}
ret=sem_init(&m2,0,0 ) ;
if(ret!=0)
{
printf ( "sem_init error! " );
exit(0 ) ;
}
pthread_create(&thr1,NULL,thread1,NULL);
pthread_create(&thr2,NULL,thread2,NULL);
pthread_join(thr1,NULL);
pthread_join(thr2,NULL);
exit(0);
}                  
