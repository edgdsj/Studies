#include <iostream>
#include <thread>

void sthread(int number){
    std::cout << "Thread Execution" << number << std::endl;
}

int main (void){
    std::cout << "Simple thread test" << std::endl; 
    std::cout << "Create a Thread" << std::endl;
    for(int i = 0; i <10 ;i++){
        std::thread th_obj(sthread, i);
        th_obj.join();
    }
    //Modfied
    //mofied2
    return 0;
}