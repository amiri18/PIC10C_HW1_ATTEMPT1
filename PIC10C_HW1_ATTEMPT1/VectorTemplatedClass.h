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
            // initialize unique_ptr to array and default initalize elements
            uniquePointer.reset(new T[initinal_cap]);
            for (size_t i = 0; i < cap; ++i){
                uniquePointer[i] = T();
            }
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
            // reset the pointer to have a new capacity and copy over the elements
            uniquePointer.reset(new T[cap]);
            for (size_t i = 0; i < cap; ++i){
                uniquePointer[i] = T();
            }
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
            // swap the vector's size, capacity, and pointers
            std::swap(sz, vec.sz);
            std::swap(cap, vec.cap);
            uniquePointer.swap(vec.uniquePointer);
            vec.uniquePointer.reset();
            return *this;
        }
        
        /**
         this function checks to see if the vector is empty
         @return true if empty, false if not
         */
        bool empty() const{
            return (sz == 0);
        }
        
        /**
         this function returns the size of the vector
         @return size
         */
        size_t size() const {
            return sz;
        }
        
        /**
         this function returns the capacity of the vector
         @return capacity
         */
        size_t capacity() const {
            return cap;
        }
        
        /**
         this function returns the first element of the vector
         @return vector[0]
         */
        T front() const {
            return uniquePointer[0];
        }
        
        /**
         this function returns the last element of the vector
         @return vector[size - 1]
         */
        T back() const {
            return uniquePointer[sz-1];
        }
        
        /**
         this function returns a copy of the element at that index
         @param index , the index of the element
         @return copy of the element
         */
        T at(size_t index) const {
            if (index < sz) { // if index is valid
                return uniquePointer[index];
            }
            // if not valid, return the first element
            return uniquePointer[0];
        }
        
        /**
         this function overloads the operator [] so that the element in the vector can be accessed
         @param index , the index of the element
         @return a reference of the element
         */
        T& operator[](size_t index) {
            return uniquePointer[index];
        }
        
        /**
         this function overloads the operator [] so that the element in the vector can be asscessed
         @param index , the index of the element
         @return a copy of the element
         */
        T operator[](size_t index) const {
            return uniquePointer[index];
        }
        
        /**
         this function outputs the all contents of the vector
         @param out , outstream
         */
        void data_dump_to(std::ostream& out) const{
            out << "Vector dump: ";
            for (size_t i = 0; i < cap; ++i){
                out << uniquePointer[i] << ' ';
            }
            out << '\n';
        }
        
        /**
         this function is a helper function for data_dump_to()
         */
        void dump_data() const {
            data_dump_to(std::cout);
        }
        
        /**
         this function adds an element to the end of the vector
         @param input , the element to be added
         */
        void push_back(const T& input) {
            if (sz == cap){ // if sz = cap, then reserve more space
                std::unique_ptr<T[]> tempPointer(new T[cap*2]);
                for (size_t i = 0; i < (cap*2); ++i){
                    tempPointer[i] = T(); // default initialize
                }
                for (size_t i = 0; i < sz; ++i){ // copy over elements
                    tempPointer[i] = uniquePointer[i];
                } // swap the pointers and leave the temp ptr in a state to be destroyed
                tempPointer.swap(uniquePointer);
                tempPointer.reset();
                cap = cap*2;
                ++sz; // increase the size add the element to the vector
                uniquePointer[sz-1] = input;
            }
            else { // if size is less than the capacity
                ++sz; // increase size and add the element to the vector
                uniquePointer[sz-1] = input;
            }
        }
        
        /**
         this fucntion removes the element at the end
         */
        void pop_back() {
            if (sz != 0){ // if the size is not equal to 0
                uniquePointer[sz-1] = T();
                --sz;
            }
        }
    };
}

/**
 this function overloads the operator << to be able to print the vector contents
 @tparam T , data type the vector stores
 @param out , output stream
 @param vec , the vector to be displayed to the console
 */
template <typename T>
std::ostream& operator<<(std::ostream& out, const Pic10c::vector<T>& vec){
    // overload allows vec elements to be cout-ed
    for (size_t i = 0; i < vec.size(); ++i){
        out << vec[i] << ' ';
    }
    return out;
}

/**
 this function prints the vector to the console
 @tparam T , data type the vector stores
 @param vec , the vector to be printed
 */
template <typename T>
void print_vector(const Pic10c::vector<T>& vec){
    if (vec.empty()){ // if empty, say so
        std::cout << "Vector is empty.\n";
    }
    else { // if not empty, display the vector
        std::cout << "Vector (contents): " << vec << std::endl;
    }
}

#endif
