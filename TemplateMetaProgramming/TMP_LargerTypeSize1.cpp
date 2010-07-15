#include<iostream>
#include<typeinfo>

template <typename T1, typename T2>
struct CompTypeSize { enum { value = sizeof(T1) > sizeof(T2), }; };

template <typename T1, typename T2, bool B >
struct LargerType { typedef T1 larger_type; };

template <typename T1, typename T2>
struct LargerType<T1, T2, 0> { typedef T2 larger_type; };

template <typename T1, typename T2>
struct GetLargerType { 
    typedef typename LargerType<T1, T2, CompTypeSize<T1, T2>::value >::larger_type larger_type; 
};


int main() {
    std::cout << "CompTypeSize<short, long>::value = " << CompTypeSize<short, long>::value << std::endl;
    std::cout << "CompTypeSize<long, short>::value = " << CompTypeSize<long, short>::value << std::endl;
    
    GetLargerType<short, long>::larger_type iValue1 = 0;
    GetLargerType<long, short>::larger_type iValue2 = 0;

    std::cout << "typeid(iValue1).name() = " << typeid(iValue1).name() << std::endl;
    std::cout << "typeid(iValue2).name() = " << typeid(iValue2).name() << std::endl;

    return 0;
}

