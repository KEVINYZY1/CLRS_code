#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;


template<typename T>
void sum_two(vector<T> const numbers, T target){
    bool found = false;
    unordered_map<T, bool> m;
    for (auto i: numbers){
        m.insert(make_pair(i, true));
    }
    for(int i=0; i<numbers.size();i++){
        int remain = target - numbers[i];
        if (m.count(remain)>0){
            cout << "Found " << numbers[i] << " " << remain << " satistied." << endl;
            found = true;
            break;
        }
    }
    if(!found){
        cout << "Not found" << endl;
    }
}

int main(){
    string line;
    cout << "Enter a int sequence: ";
    getline(cin, line);
    istringstream iss(line);

    int input;
    vector<int> arr;
    while(iss >> input){
        arr.push_back(input);
    }
    cout << "Enter sum: ";
    cin >> input;
    sum_two<int>(arr, input);
}