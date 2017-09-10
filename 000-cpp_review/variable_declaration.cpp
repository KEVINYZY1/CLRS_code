#include<iostream>
using namespace std;

// Variable declaration
extern int a, b;
extern int c;
extern float f;

// Function declaration
int func();

int main(){
    // Variable definition
    int a, b;
    int c;
    float f;

    // Actual initialization
    a = 10;
    b = 20;
    c = a + b;

    cout << c << endl;

    f = 70.0 / 3.0;
    cout << f << endl;

    // Function call
    int result = func();
    cout << result;

    return 0;
}

// Function definition
int func(){
    return 0;
}
