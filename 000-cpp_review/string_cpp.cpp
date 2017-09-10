#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main () {

   string str1 = "Hello";
   string str2 = "World";
   string str3;
   string split = " , ";
   int len ;

   // copy str1 into str3
   str3 = str1;
   cout << "str3 : " << str3 << endl;
   cout << sizeof(str1) << split 
        << sizeof(str2) << split
        << sizeof(str3) << endl << endl;

   // concatenates str1 and str2
   str3 = str1 + str2;
   cout << "str1 + str2 : " << str3 << endl;
   cout << sizeof(str1) << split 
        << sizeof(str2) << split
        << sizeof(str3) << endl << endl;

   // total length of str3 after concatenation
   len = str3.size();
   cout << "str3.size() :  " << len << endl;
   cout << sizeof(str1) << split 
        << sizeof(str2) << split
        << sizeof(str3) << endl << endl;
   return 0;
}