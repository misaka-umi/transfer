
include <unistd.h>
#include <stdio.h>#include <stdlib.h>#include <semaphore.h>#include <sys /mman.h>int* count=;
sem_t*mutex1=NULL;sem_t *mutex2=NULL;int main( )
{
int i;
mutexl=(sem_t* )mmap(NULL,sizeof(sem_t),PROT_READ|PROT_WRITE,MAP_ANON|MAP_SHARED,-1,0 ) ;
mutex2=(sem_t* )mmap(NULL,sizeof(sem_t),PROT_READ|PROT_WRITE,MAP_ANONIMAP_SHARED,-1,0);
count=(int* )mmap(NULL,sizeof(int), PROT_READ|PROT_WRITE,MAP_ANON|NAP_SHARED,-1,0)
sem_init(mutex1,1,1);
sem_init(mutex2,1,0);*count=0 ;
if(fork()==o)i
for(i=0;i<10; i++){
printf ( "add continue!\n" );sem_wait(mutex1) ;
*count+=5;
sem_post(mutex2);}
printf ( "add finish!n" ) ;exit(0);
}
for(i=0;i<10 ; i++)
printf ( "printf_continue! \n" );sem_wait(mutex2);
printf ( "count:%din" ,*count);sem_post(mutex1);
sem_destroy ( mutex1);sem_destroy ( mutex2);
munmap(mutex1,sizeof(sem_t) ) ;munmap(mutex2,sizeof(sem_t) );munmap( count,sizeof(int) );printf( "finish all!\n" );return 0;
