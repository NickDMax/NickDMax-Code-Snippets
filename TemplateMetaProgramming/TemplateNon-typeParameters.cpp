//#include <iostream>
//#include <string>
//using namespace std;
//
//template <typename T, T* N>
//T retNAME() { return *N; }
//extern const string constData = string("Testing");
//extern const string* someConst = &constData;
//const int A = 5;
//const int *B = &A;
//
//int main() {
//    cout << retNAME<string, someConst>();
//    return 0;
//}

//
//#include <iostream>
//#include <string>
//using namespace std;
//
//template <typename T, T* NAME>
//T retNAME() { return *NAME; }
//
//string niceStr = "Nice String";
//
//int main() {
//    cout << retNAME<string, &niceStr>() <<endl;
//    return 0;
//}

// template_specifications2.cpp
//
//class Y 
//{
//};
//template<class T, T* pT> class X1 
//{
//};
//template<class T1, class T2 = T1> class X2 
//{
//};
//
//Y aY;
//
//X1<Y, &aY> x1;
//X2<int> x2;
//
//int main()
//{
//}



//#include <iostream>
//#include <cstring>
//#include <fstream>
//using namespace std;
//
//template <typename Typ, Typ *neutral> class zbior{
//    int _rozmiar;
//    Typ *ti;
//    static const int DomysRoz=5;
//public:
//    explicit zbior(int rzm=DomysRoz);
//
//};
//
//template <typename Typ, Typ *neutral> 
//zbior<Typ,neutral>::zbior(int rzm){
//    _rozmiar=rzm;
//    ti=new Typ[_rozmiar];
//    for (int ix=0; ix<_rozmiar; ++ix){
//        ti[ix]=*neutral;
//    }
//}
//
//const string p="kot";
//
//int main(){
//    zbior<string,&p> k;
//    return 0;
//}

#include <iostream>
#include <string>

extern std::string bar = "Hello, World";
extern const std::string * barPtr = &bar;

template<const std::string* str>
struct foo
{
    void display() { std::cout << *str; }
};

int main()
{
    foo<barPtr> f;
    f.display();
}