/*Polymorphism
    Multiple form to the same class
    Overloading: The hability to write two function with the same name but with diferent parameters
    Overriding: The hability to add new functionality or change functionality of a method from
    tha base class in the derived class, the same method signature with diferent functionality*/
/*
        We can instantiate a derived class and asign it to a Base class
    But if the base class destructor is not marked as virtual the derived class destructor will 
    not be called, it can cause a memory leak
*/
class BaseClass{
    public:
        void method1(void);
      //int  method1(void); you cannot overload a method with same input and differet return type
        int  method1(char c); // but you can overload a method with different input and differet return type
        void method1(int i);
};