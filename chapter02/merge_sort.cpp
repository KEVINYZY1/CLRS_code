#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;


// 总时间复杂度 O(NlogN), 空间复杂度O(N)
template <typename T>
void merge(vector<T> &arr, int start, int mid, int end){
    vector<T> left, right;  // 空间复杂度贡献 O(N)
    for(int i=start; i<=mid; i++){
        left.push_back(arr[i]);
    }
    for(int i=mid+1; i<=end; i++){
        right.push_back(arr[i]);
    }

    int i_left=0, i_right=0;
    int len_left=left.size(), len_right=right.size();
    for (int k=start; k<=end; k++){
        if (i_left == len_left){
            while(i_right<len_right){
                arr[k++] = right[i_right++];
            }
        } else if (i_right == len_right){
            while(i_left<len_left){
                arr[k++] = left[i_left++];
            }
        } else {
            if (left[i_left] <= right[i_right]){
                arr[k] = left[i_left++];
            } else {
                arr[k] = right[i_right++];
            }
        }
    }
}

template <typename T>
void merge_sort(vector<T> &arr, int start, int end){
    if (start < end){
        int mid = (start+end)/2;
        merge_sort<T>(arr, start, mid);  // 递归调用，空间复杂度贡献 O(logN)
        merge_sort<T>(arr, mid+1, end);
        merge<T>(arr, start, mid, end);
    }
}

void print_vector(vector<auto> const &arr);

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

    merge_sort<int>(arr, 0, arr.size()-1);

    cout << "After merge sort: ";
    print_vector(arr);
    getchar();
}

void print_vector(vector<auto> const &arr){
    for (auto i: arr){
        cout << i << " ";
    }
    cout << endl;
}

