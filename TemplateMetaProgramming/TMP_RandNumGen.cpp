#include <iostream>

template<int ValueN, unsigned int Seed> 
struct RandomValue { 
    enum {_value = 2612001773U * RandomValue<ValueN-1, Seed>::_value + 65535, };
    static const unsigned int value = (static_cast<unsigned int>(_value) >> 16) + (static_cast<unsigned int>(_value) << 16); 
};

template<unsigned int Seed> 
struct RandomValue<0, Seed> { 
    enum {_value = 2612001773U * Seed + 65535, };
    static const unsigned int value = (static_cast<unsigned int>(_value) >> 16) + (static_cast<unsigned int>(_value) << 16);    
};

#if defined(__COUNTER__) 
    #define RANDOM_MULT() __COUNTER__
#else
    #define RANDOM_MULT() 63
#endif


#define RANDOM_VALUE(N) (RandomValue<__LINE__ % 10, __LINE__ * RANDOM_MULT()>::value % N)

template <int N>
inline void Gen() {
    Gen<N-1>();
    std::cout << RandomValue<N, 1>::value << std::endl; 
}

template <>
inline void Gen<0>() {
    std::cout << RandomValue<0, 1>::value << std::endl; 
}

int main() {

    Gen<100>();

    //std::cout << RandomValue<0, 1>::value << std::endl;
    //std::cout << RandomValue<1, 1>::value << std::endl;
    //std::cout << RandomValue<2, 1>::value << std::endl;
    //std::cout << RandomValue<3, 1>::value << std::endl;
    //std::cout << RandomValue<4, 1>::value << std::endl;
    //std::cout << RandomValue<5, 1>::value << std::endl;
    //std::cout << RandomValue<6, 1>::value << std::endl;
    //std::cout << RandomValue<7, 1>::value << std::endl;
    //std::cout << RandomValue<8, 1>::value << std::endl;
    //std::cout << RandomValue<9, 1>::value << std::endl;
    //std::cout << RandomValue<10, 1>::value << std::endl;
    //std::cout << RandomValue<200, 1>::value << std::endl;


//////    std::cout << RANDOM_VALUE(100) << std::endl;
    //std::cout << RANDOM_VALUE(100) << std::endl;
    //std::cout << RANDOM_VALUE(100) << std::endl;
    //std::cout << RANDOM_VALUE(100) << std::endl;
    //std::cout << RANDOM_VALUE(100) << std::endl;
    //std::cout << RANDOM_VALUE(100) << std::endl;


//////    std::cout << std::endl;
    //for (int i = 0; i < 100; ++i) {
    //    std::cout << RANDOM_VALUE(100) << " ";
    //    if(i%10 ==9) { std::cout << std::endl; }
    //}
    
//    std::cout << RANDOM_MULT() << std::endl;
//    std::cout << RANDOM_MULT() << std::endl;
//    std::cout << RANDOM_MULT() << std::endl;
//    std::cout << RANDOM_MULT() << std::endl;
    return 0;
}