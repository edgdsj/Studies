#include <iostream>
#include <memory>
 
struct StructA {
};
 
struct StructB {
    unsigned char myData[10];
};
 
struct StructC : StructB {
    unsigned char myOtherData[2];
};
 
class ClassA {
    bool myBoolean1;
    bool myBoolean2;
};
 
class ClassB {
    public:
        virtual ~ClassB() = default;
};
 
template<class T>
void PrintSizeOf(const T& o)
{
    std::cout << "sizeof " << typeid(o).name() << "\t " << sizeof(o) << std::endl;
}
 
 
int main()
{
    PrintSizeOf(StructA());
    PrintSizeOf(StructB());
    PrintSizeOf(StructC());
    std::cout << std::endl;
 
    PrintSizeOf(ClassA());
    PrintSizeOf(ClassB());
    std::cout << std::endl;
   
    PrintSizeOf(bool());
    PrintSizeOf(short());
    PrintSizeOf(int());
    PrintSizeOf(double());
    std::cout << std::endl;
 
    bool* pbool;
    ClassA* pdouble;
    PrintSizeOf(pbool);
    PrintSizeOf(pdouble);
 
    return EXIT_SUCCESS;
}