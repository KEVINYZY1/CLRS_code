#include <iostream>

using namespace std;

void print_void();
void print_pointer_anotherway();

int main () {
   int  var1;
   double var2[10];

   cout << "Address of var1 variable: ";
   cout << &var1 << endl;

   cout << "Address of var2 variable: ";
   cout << &var2 << endl;

   cout << "Address of first element in var2: ";
   cout << &var2[0] << " same to " << var2 << endl;
 
   print_pointer_anotherway();
   print_void();

   return 0;
}

void print_pointer_anotherway(){
    int a = 10;
    int *b = &a;
    cout << *b << " " << b  << " " << &b << endl;
}

void print_void(){
    void *b = NULL;  /* same as:
    void *b;
    b = NULL;  
    */
    cout << b << " " << " " << &b << endl;  // 这里无法打印 *b，在编译时通过不了,
                                            // 因为声明里面已经说了b是个指向void的指针，无法获取不存在的值。

    int *c = NULL; 
    cout << c << " " << " " << &c << endl; // 这里打印 *c时，编译可以通过，但是运行会出现segmentation fault
                                           // 因为相当于去寻找地址为0的int对象，地址为0一般为系统地址，寻址时便出现错误。
}