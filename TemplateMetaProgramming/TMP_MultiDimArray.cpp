#include <iostream>

//--recursive template to calculate a power
template<int X, int Y> struct Power { enum { value = X * Power<X, Y - 1>::value, }; };
template<int X> struct Power<X, 0> { enum { value = 1, }; };

//Utility template to add an extra dimention to a type
template<typename T, int SIZE> struct AddDimention {
    typedef T value_type[SIZE];
};

// -- recursive template to create a multi-dimentional array type.
template <typename T, int SIZE, int DIM> struct MultiDimArray {
    typedef typename AddDimention< typename MultiDimArray<T, SIZE, DIM-1>::value_type , SIZE>::value_type value_type;
    typedef value_type* value_ptr;
};

template <typename T, int SIZE> struct MultiDimArray<T, SIZE, 1> {
    typedef typename AddDimention< T , SIZE>::value_type value_type;
    typedef value_type* value_ptr;
};

int main() {
    MultiDimArray<int, 50, 3>::value_type myInt3D;
    MultiDimArray<int, 30, 3>::value_ptr myInt3Dptr;
    
    std::cout << (sizeof(myInt3D)/sizeof(int)) 
              << " == " 
              << Power<50, 3>::value
              << std::endl;
    
     std::cout << (sizeof(*myInt3Dptr)/sizeof(int)) 
              << " == " 
              << Power<30, 3>::value
              << std::endl;   
    
    //freeMDA(myInt3Dptr);

    return 0;
}