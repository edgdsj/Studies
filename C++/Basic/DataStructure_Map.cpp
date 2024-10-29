#include <iostream>
#include <map>
#include <string>


int main() {
    std::map<int, std::string> map;
    map[1] = "one";
    map[2] = "two";
    map[3] = "three";

    //this usage will insert a new value on the map
    std::string new_value = map[4];

    for (auto [ key, value ] : map) {
        std::cout << key << " " << value << std::endl;
    }

    return 0;
}