#include <iostream>
using namespace std;

// first name space
namespace first_space {
   void func() {
      cout << "Inside first_space" << endl;
   }
}

// second name space
namespace second_space {
   void func() {
      cout << "Inside second_space" << endl;
   }
}

// 使用多个using namespace 若两个namespace有重复声明、定义的东西，那么后面的会覆盖前面的
using namespace first_space;

int main () {
   func();

   // 若使用单个成员，如下
   using  second_space::func;
   func();

   // 此外，可以使用嵌套namespace
   return 0;
}