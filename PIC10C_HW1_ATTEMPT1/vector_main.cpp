#include <iostream>
#include <string>
#include "VectorTemplatedClass.h"

/* Test Run:
Program can also work for other types such as: std::string, char, int, double, etc. */

int main() {
    using Pic10c::vector;
    using std::cout;
    
    cout << "Create & display empty vector (v1)\n";
    vector<double> v1;
    print_vector(v1);
    v1.dump_data();
    
    int size = 15;
    cout << "\nPopulate & display vector with " << size << " entries (v1)\n";
    for ( int i = 1 ; i <= size ; ++i )
        v1.push_back(i);
    print_vector(v1);
    
    cout << "\nCopy non-empty vector, pop back last entry & display (v2)\n";
    vector<double> v2(v1);
    v2.pop_back();
    print_vector(v2);
    
    cout << "\nReassign vector (v1 = v2) & display\n";
    v1 = v2;
    print_vector(v1);
    
    cout << "\nDump contents of vectors (v1,v2)\n";
    v1.dump_data();
    v2.dump_data();

    return 0;
}
