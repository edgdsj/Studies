/*
    A tuple is an object that can hold a number of elements.
    The elements can be of different data types.
    The elements of tuples are initialized as arguments in order in which they will be accessed.
    tuple<type1, type2, ...>(value1, value2, ...);
*/
/*
    std::get<index>(tupleObj)
        can be used to set the value
    std::make_tuple(args...)
        can be used to create a new tuple
    tup.swap(tup2)
        Can be used to swap the values of the tuples.
    tuple_cat()
        Can be used to create a new tuple concatenating two tuples.
*/
/*
    Constructs a tuple object whose elements are references to the arguments in args, in the same order.
    Normaly used to unpack values from a tuple
    std::tie<type1, type2...>(var1, var2, ...) = tuple;
*/
#include <iostream>
#include <tuple>

using namespace std;

int main(){
    tuple<int, char> myTup( 10, 'u');
    
    tuple<int, char> myTup2;
    myTup2 = make_tuple(13, 'y');

    cout << "First element: " << get<0>(myTup) << endl;
    cout << "Second element: " << get<1>(myTup2) << endl;

    int a = 0;
    char b = 'f';
    double c = 3.5;

    tuple<int, char, double> tup = tie(a,b,c);
    tuple<int, char, double> tup2(3, 'u', 9.7);
    cout << "First  element: " << get<0>(tup) << endl;
    cout << "Second element: " << get<1>(tup) << endl;
    cout << "Third  element: " << get<2>(tup) << endl;

    //It will not refers to the variable used to create the tuple
    cout << "Address: " << &get<0>(tup) << " " << &a<< endl;

    tie(a, b, c) = tup2;
    
    cout << "First  element: " << a << endl;
    cout << "Second element: " << b << endl;
    cout << "Third  element: " << c << endl;
    
    return 0;
};

