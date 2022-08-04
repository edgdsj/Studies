#include <iostream>
#include <thread>
#include <unistd.h>

void sthread(int number){
    std::cout << "Thread Execution " << number << std::endl;
    usleep(2000000);
}

int main (void){
    std::cout << "Simple thread test" << std::endl; 
    std::cout << "Create a Thread" << std::endl;
    std::thread t;
    usleep(1000000);
    t = std::thread(sthread, 10);
    t.join();
    std::cout << "The End" << std::endl;
    return 0;
}