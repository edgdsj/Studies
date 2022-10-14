#include <iostream>
 
class Base
{
     public:
          void fun()
          {
               std::cout << "Base" << std::endl;
          }
 
};
 
class Derived : public Base
{
     public:
          void fun()
          {
               std::cout << "Derived " << std::endl;
          }
};
 
int main() {
    Base* a = new Derived;
    a->fun();
 
    return EXIT_SUCCESS;
}