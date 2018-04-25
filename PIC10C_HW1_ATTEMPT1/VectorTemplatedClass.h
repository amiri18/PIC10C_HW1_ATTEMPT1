#ifndef __VECTOR_CLASS__
#define __VECTOR_CLASS__

#include <iostream>
#include <memory>

namespace Pic10c {
    
    /**
     The vector class stores objects of any type
     @tparam T , the data type the vector stores
     */
    template <typename T>
    class vector{
    
    private:
        size_t sz; // size of the vector
        
        size_t cap; // capacity of the vector
        
        std::unique_ptr<T[]> uniquePointer; // unique_ptr to an array that stores type T
        
        static const int initinal_cap = 10; // initial capacity set to 10
        
    public:
        /**
         vector constructor:
         creates a vector having capacity of 10 with default inititalized elements
         */
        vector() : sz(0), cap(static_cast<size_t>(initinal_cap)) {
            uniquePointer.reset(new T[initinal_cap]);
        }
        
        /**
         default destructor
         */
        ~vector() {}
        
        /**
         copy constructor:
         @param copy , the vector to be copied
         */
        vector(const vector& copy) : sz(copy.sz), cap(copy.cap) {
            uniquePointer.reset(new T[cap]);
            for (size_t i = 0; i < sz; ++i){
                uniquePointer[i] = copy.uniquePointer[i];
            }
        }
        
        /**
         move constructor
         @param vec , vector to be moved
         */
        vector(vector&& vec) : sz(vec.sz), cap(vec.cap) {
            uniquePointer(std::move(vec.uniquePointer));
        }
        
        /**
         copy and move assignment operator
         @prama vec , the vector to be copied/moved
         @return the copied/moved vector
         */
        vector& operator=(vector vec) {
            std::swap(sz, vec.sz);
            std::swap(cap, vec.cap);
            uniquePointer.swap(vec.uniquePointer);
            vec.uniquePointer.reset();
            return *this;
        }
        bool empty() const;
        size_t size() const;
        size_t capacity() const;
        T front() const;
        T back() const;
        T at(size_t index) const {
            return uniquePointer[index];
        }
        T& operator[](size_t index);
        T operator[](size_t index) const;
        void data_dump_to(std::ostream& out) const;
        void dump_data() const;
        void push_back(const T& input){
            
        }
        void pop_back();
        //void deleteAt(size_t index);
    };
}

/**
 this function overloads the operator << to be able to print the vector contents
 @tparam T , data type the vector stores
 @param out , output stream
 @param vec , the vector to be displayed to the console
 */
template <typename T>
std::ostream& operator<<(std::ostream& out, const Pic10c::vector<T>& vec);

/**
 this function prints the vector to the console
 @tparam T , data type the vector stores
 @param vec , the vector to be printed
 */
template <typename T>
void print_vector(const Pic10c::vector<T>& vec);

#endif
