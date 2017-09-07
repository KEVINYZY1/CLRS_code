#include <iostream>

using namespace std;

int main () {
    // declare simple variables
    int    i;
    double d;

    // declare reference of double
    int&    r = i;
    double& s = d;
    
    i = 5;
    cout << "Value of i : " << i << endl;
    cout << "Value of i reference: " << r  << endl;
    cout << "Address of i: " << &i << endl;
    cout << "Address of i reference:" << &r << endl; 

    d = 11.7;
    cout << "Value of d : " << d << endl;
    cout << "Value of d reference : " << s  << endl;
    cout << "Address of d: " << &d << endl;
    cout << "Address of d reference:" << &s << endl; 

    // 根据打印结果得知，他俩就是一摸一样的，从本质到表面，只不过名字不一样
    return 0;
}

/*
Difference between pointer and reference:

1. You cannot have NULL references. You must always be able to assume that a reference is connected to a legitimate piece of storage.

2. Once a reference is initialized to an object, it cannot be changed to refer to another object. Pointers can be pointed to another object at any time.

3. A reference must be initialized when it is created. Pointers can be initialized at any time.
*/

/*
1	References as Parameters
C++ supports passing references as function parameter more safely than parameters.

2	Reference as Return Value
You can return reference from a C++ function like any other data type. 
返回的引用可以作为 left value 使用.
*/