#include <iostream>
using namespace std;

void example_common();
void example_array();
void example_object();

class Box {
public:
    Box(){
        cout << "Box constructor called" << endl;
    }

    ~Box(){
        cout << "Box deconstructor called" << endl;
    }
};

int main(){
    example_common();
    example_array();
    example_object();
    return 0;
}

void example_common(){
    double *pvalue = NULL;
    int *pivalue = NULL;
    cout << pvalue << " " << &pvalue << " " << pivalue << " " << &pivalue << endl;

    pvalue = new double;
    cout << "Value of pvalue: " << *pvalue << " pvalue: " << pvalue << " Address of pvalue: "<< &pvalue << endl;

    *pvalue = 291.4;
    cout << "Value of pvalue: " << *pvalue << " pvalue: " << pvalue << " Address of pvalue: "<< &pvalue << endl;

    delete pvalue;
    cout << "Value of pvalue: " << *pvalue << " pvalue: " << pvalue << " Address of pvalue: "<< &pvalue << endl;
    // delete pvalue释放了pvalue所指的内存，指针仍存在，只不过指向的内存是垃圾,
    // 因此一般在在delete后使其为NULL
    pvalue = NULL;
    cout << pvalue << endl;
}

void example_array(){
    int * pvalue = NULL;
    pvalue = new int[20];
    int * pvalue_copy = pvalue;
    for(int i=0; i<10; i++, pvalue++){
        *pvalue = i;
    }
    cout << pvalue << " " << *pvalue << " " 
         << pvalue_copy << " " << *pvalue_copy << endl;;
    delete [] pvalue;
    pvalue = NULL;

    double ** pdvalue = NULL;
    pdvalue = new double * [4];
    delete [] pdvalue;
    pdvalue = NULL;
}

void example_object(){
    Box * my_box_array = new Box[4];
    delete [] my_box_array; // Delete array
    my_box_array = (Box *)NULL;
}