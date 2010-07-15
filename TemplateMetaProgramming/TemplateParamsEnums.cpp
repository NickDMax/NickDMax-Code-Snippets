#include <iostream>
#include <string>

using namespace std;

const string classNames[2] = {
"FOO", "BAR"
};

enum ClassNames {
    FOO, BAR
};

template<ClassNames TYPE>
class FooBarTemplate{
    public:
    const string &getType() {return classNames[TYPE]; }
};

int main() {
    FooBarTemplate<FOO> foo;
    FooBarTemplate<BAR> bar;
    cout << foo.getType() << " " << bar.getType() << endl;
    return 0;
}