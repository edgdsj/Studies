#include "iostream"
class BasicClass{
    public:
        int basePublicAttribute;
        virtual void basePublicMethod(void){
            std::cout << "basePublicMethod on base" << std::endl;
            // inline methods can't be called here because this function is marked as virtual
            // the execution will choose the right execution during the runtime.
        }
        BasicClass(){
            std::cout << "base constructor" << std::endl;
        }
        ~BasicClass(){
            std::cout << "base destructor" << std::endl;
        }

    private:
        int basePrivateAttribute;
    
    protected:
        int baseProtectAttribute;
};

/*Inheritance:
    We can extend the properties and methods from a class by using inheritance.
    The base class or super class is the class that will be extended
    The derived class or sub class is the class that extends the base class
    
    It can be a public, private and protect inheritance, the default is the private.
    
    During the construction of the derived class, the base class is called first and in the 
    Distruction the base class destructor is called after the derived class
    
    We can instantiate a derived class and asign it to a Base class
    But if the base class destructor is not marked as virtual the derived class destructor will 
    not be called, it can cause a memory leak*/
class DerivedPublicClass : public BasicClass{
    public:
        int  derivedPublicAttribute;
        void derivedPublicMethod(void);
        void basePublicMethod(void){
            std::cout << "basePublicMethod on derived" << std::endl;
        }

        DerivedPublicClass(){
            std::cout << "derived public constructor" << std::endl;
            baseProtectAttribute = 1;   // <-- this attribute is a protect menber
            basePublicAttribute  = 1;   // <-- This attribute is a public menber
            // basePrivateAttribute = 1;   <-- nao tem acesso aqui nessa classe
        }
        ~DerivedPublicClass(){
            std::cout << "derived public destructor" << std::endl;
            baseProtectAttribute = 1;   // <-- this attribute is a protect menber
            basePublicAttribute  = 1;   // <-- This attribute is a public menber
            // basePrivateAttribute = 1;   <-- nao tem acesso aqui nessa classe
        }
    protected:
        //int derivedProtectAttribute;;
        //void derivedProtecttMethod(void);
    private:
        //int derivedPrivateAttribute;;
        //void derivedPrivateMethod(void);
};

class DerivedProtectClass : protected BasicClass{

    DerivedProtectClass(){
        baseProtectAttribute = 1; // <-- this attribute is a protect menber now
        basePublicAttribute  = 1; // <-- This attribute is a protect menber also
        //basePrivateAttribute = 1;  <-- nao tem acesso aqui nessa classe
    }
};

class DerivedPrivateClass : private BasicClass{

    DerivedPrivateClass(){
        baseProtectAttribute = 1;     //<-- this attribute is a private menber now
        basePublicAttribute  = 1;     //<-- This attribute is a private menber also
        ///basePrivateAttribute = 1;  //<-- nao tem acesso aqui nessa classe
    }
};

int main(){
    {
        BasicClass b;
        DerivedPublicClass dp;
        std::cout << "Base Size: " << sizeof(b) << std::endl;
        std::cout << "Derived Size: " << sizeof(dp) << std::endl;
    }
    
    std::cout << "-----------------" << std::endl;
    DerivedPublicClass dp;
    BasicClass *bc = &dp;
    std::cout << "*****************" << std::endl;
    bc->basePublicMethod();             // this line will call the derived method if the functions is marked as vitual
                                        // on Base class otherwise it will call the base method.
    bc->BasicClass::basePublicMethod(); // you can explicity call a function from a base class
    std::cout << "*****************" << std::endl;

    return 0;
}