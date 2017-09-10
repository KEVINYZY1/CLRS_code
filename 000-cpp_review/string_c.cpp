#include <iostream>
#include <cstring>

using namespace std;

int main () {

   char str1[10] = "Hello";
   char str2[10] = "World";
   char str3[10];
   string split = " , ";
   int  len;

   cout << sizeof(str1) << split 
        << sizeof(str2) << split
        << sizeof(str3) << endl << endl;

   // copy str1 into str3
   strcpy(str3, str1);  // 此系列方法只适用于c方式的string
   cout << "strcpy(str3, str1) : " << str3 << endl;
   cout << sizeof(str1) << split 
        << sizeof(str2) << split
        << sizeof(str3) << endl << endl;

   // concatenates str1 and str2
   strcat( str1, str2);
   cout << "strcat( str1, str2): " << str1 << endl;
   cout << sizeof(str1) << split 
        << sizeof(str2) << split
        << sizeof(str3) << endl << endl;

   // total lenghth of str1 after concatenation
   len = strlen(str1);
   cout << "strlen(str1) : " << len << endl;
   cout << sizeof(str1) << split 
        << sizeof(str2) << split
        << sizeof(str3) << endl << endl;
   return 0;
}