#include "iostream"
#include "string"
#include "cmath"

int main(){
    std::string line;
    long V1, V2;
    while (std::getline(std::cin, line))
    {
        sscanf(line.c_str(),"%ld %ld",&V1,&V2);
        std::cout << std::abs(V1 -V2) << std::endl;
    }   
    
    return 0;
}