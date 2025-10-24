#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::vector<int> vec{2,2,3,4,5,6,7};
    for(int v : vec){
        
        auto new_end = std::remove_if(vec.begin(), vec.end(),[v](int n){ 
            
            return n==v;
        });
        std::cout << "new vec "; 
        for(int v : vec){
            std::cout <<  v << ", ";
        }
        std::cout << std::endl;
        vec.erase(new_end, vec.end());
                std::cout << "after erase vec "; 
        for(int v : vec){
            std::cout <<  v << ", ";
        }
        std::cout << std::endl;
    }


    std::cout << "Final vec"; 
        for(int v : vec){
            std::cout <<  v << ", ";
        }
        std::cout << std::endl;

    return 0;
}