#include <iostream>
using namespace std;

int main(){
    char name[50];
    cout << "Please enter your name" << endl;
    cin >> name;
    clog << "Log message: " << name << " has been recorded" << endl;
    cerr << "Sorry, something wrong with the system." << endl;
}