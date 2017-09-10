#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

void insertion_sort(vector<auto> &arr){
    for(int i=1; i<arr.size(); i++){
        int j = i - 1;
        auto key = arr[i];
        while(j>=0 && key<arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    return;
}

void print_vector(vector<auto> const &arr){
    for (auto i: arr){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    string line;
    getline(cin, line);
    istringstream iss(line);

    int input;
    vector<int> arr;
    while(iss >> input){
        arr.push_back(input); 
    }

    cout << "Your int put:  ";
    print_vector(arr);

    insertion_sort(arr);

    cout << "After sort:  ";
    print_vector(arr);
}
