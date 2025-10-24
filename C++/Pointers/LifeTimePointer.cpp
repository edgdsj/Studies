#include <iostream>
#include <memory>
#include <vector>

class MPointer{
    public:
        int value = 0;
};

using ListOfPointer = std::vector<MPointer*>;

void usepointer(ListOfPointer pointers){
    for(auto p : pointers){
        p->value = 10;
        std::cout << p << " " << p->value << std::endl;
    }
}

int main(){

    std::unique_ptr<MPointer> p1 = std::make_unique<MPointer>();
    p1->value = 2;
    std::cout << p1.get() << " " << p1->value << std::endl;
    ListOfPointer list {p1.get()};
    usepointer(std::move(list));
    std::cout << p1.get() << " " << p1->value << std::endl;

    return 0;
}