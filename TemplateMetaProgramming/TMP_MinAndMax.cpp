#include<iostream>

//--simple if-else conditional with a return of a type
template <bool cond, typename T1, typename T2> struct IfTypes { typedef T1 return_type; };
template <typename T1, typename T2> struct IfTypes<0, T1, T2> { typedef T2 return_type; };

// -- simple if-else conditional with a return of a number
template <bool cond, int V1, int V2> struct IfInts { enum { value = V1, }; };
template <int V1, int V2> struct IfInts<0, V1, V2> { enum { value = V2, }; };


// -- choose either the max or min value using template conditionals.
#define MIN 0
#define MAX 1
template <int MIN_OR_MAX, int V1, int V2> struct MinMax { 
    enum { 
    _result = V1 > V2,
    value = IfInts< _result, V1, V2>::value 
    }; 
};

template <int V1, int V2> struct MinMax<0, V1, V2> { 
    enum { 
    _result = V1 < V2,
    value = IfInts< _result, V1, V2>::value 
    }; 
};


// -- choose either the max or min valye using an expression
//       Note that you can't do this so easily with types.
template <int MIN_OR_MAX, int V1, int V2> struct MinMax2 { 
    enum { 
    value = MIN_OR_MAX ? 
        ((V1 > V2) ? V1 : V2) 
        : ((V1 < V2) ? V1 : V2)
    }; 
};

int main() {
    //test choosing types
    IfTypes<0, int, long>::return_type v1;
    IfTypes<1, int, long>::return_type v2;
    
    std::cout << typeid(v1).name() << std::endl;
    std::cout << typeid(v2).name() << std::endl;

    //test choosing values
    v1 = IfInts<0, 100, 200>::value;
    v2 = IfInts<1, 100, 200>::value
    std::cout << v1 << std::endl;
    std::cout << v2 << std::endl;

    //test choosing values with template expressions
    std::cout << "min = " << MinMax<MIN, 100, 200>::value << std::endl;
    std::cout << "max = " << MinMax<MAX, 100, 200>::value << std::endl;
   
    //test choosing values with a conditional
    std::cout << "min = " << MinMax2<MIN, 100, 200>::value << std::endl;
    std::cout << "max = " << MinMax2<MAX, 100, 200>::value << std::endl;

    return 0;
}