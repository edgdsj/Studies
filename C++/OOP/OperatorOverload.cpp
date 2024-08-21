#include <iostream>

class MyClass{
    public:
        int value;
        MyClass(int v) : value(v){}

        //Declared like this inside the class you have to use ine opposite way
        std::ostream& operator<<(std::ostream& out){
            out << "inside the class" << value;
            return out;
        }

        //the best way to do is use friend inside the class
        // friend keyword means that the friend object will have access to the private
        // and protected menber of the class if make a global function friend it will have
        //access to all menber of the class
        friend std::ostream& operator<<(std::ostream& out, MyClass& myClass){
            out << "From friend" << myClass.value;
            return out;
        }
};

// in order to stream an object to cout is necessary overload the operator <<
// std::ostream& operator<<(std::ostream& out, MyClass& myClass){
//     out << myClass.value;
//     return out;
// }


int main(){
    MyClass obj(111);
    MyClass obj2(333);
    std::cout << obj << std::endl;
    obj << std::cout << obj2;
    return 0;
}