#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

void print_vector(vector<int> const &arr);
void swap(vector<int> &arr, int i, int j);

tuple<int, int> partition_plus(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int p1 = low - 1, p2 = high + 1;
    int pointer = low;
    while(pointer < p2){
        if (arr[pointer] < pivot)
        {
            p1 += 1;
            int tmp = arr[p1];
            arr[p1] = arr[pointer];
            arr[pointer] = tmp;
            pointer += 1;
        }
        else if (arr[pointer] > pivot)
        {
            p2 -= 1;
            int tmp = arr[p2];
            arr[p2] = arr[pointer];
            arr[pointer] = tmp;
        }
        else
        {
            pointer += 1;
        }
    }
    return make_tuple(p1, p2);
}

void quick_sort_plus(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int p1, p2;
        tie(p1, p2) = partition_plus(arr, low, high);
        quick_sort_plus(arr, low, p1);
        quick_sort_plus(arr, p2, high);
    }
}

int main()
{
    string line;
    cout << "Enter a sequence " << endl;
    getline(cin, line);
    istringstream iss(line);

    int input;
    vector<int> arr;
    while (iss >> input)
    {
        arr.push_back(input);
    }

    cout << "Input sequence:" << endl;
    print_vector(arr);
    quick_sort_plus(arr, 0, arr.size() - 1);
    cout << "After sorted:" << endl;
    print_vector(arr);
}

void print_vector(vector<int> const &arr)
{
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

void swap(vector<int> &arr, int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}