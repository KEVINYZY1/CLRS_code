#include <iostream>
using namespace std;

int main(){
    typedef int feet;
    feet distance = 1;
    cout << distance << endl;

    typedef enum color { red, green = 5, blue } COLOR;
    COLOR c = blue;
    cout << c << endl;
}
