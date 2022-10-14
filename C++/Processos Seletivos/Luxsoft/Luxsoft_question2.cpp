#include <iostream>
#include <vector>
 
 
class Base
{
     public:
          virtual void fun() = 0;
 
};
 
class Derived1 : public Base
{
     public:
          virtual void fun() override
          {
               std::cout << "derived1 ";
          }
};
 
class Derived2 : public Base
{
     public:
          virtual void fun() override
          {
               std::cout << "derived2 ";
          }
};
 
class FinalClass : public Derived1, public Derived2
{
};
 
int main()
{
    FinalClass* a = new FinalClass;
    a->fun();
 
    return EXIT_SUCCESS;
}