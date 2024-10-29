#include <iostream>
#include <unordered_map>
#include <string>


int main() {
    std::unordered_map<int, std::string> map;
    
    map.insert(std::make_pair(1, "one"));
    map.insert(std::make_pair(1, "two"));

    //unordered map doesn't replace the first entry.
    for (auto [ key, value ] : map) {
        std::cout << key << " " << value << std::endl;
    }

    return 0;
}