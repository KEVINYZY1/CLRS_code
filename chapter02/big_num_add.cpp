#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

string big_num_add(string num1, string num2){
    int len1 = num1.length(), len2 = num2.length();
    int len = len1>len2 ? len1 : len2;
    string results(len, ' ');
    int carry=0, tmp1, tmp2;
    for(int i=0; i<len; i++){
        tmp1 = (len1 > i ? num1.at(len1-1-i) : '0') - '0';
        tmp2 = (len2 > i ? num2.at(len2-1-i) : '0') - '0';
        results.at(len-1-i) = (tmp1+tmp2+carry) % 10 + '0';
        carry = (tmp1+tmp2+carry) / 10;
    }
    return results;
}

int main(){
    string num1, num2;
    cout << "Enter two big num: ";
    cin >> num1 >> num2;
    cout << "Sum: " << big_num_add(num1, num2);
}