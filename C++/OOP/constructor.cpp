#include <iostream>

class A{
    public:
        int value;
        // This is the default constructor 
        A(){
            std::cout << "Default Constructor" << std::endl;
        }
        // Constructor with input option
        A(int i){
            std::cout << "Constructor with value" << std::endl;
        }
};

//Menber Initialize list allow you to call a member constructor without call the default constructor
class B{
    public:
        A obj;
        int bvalue;

        B() : obj(1){}
        B(int v){obj = A(2); bvalue = v;}

};

int main(){
    B obj1;
    std::cout << "without init list" << std::endl;
    B obj2(10);

    return 0;
}