#ifndef __VECTOR_CLASS__
#define __VECTOR_CLASS__

#include <iostream>
#include <memory>

namespace Pic10c {
    template <typename T>
    class vector{
    private:
        size_t sz;
        size_t cap;
        std::unique_ptr<T[]> uniquePointer;
        static const int initinal_cap = 10;
    public:
        vector() : sz(0), cap(static_cast<size_t>(initinal_cap)) {
            uniquePointer.reset(new T[initinal_cap]);
            for (size_t i = 0; i < cap; ++i){
                uniquePointer[i] = T();
            }
        }
        
        vector(const vector& copy) : sz(copy.sz), cap(copy.cap) {
            uniquePointer.reset(new T[cap]);
            for (size_t i = 0; i < sz; ++i){
                uniquePointer[i] = copy.uniquePointer[i];
            }
        }
        
        vector(vector&& vec) : sz(vec.sz), cap(vec.cap) {
            uniquePointer(std::move(vec.uniquePointer));
        }
        vector& operator=(vector vec) {
            std::cout << std::endl;
            std::swap(sz, vec.sz);
            std::swap(cap, vec.cap);
            uniquePointer.swap(vec.uniquePointer);
            vec.uniquePointer.reset();
            return *this;
        }
        bool empty() const{
            return (sz == 0);
        }
        size_t size() const {
            return sz;
        }
        size_t capacity() const {
            return cap;
        }
        T front() const {
            return uniquePointer[0];
        }
        T back() const {
            return uniquePointer[sz-1];
        }
        T at(size_t index) const {
            if (index < sz) {
                return uniquePointer[index];
            }
            return uniquePointer[0];
        }
        T& operator[](size_t index) {
            return uniquePointer[index];
        }
        T operator[](size_t index) const {
            return uniquePointer[index];
        }
        void data_dump_to(std::ostream& out) const{
            out << "Vector dump: ";
            for (size_t i = 0; i < cap; ++i){
                out << uniquePointer[i] << ' ';
            }
            out << '\n';
        }
        void dump_data() const {
            data_dump_to(std::cout);
        }
        void push_back(const T& input) {
            if (sz == cap){
                std::unique_ptr<T[]> tempPointer(new T[cap*2]);
                for (size_t i = 0; i < (cap*2); ++i){
                    tempPointer[i] = T();
                }
                for (size_t i = 0; i < sz; ++i){
                    tempPointer[i] = uniquePointer[i];
                }
                tempPointer.swap(uniquePointer);
                tempPointer.reset();
                cap = cap*2;
                ++sz;
                uniquePointer[sz-1] = input;
            }
            else {
                ++sz;
                uniquePointer[sz-1] = input;
            }
        }
        void pop_back() {
            if (sz != 0){
                uniquePointer[sz-1] = T();
                --sz;
            }
        }
        //void deleteAt(size_t index);
    };
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Pic10c::vector<T>& vec){
    for (size_t i = 0; i < vec.size(); ++i){
        out << vec[i] << ' ';
    }
    return out;
}

template <typename T>
void print_vector(const Pic10c::vector<T>& vec){
    if (vec.empty()){
        std::cout << "Vector is empty.\n";
    }
    else {
        std::cout << "Vector (contents): " << vec << std::endl;
    }
}

#endif
