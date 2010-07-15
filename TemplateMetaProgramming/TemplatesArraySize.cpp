//For consistency
template<typename T, unsigned int SIZE>
static inline T* arrayBegin(T (&array)[SIZE] ) { return array; }


//Get end: stl expects arguments [begin, end) 
template<typename T, unsigned int SIZE>
static inline T* arrayEnd(T (&array)[SIZE]) { return array + SIZE; }

template<typename T, unsigned int SIZE>
static inline unsigned int arraySize(const T (&array)[SIZE]) { return SIZE; }

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    //Some data.
    int array[] = { 3,1,4,15,9,2,6,5,35,8,97,93,23,84,62,64,33,83,27,95,0,28,841,971,69,39,937,51 };
    
    //grab the size of the array...
    cout << "Array size: " << arraySize(array) << endl;
    
    //test the arrayBegin()/arrayEnd() with a STL algorithm
    sort(arrayBegin(array), arrayEnd(array));
    
    // display data (using C++0x lambda)
    for_each(arrayBegin(array), arrayEnd(array), [](const int& n) { cout << n << ", "; });

    return 0;
}
