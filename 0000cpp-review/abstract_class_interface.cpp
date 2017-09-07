#include <iostream>
using namespace std;

// Base class or it is abstract class
class Shape{
public:
    // pure virtual function providing interface framework
    virtual int get_area() = 0;
    void set_width(int w){
        width = w;
    }
    void set_height(int h){
        height = h;
    }
protected:
    int width;
    int height;
};

// Derived classes
class Rectangle: public Shape{
public:
    int get_area(){
        return width * height;
    }
};

class Triangle: public Shape{
public:
    int get_area(){ // 这里无法使用double返回值
        return (width * height) / 2;
    }
};

int main(){
    Rectangle rect;
    Triangle tri;

    rect.set_width(5);
    rect.set_height(7);

    cout << rect.get_area() << endl;

    // every drived class set it's value respectly

    tri.set_width(5);
    tri.set_height(7);
    cout << tri.get_area() << endl;
    return 0;
}
