#include <vector>
using namespace std;

void heapify(vector<auto> &arr, int pos, int max_index){
    // See heap_sort.cpp for detail.
}

auto heap_maximum(vector<auto> const &arr){
    return arr[0];
}

auto heap_extract_maximum(vector<auto> &arr){
    auto maximum = arr[0];
    arr[0] = arr[arr.size()-1];
    heapify(arr, 0, arr.size()-2);
    return maximum;
}

template <typename T>
void max_heap_increase(vector<T> &arr, int pos, T value){
    if(value <= arr[pos]){
        return;
    }
    while(pos>0 && arr[(pos-1)/2] < value){
        arr[pos] = arr[(pos-1)/2];
        pos = (pos-1)/2;
    }
    arr[pos] = value;
}

template <typename T>
void max_heap_insert(vector <T> &arr, T value){
    T minimum = -9999;
    arr.push_back(minimum);
    max_heap_increase(arr, arr.size()-1, value);
}

int main(){}