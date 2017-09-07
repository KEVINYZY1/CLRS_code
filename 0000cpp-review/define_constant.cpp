#include <iostream>
using namespace std;

#define LENGTH 10
#define WIDTH 5
#define NEWLINE "\n"  // 这个定义的是字符串

void print_constant();

int main(){
    int area;

    area = LENGTH * WIDTH;
    cout << area;
    cout << NEWLINE;

    print_constant();
    return 0;
}

void print_constant(){
    // const int 等价于 int const
    const int length = 20;
    int const width = 10;
    const char new_line = '\n';

    cout << length * width << new_line;
}
