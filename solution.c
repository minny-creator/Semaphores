#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem1,sem2;
void* A(void* arg)
{
sem_wait(&sem1);
sem_post(&sem1);
sem_post(&sem2);
 // V operation (signal / unlock)
}

void* B(void* arg){
sem_post(&sem1);
sem_wait(&sem2);
}

int main()
{
    pthread_t t1, t2,t3,t4;
    int id1 = 1, id2 = 2,id3=3,id4=4;

    // Initialize semaphore
    // 0 → shared between threads
    // 1 → initial value
    sem_init(&sem1, 0, 0);
sem_init(&sem2,0,0);
    pthread_create(&t1, NULL, A, &id1);
    pthread_create(&t2, NULL, A, &id2);
pthread_create(&t3,NULL,A,&id3);
pthread_create(&t4,NULL,B,&id4);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
pthread_join(t3,NULL);
pthread_join(t4,NULL);
    // Destroy semaphore
    sem_destroy(&sem1);
sem_destroy(&sem2);
    return 0;
}
