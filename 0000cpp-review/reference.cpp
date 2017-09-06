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