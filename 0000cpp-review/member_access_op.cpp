#include <iostream>
#include <vector>

using namespace std;

// Consider an actual class
class Obj {
    static int i, j;

public:
    void f() const { cout << i++ << endl;}  // 函数后加const表示不会修改类成员
    void g() const { cout << j++ << endl;}
};

// Static member definitions;
int Obj::i = -5;
int Obj::j = 5;

// Implement a container for the above class
class ObjContainer {
    vector<Obj *> a;  // 保存 Obj对象的地址 的vector

public:
    void add(Obj* obj){  // 参数为 Obj对象的地址
        a.push_back(obj);  // call vector's standard method.
    }
    friend class SmartPointer;
};

// implement smart pointer to access member of Obj class.
class SmartPointer {
    ObjContainer oc;
    int index;

public:
    SmartPointer(ObjContainer& objc) {  // 参数为ObjConrainer的某对象的引用
        oc = objc;
        index = 0;
    }
    
    // Return value indicates end of list;
    bool operator++() { // Prefix version
        if(index >= oc.a.size()) return false;
        if(oc.a[++index] == 0) return false;
        return true;
    }

    bool operator++(int) { // Postfix version
        return operator++();
    }

    Obj* operator->() const {
        if(!oc.a[index]){  /* 遇到该Obj对象的地址为0，将地址0强转为 Obj* 类型的地址并返回
            根据pointer.cpp介绍，若地址值为0，说明该指针为空指针，指针的值是一个常量0。
            */
            cout << "Zero value";
            return (Obj*)0;
        }

        return oc.a[index];  // 否则直接返回该 对象地址
    }
};

int main(){
    const int sz = 10;
    Obj o[sz];
    ObjContainer oc;

    for(int i=0;i<sz;i++){
        oc.add(&o[i]);  // 取地址符号
    }

    SmartPointer sp(oc);
    do {
        sp->f();  // smart pointer call
        sp->g();
    } while(sp++);

    return 0;
}