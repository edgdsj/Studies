#include <iostream>
#include <memory>

class A{
    public:
        int i;
        A(int v):i(v){};
        A(std::shared_ptr<A> pointer){A(pointer->i);};
};

class B{
    public:
        std::shared_ptr<A> p;
        B(int v){ p = std::make_shared<A>(v);};
        A getCopy(){return A(p);};
};

int main()
{
    auto p1 = B(100);
    auto p2 = A(*p1.p);

    p2.i = 200;

    std::cout << "First " << p1.p->i << std::endl << "Second " << p2.i ;
    return 0;
}

