#include <iostream>

template <int N>
struct Power {
    template <typename NUMERIC_TYPE> 
    static inline NUMERIC_TYPE of(const NUMERIC_TYPE& x) { 
        return x * Power<N-1>::of(x); 
    }
};

template <>
struct Power<0> {
    template <typename NUMERIC_TYPE> 
    static inline NUMERIC_TYPE of(const NUMERIC_TYPE& x) { 
        return 1; 
    }
};


int main() {
    std::cout << "Power<5>::of(3) = " << Power<5>::of(3) << std::endl;
    std::cout << "Power<5>::of(3.14) = " << Power<5>::of(3.14) << std::endl;
    std::cout << "Power<5>::of(3) = " << Power<5>::of(3) << std::endl;
    std::cout << "Power<10>::of(0.1) = " << Power<10>::of(0.1) << std::endl;
    std::cout << "Power<2>::of('A') = " << Power<2>::of('a') << std::endl;

    return 0;
}