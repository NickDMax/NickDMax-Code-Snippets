#include <iostream>

//use -DRAND_TEMPLATE_SEED=value to set an entropy source or have a progam generate a .h file that will define RAND_TEMP_SEED
#if !defined(RAND_TEMPLATE_SEED)
# define RAND_TEMPLATE_SEED __LINE__ 
#endif

struct END { };

template<typename Prev, unsigned int Seed = RAND_TEMPLATE_SEED > 
struct RandomValue {    
    enum {_value = 2612001773U * Prev::_value + 65535, };
    //swap high and low words to hide bit patterns.
    static const unsigned int value = (static_cast<unsigned int>(_value) >> 16) + (static_cast<unsigned int>(_value) << 16);
    typedef RandomValue< RandomValue<Prev, Seed>, Seed> next;
};

template<unsigned int Seed> 
struct RandomValue<END, Seed> { 
    enum {_value = 2612001773U * Seed + 65535, };
    static const unsigned int value = (static_cast<unsigned int>(_value) >> 16) + (static_cast<unsigned int>(_value) << 16);
    typedef RandomValue< RandomValue<END, Seed>, Seed> next;    
};

typedef RandomValue<END> RV;

template <int N = 1, typename Base = RandomValue<END> > struct GetRandom {
    static const unsigned int value = GetRandom<N-1, typename Base::next>::value; 
};

template <typename Base > struct GetRandom<0, Base> {
    static const unsigned int value = Base::value; 
};


template <int N>
inline void Gen() {
    Gen<N-1>();
    std::cout << GetRandom<N>::value << std::endl; 
}

template <>
inline void Gen<0>() {
    std::cout << GetRandom<0>::value << std::endl; 
}



int main() {
    std::cout << RV::value << std::endl;
    std::cout << RV::next::value << std::endl;
    std::cout << RV::next::next::value << std::endl;
    std::cout << RV::next::next::next::value << std::endl;
    std::cout << RV::next::next::next::next::value << std::endl;
    std::cout << "\n---- Begin list ----" << std::endl;
    Gen<200>();
    std::cout << "\n---- End list ----" << std::endl;
    std::cout << GetRandom<199>::value << std::endl;
    return 0;
}