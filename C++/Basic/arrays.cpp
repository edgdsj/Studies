#include <iostream>

using namespace std;

int main(){
    char arr[] = "Edmilson Junior";
    cout << &arr << endl;       //Print address of the array
    cout << arr << endl;        //Print all array
    cout << arr + 5 << endl;    //Print all after the 5th item
    int intarr[] = {5,6,7,8,9,0};
    cout << &intarr << endl;                //Print address of the array
    cout << intarr << endl;                 //Print address of the array
    cout << intarr + 5 << endl;             //Print address of the 6th element of this array
    cout << *intarr << endl;                //you have to derefer to print the element
    cout << *intarr + 5 << endl;            //sum some value to the first element
    cout << *(intarr + 4) << endl;          //print the 4th element of the array
}