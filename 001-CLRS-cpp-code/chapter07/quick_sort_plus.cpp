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
    int p1 = low - 1, p2 = low - 1;
    for (int pointer = low; pointer <= high; pointer++)
    {
        if (arr[pointer] < pivot)
        {
            if (p1 == p2)
            {
                p1 += 1;
                p2 += 1;
                if (p1 < pointer)
                {
                    swap(arr, pointer, p1);
                }
            }
            else
            {
                arr[++p1] = arr[pointer];
                arr[pointer] = arr[++p2];
                arr[p2] = pivot;
            }
        }
        else if (arr[pointer] == pivot)
        {
            p2 += 1;
            if (p2 < pointer)
            {
                swap(arr, pointer, p2);
            }
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
        quick_sort_plus(arr, p2 + 1, high);
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