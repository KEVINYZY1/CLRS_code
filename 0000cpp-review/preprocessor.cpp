#include <iostream>
using namespace std;

#define DEBUG
#define MIN(a,b) (((a)<(b)) ? a : b)
#define MKSTR(x) #x
#define concat(a, b) a##b

void example_1();
void example_2();
void example_3();
void example_4();

int main () {
    example_1();
    example_2();
    example_3();
    example_4();
    return 0;
}

void example_1(){

    int i, j;
   
    i = 100;
    j = 30;

    #ifdef DEBUG
    cerr <<"Trace: Inside main function" << endl;
    #endif

    #if 0
    /* This is commented part */
    cout << MKSTR(HELLO C++) << endl;
    #endif

    cout <<"The minimum is " << MIN(i, j) << endl;

    #ifdef DEBUG
    cerr <<"Trace: Coming out of main function" << endl;
    #endif
}

void example_2(){
    cout << MKSTR(Hello c++) << endl;
}

void example_3(){
    int xy = 100;
    cout << concat(x, y) << endl;
}

void example_4(){
    cout << "Value of __LINE__ : " << __LINE__ << endl;
    cout << "Value of __FILE__ : " << __FILE__ << endl;
    cout << "Value of __DATE__ : " << __DATE__ << endl;
    cout << "Value of __TIME__ : " << __TIME__ << endl;
}