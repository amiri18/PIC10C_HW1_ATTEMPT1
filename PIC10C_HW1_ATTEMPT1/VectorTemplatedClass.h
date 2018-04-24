#ifndef __VECTOR_CLASS__
#define __VECTOR_CLASS__

#include <iostream>
#include <memory>
// vector class
namespace Pic10c {
    template <typename T>
    class vector{
    private:
        size_t sz;
        size_t cap;
        std::unique_ptr<T> uniquePointer;
        static const int initinal_cap = 10;
    public:
        vector() : sz(0), cap(static_cast<size_t>(initinal_cap)) {
            uniquePointer.reset(new T[initinal_cap]);
        }
        
        vector(const vector& copy) : sz(copy.sz), cap(copy.cap) {
            uniquePointer.reset(new T[cap]);
            for (size_t i = 0; i < sz; ++i){
                uniquePointer[i] = copy.uniquePointer[i];
            }
        }
        
        vector(vector&& move);
        vector& operator=(const vector& copy);
        bool empty() const;
        size_t size() const;
        size_t capacity() const;
        T front() const;
        T back() const;
        T at(size_t index) const;
        T& operator[](size_t index);
        T operator[](size_t index) const;
        void data_dump_to(std::ostream& out) const;
        void data_dump() const;
        void push_back(const T& input);
        void pop_back();
        void deleteAt(size_t index);
    };
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Pic10c::vector<T>& vec);

template <typename T>
void print_vector(const Pic10c::vector<T>& vec);

#endif
