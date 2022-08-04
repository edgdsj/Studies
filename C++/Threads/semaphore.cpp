#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>
#include <semaphore.h>

#define ALLYGMENT   "/allygmment"
sem_t *semafaro;

void thread1(void){
    sem_wait(semafaro);
    std::cout << "Thread 1 Executing " << std::endl;
    usleep(2000000);
    std::cout << "Thread 1 End " << std::endl;
}
void thread2(void){
    sem_wait(semafaro);
    std::cout << "Thread 2 Executing " << std::endl;
    usleep(2000000);
    std::cout << "Thread 2 End " << std::endl;
    sem_post(semafaro);
}
void thread3(void){
    sem_wait(semafaro);
    std::cout << "Thread 3 Executing " << std::endl;
    usleep(2000000);
    std::cout << "Thread 3 End " << std::endl;
    sem_post(semafaro);
    sem_post(semafaro);
}



int main (void){
    sem_unlink(ALLYGMENT);
    semafaro = sem_open(ALLYGMENT, 1, 0660, 1);
    std::cout << "Simple thread test" << std::endl; 
    std::cout << "Create a Thread" << std::endl;
    std::thread t1;
    std::thread t2;
    std::thread t3;
    t1 = std::thread(thread1);
    t2 = std::thread(thread2);
    t3 = std::thread(thread3);
    
    int i = 10;
    while (i != 0){
        usleep(1000000);
        i--;
    };
    sem_close(semafaro);
    std::cout << "The End" << std::endl;
    return 0;
}