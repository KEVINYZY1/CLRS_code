#include <iostream> 
using namespace std;
 
class Shape {
   protected:
      int width, height;
      
   public:
      Shape( int a = 0, int b = 0){
         width = a;
         height = b;
      }
      virtual int area() {
         cout << "Parent class area :" <<endl;
         return 0;
      }

      // virtual int area1() = 0;  // 含有纯虚函数的类无法实例化。
};
// Main function for the program
int main() {
    Shape *shape;
    Shape s(2, 3);
    shape = &s;
    shape ->area();     // 在不是继承的情况下，虚函数可以直接调用。
    // shape -> area1();  //含有纯虚函数的类无法实例化，更别说调用纯虚函数。
    return 0;
}