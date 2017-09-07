#include <iostream>
using namespace std;


// 参考 http://blog.csdn.net/eric_jo/article/details/4138548 , 3、函数中使用const d. 
class Foo{
public:
    Foo(int b){
        bar = b;
    }
    int bar;
};

void change_1(Foo f);
void change_2(const Foo f);

int main(){
    Foo f = Foo(1);
    cout << f.bar << endl;
    change_1(f);
    cout << f.bar << endl;
    change_2(f);
    cout << f.bar << endl;
}

void change_1(Foo f){
    f.bar = 2;
    cout << "in change 1: " << f.bar << endl;
}

void change_2(Foo const f){
    // f.bar = 3;  // read-only, cause wrong.
    Foo f2 = f;
    f2.bar = 2;
    cout << "in change 2: " << f2.bar << endl;
}