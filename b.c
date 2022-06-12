#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
#include <semaphore.h>
#define N 128
int data[N];
int datap=0 ;
sem_t rmutex,wmutex;
int readCnt=0;
//读者
void *reader(void* id) {
sem_wait(&rmutex);
if(readCnt==0)
sem_wait(&wmutex);
++readCnt;
printf("======%S======\n",(char*)id);
int i;
for(i=o; i<datap; ++i)
printf("%c",data[i]);
puts("");
sem_post(&rmutex) ;
//读
sem_wait(&rmutex);
--readCnt;
if(readCnt==0)
sem_post(&wmutex);
sem_post(&rmutex );
return NULL;
}

// 写者
void *writer(void *id) {
sem_wait(&wmutex);
// 写
if(datap==N)
  datap=0;
printf( "=====%s======n",(char*)id);
for(;datap<N;++datap)
data[datap++]=rand()%26+'a';
sem_post(&wmutex);
return NULL;
}
int main()
{
sem_init(&rmutex,0,1);
sem_init(&wmutex,0,1);
// 一个写者，3个读者
pthread_t w1,r1,r2,r3;
while(1){
if(pthread_create(&w1,NULL,writer,(void*) "writer"))
perror("pthread_create");
if(pthread_create(&r1,NULL,reader,(void*) "reader1"))
perror("pthread_create");
if(pthread_create(&r2,NULL,reader,(void*) "reader2"))
perror("pthread_create");
if(pthread_create(&r3,NULL,reader,(void*) "reader3" ))
perror("pthread_create");
if(pthread_join(r1,NULL))
perror("pthread_join");
if(pthread_join(r2,NULL))
perror("pthread_join");
if(pthread_join(r3, NULL))
perror("pthread_join");
if(pthread_join(w1,NULL))
perror("pthread_join");
}
return 0;
}
