#include<stdio.h>

int multiply(int &a, int &b){
    return a*b;
}

int main(){
    int x = 2;
    int y = 3;
    int m = multiply(x,y);
    return 0;
}