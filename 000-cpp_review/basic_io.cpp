#include <iostream>
using namespace std;

int main(){
    // 注：这里会产生安全隐患,输入数据大于10会越界。
    char name[10];
    char *name1 = new char[10];

    // 下面三行，输出一致。
    cout << sizeof(name) << " " << sizeof(name1) << endl;
    cout << sizeof(*name1)*10 << " " << sizeof(&(name[0])) << endl;
    cout << sizeof(char)*10 << " " << sizeof(char *) << endl;

    // 下面两个表示的都是地址，但一个可以将地址打印出来，另一个打印出来的是地址指向的字符。
    // 所以类型不同，打印的对象也不同。
    cout << &name << " |  " << &(name[0]) << endl;

    // 直接打印两个指向字符的地址
    cout << &(*name1) << " | " << &(*name) << endl;

    cout << "Please enter your name in char[1]" << endl;
    cin >> name;
    cin.ignore();
    cout << "Please enter your name1 in char *" << endl;
    cin >> name1;
    clog << "Log message1: " << name << " has been recorded" << endl;
    clog << "Log message2: " << name1 << " has been recorded" << endl;
    cerr << "Sorry, something wrong with the system." << endl;

    cout << endl;
    cout << *name << name[1] << *(name+2) << name[3] << name[4] << endl;
    cout << *name1 << name1[1] << *(name1+2) << name1[3] << name1[4] << endl;
}
