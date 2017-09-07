#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>
using namespace std;

void normal_use();
void class_use();

/*
inline函数：因为调用函数时，系统会造成额外开销，
使用inline函数，相当于直接在调用点展开函数内部代码，
一般用于写成函数易理解，但调用函数额外开销占用较大的地方
*/
template <typename T>  // 用class 代替typename一样
inline T const & Max (T const & a, T const & b){
    return a < b ? b : a;
}

template <class T>  // 可以用typename代替class
class Stack{
private:
    vector<T> elems;  // elements

public:
    void push(T const &);  // push element
    void pop();     // pop element
    T top() const;  // return top element, 常成员函数，不会修改其它类成员

    bool empty() const{
        return elems.empty();
    }
};

template <class T>
void Stack<T>::push(T const& elem){  // 实现方法时，显示类型一定要带着，调用时才可以省略，见行73
    //append copy of passed element
    elems.push_back(elem);
}

template <class T>
void Stack<T>::pop(){
    if(elems.empty()){
        throw out_of_range("Stack<>::pop(): empty stack");
    }

    // remove last element
    elems.pop_back();
}

template <class T>
T Stack<T>::top() const{
    if (elems.empty()) { 
        throw out_of_range("Stack<>::top(): empty stack"); 
    }
     // return copy of last element 
     return elems.back();    
}

int main(){
    normal_use();
    class_use();
    return 0;
}

void normal_use(){
    int i = 39;
    int j = 20;
    // 在没有歧义，编译器可以自动发现函数类型情况下，可以省略显示类型的传入
    // 如下调用，其和调用Max<int>(i, j)作用相同。
    cout << "Max(i, j): " << Max(i, j) << endl; 

    // 以下验证显示加的模板的作用
    int const * tmp = &(Max(i, j));
    double const * tmp2 = &(Max<double>(i, j));  // 若使用int count * 会报错
    cout << *tmp/2 << " " << *tmp2/2 << endl;
 
    double f1 = 13.5; 
    double f2 = 20.7; 
    // 若显示传入类型，那么，传进去的double都要被强转为int
    cout << "Max(f1, f2): " << Max<int>(f1, f2) << endl; 
 
    string s1 = "Hello"; 
    string s2 = "World"; 
    cout << "Max(s1, s2): " << Max(s1, s2) << endl; 
}

void class_use(){
    try {
        Stack<int> int_stack;  // stack of ints
        Stack<string> string_stack;    // stack of strings 
  
        // manipulate int stack 
        int_stack.push(7); 
        cout << int_stack.top() <<endl; 
  
        // manipulate string stack 
        string_stack.push("hello"); 
        cout << string_stack.top() << std::endl; 

        string_stack.pop(); 
        string_stack.pop(); 
     } catch (exception const& ex) { 
        cerr << "Exception: " << ex.what() <<endl; 
     } 
}