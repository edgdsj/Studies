#include <iostream>
#include <memory>
 
 
struct Class1
{
};
 
void DoSomethingWithShared(std::shared_ptr<Class1> sp)
{
    static std::shared_ptr<Class1> lp = sp;
    std::cout << "P3, use count: " << sp.use_count() << std::endl;
}
 
 
int main()
{
    std::shared_ptr<Class1> sp;
    {
        std::cout << "P1, use count: " << sp.use_count() << std::endl;
       
        sp = std::make_shared<Class1>();
        std::cout << "P2, use count: " << sp.use_count() << std::endl;
       
        DoSomethingWithShared(sp);
        std::cout << "P4, use count: " << sp.use_count() << std::endl;
    }
    sp.reset();
    std::cout << "P5, use count: " << sp.use_count() << std::endl;
 
    return EXIT_SUCCESS;
}