#include <iostream>

template<unsigned int A, unsigned int B>
struct GCD { enum { value = GCD<B, A % B>::value, }; };

template<unsigned int A>
struct GCD<A, 0> { enum { value = A, }; };

template<unsigned int A, unsigned int B>
struct LCM { enum { value = A * (B / GCD<A,B>::value), }; };

template<typename T, unsigned int MinSize, unsigned int BlockSize>
class AlignedArray {
    enum { 
        _lcm = LCM<sizeof(T), BlockSize>::value,
        _min = MinSize * sizeof(T),
        _size = _lcm * (_min / _lcm + (_min % _lcm > 0))/sizeof(T), 
    };
    public:
    typedef T value_type[_size];
};

template<typename T, unsigned int SIZE>
static inline unsigned int arraySize(const T (&array)[SIZE]) { return SIZE; }

struct Testing { short a; char b; };

#pragma pack(push, 1)
struct Testing2 { short a; char b; };
#pragma pack(pop)

#define TEST_GCD(V1, V2) std::cout << "GCD<" #V1 ", " #V2 ">::value = " << GCD<V1, V2>::value << std::endl

#define TEST_LCM(V1, V2) std::cout << "LCM<" #V1 ", " #V2 ">::value = " << LCM<V1, V2>::value << std::endl

#define TEST_CASE(array, mult) \
    std::cout << arraySize(array) \
              << " | "<< sizeof(*array) \
              << " = " << sizeof(array) \
              << " | " << sizeof(array) / mult  \
              << std::endl

int main() {
    std::cout << "GCD test: " << std::endl;
    TEST_GCD(2*5*7*13, 5*7);
    TEST_GCD(2*2*5*7*13, 2*7*7*7);
    TEST_GCD(423, 78);

    std::cout << "\n-----------------\n" << std::endl;

    std::cout << "LCM test: " << std::endl;
    TEST_LCM(2*5*7*13, 5*7);
    TEST_LCM(2*2*5*7*13, 2*7*7*7);
    TEST_LCM(423, 76);

    std::cout << "\n-----------------\n" << std::endl;

    std::cout << "Min size 1 block size 16" << std::endl;
    AlignedArray<char, 1, 16>::value_type array1;
    AlignedArray<int, 1, 16>::value_type array2;

    TEST_CASE(array1, 16.0);
    TEST_CASE(array2, 16.0);


    std::cout << "Min size 10 block size 16" << std::endl;
    AlignedArray<Testing, 10, 16>::value_type array3;
    AlignedArray<Testing2, 10, 16>::value_type array4;

    TEST_CASE(array3, 16.0);
    TEST_CASE(array4, 16.0);


    std::cout << "Min size 5 block size 3" << std::endl;
    AlignedArray<Testing, 5, 3>::value_type array5;
    AlignedArray<Testing2, 5, 3>::value_type array6;

    TEST_CASE(array5, 3.0);
    TEST_CASE(array6, 3.0);

    return 0;
}