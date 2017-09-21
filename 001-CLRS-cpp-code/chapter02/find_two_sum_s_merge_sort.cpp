#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

// copy from ../code/merge_sort.cpp
template <typename T>
void merge(vector<T> &arr, int start, int mid, int end);

template <typename T>
void merge_sort(vector<T> &arr, int start, int end);

template <typename T>
void sum_two(vector<T> const &arr, T target){
    bool found = false;
    int start=0, end=arr.size()-1;
    while(end>start){
        T a = arr[start];
        T b = arr[end];
        if (a+b < target){
            start ++;
        } else if (a+b > target){
            end --;
        } else {
            cout << "Find " << a << " and " << b << " satisfied." << endl;
            found = true;
            break;
        }
    }
    if(!found){
        cout << "Not found." << endl;
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
    merge_sort<int>(arr, 0, arr.size()-1);
    sum_two<int>(arr, input);
}

template <typename T>
void merge(vector<T> &arr, int start, int mid, int end){
    vector<T> left, right;
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
        merge_sort<T>(arr, start, mid);
        merge_sort<T>(arr, mid+1, end);
        merge<T>(arr, start, mid, end);
    }
}