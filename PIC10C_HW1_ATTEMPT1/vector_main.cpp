#include <iostream>
#include <string>
#include "VectorTemplatedClass.h"

int main() {
    Pic10c::vector<int> v;
    Pic10c::vector<int> u;
    v.push_back(3);
    v.push_back(4);
    for (size_t i = 0; i < 2; ++i){
        std::cout << v.at(i) << " ";
    }
    std::cout << std::endl;
    u.push_back(2);
    for (size_t i = 0; i < 1; ++i){
        std::cout << u.at(i) << " ";
    }
    std::cout << std::endl;
    u = v;
    for (size_t i = 0; i < 2; ++i){
        std::cout << u.at(i) <<  " ";
    }
    return 0;
}
