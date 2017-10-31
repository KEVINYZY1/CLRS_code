#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void print_vector(vector<int> const &arr);

int hoare_partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low - 1, j = high + 1;
    while (true)
    {
        do
        {
            j -= 1;
        } while (arr[j] > pivot);
        do
        {
            i += 1;
        } while (arr[i] < pivot);
        if (i < j)
        {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
        else
        {
            return j;
        }
    }
}

void hoare_quick_sort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int pivot_index = hoare_partition(arr, start, end);
        hoare_quick_sort(arr, start, pivot_index);
        hoare_quick_sort(arr, pivot_index + 1, end);
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

    hoare_quick_sort(arr, 0, arr.size() - 1);
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