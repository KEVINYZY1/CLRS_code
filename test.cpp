#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

typedef struct
{
    int small;
    int big;
} node;


int main(){
    node a = {1, 2};
    node b = a;
    b.small = 0;
    cout << a.small << a.big;
    cout << b.small << b.big;
}