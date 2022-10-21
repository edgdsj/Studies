class BasicClass{
    //Access Modfier: public means that every code that has a instance of one object of this class will be able to access 
    //any attribute or method declared inside this modifier. 
    public:
        //Atributes are variables that will describe and hold the state of this object
        int basePublicAttribute;;
        //Methods are functions reletaded to the object, those function can modify the state of the object.
        //Those functions are not stored with the object. it only point to those functions.
        void basePublicMethod(void);
        //Constructors are especial methods that are called to initialize a object, it must be declared without a retun type.
        BasicClass();
        //Destructors are especial methods called when the object is out of scope or whne use the method Delete()
        ~BasicClass();
    
    //Access Modfier: public means that every code that has a instance of one object of this class will not be able to access 
    //any attribute or method declared inside this modifier.
    private:
        int basePrivateAttribute;
    
    //Access Modfier: protect means that every code that has a instance of one object of this class will not be able to access 
    //any attribute or method declared inside this modifier. but derived classes will be access to public and protected menbers.
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
        int derivedPublicAttribute;;
        void derivedPublicMethod(void);

        DerivedPublicClass(){
            baseProtectAttribute = 1;   // <-- this attribute is a protect menber
            basePublicAttribute  = 1;   // <-- This attribute is a public menber
            // basePrivateAttribute = 1;   <-- nao tem acesso aqui nessa classe
        }
    protected:
        int basePublicAttribute;;
        void baseProtectMethod(void);
    private:
        int basePublicAttribute;;
        void baseProtectMethod(void);
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