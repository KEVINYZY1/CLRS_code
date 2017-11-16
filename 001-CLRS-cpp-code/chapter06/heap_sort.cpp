#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void print_vector(vector<auto> const & arr);

void heapify_circulation(vector<auto> &arr, int pos, int max_index){
    int left_index, right_index, next_pos;
    while(1){
        int left_index = 2 * pos + 1;
        int right_index = 2 * pos + 2;
        int next_pos = pos;
        auto tmp = arr[pos];
        if(left_index <= max_index && arr[left_index] > arr[next_pos]){
            next_pos = left_index;
        }
        if(right_index <= max_index && arr[right_index] > arr[next_pos]){
            next_pos = right_index;
        }
        if(next_pos == pos){
            break;
        } else {
            tmp = arr[pos];
            arr[pos] = arr[next_pos];
            arr[next_pos] = tmp;
            pos = next_pos;
        }
    }
}

void heapify_recursively(vector<auto> & arr, int pos, int max_index){
    int left_index = 2*pos + 1;
    int right_index = 2*pos + 2;
    int next_pos = pos;
    if(left_index <= max_index && arr[left_index] > arr[next_pos]){
        next_pos = left_index;
    }
    if(right_index <= max_index && arr[right_index] > arr[next_pos]){
        next_pos = right_index;
    }
    if(pos != next_pos){
        auto tmp = arr[pos];
        arr[pos] = arr[next_pos];
        arr[next_pos] = tmp;
        heapify_recursively(arr, next_pos, max_index);
    }
}

void build_heap(vector<auto> & arr){ß
    // 建堆过程虽然对N/2个节点进行了可能的调整，但越在前面的元素，需比较的次数越少，
    // 且比较次数少的占大头，最后累计求和起来，复杂度只有O(N)
    int last_not_leaf_index = arr.size()/2 - 1;
    for(int i=last_not_leaf_index; i>=0; i--){
        heapify_recursively(arr, i, arr.size()-1);
    }
}

void heap_sort(vector<auto> &arr){
    build_heap(arr);
    auto tmp = arr[0];
    for(int i=arr.size()-1; i>=1; i--){
        tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        heapify_circulation(arr, 0, i-1);
    }
}

int main(){
    string line;
    cout << "Enter a price sequence:(must contain positive number) " << endl;
    getline(cin, line);
    istringstream iss(line);

    int input;
    vector<int> arr;
    while(iss >> input){
        arr.push_back(input);
    }

    heap_sort(arr);
    cout << "After sorted:" << endl;
    print_vector(arr);
}

void print_vector(vector<auto> const & arr){
    for(auto i:arr){
        cout << i << " ";
    }
    cout << endl;
}