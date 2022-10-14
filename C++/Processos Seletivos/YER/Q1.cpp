#include <iostream>
#include <tuple>

/*Which od the following are true statements regardung the C++ program bellow*/

std::tuple<int, double> tuppy(int i, double d){
    std::tuple<int, double> localTuple(i, d);
    return localTuple;                          //Line X
}

int main(){
    int a = 1;
    double c = 2.0;

    std::tuple<int, double> myTup = tuppy(a, c);

    std::cout << std::get<1>(myTup) << std::endl;

    int b;
    double d;

    std::tie(b, d) = myTup;                    //Line Y 

    std::cout << b << " " << d << std::endl;
    std::cout << &b << " " << &std::get<0>(myTup) << std::endl;
}

// |T| After execution of the code, variable d will be 2.0
// |F| In order for the code to compile, Line Y should be replaced with: std::tie<int, double>(b, d) = myTup
        //it works with or without it.
// |F| A function cannot return an object of the type std::tuple as is done on Line X
// |F| After execution of the code, variable b will be 3.0.
// |F| After Line Y, variables b and d are references to corresponding elements in the associated tuple.