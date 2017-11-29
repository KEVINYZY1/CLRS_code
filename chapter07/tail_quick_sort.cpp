#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void print_vector(vector<int> const &arr);
int partition(vector<int> &arr, int start, int end)
{
	int element = arr[end];
	int tmp, i = start - 1;
	for (int j = start; j <= end; j++)
	{
		if (arr[j] <= element)
		{
			i += 1;
			if (i < j)
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	return i;
}

void quick_sort(vector<int> &arr, int start, int end)
{
	while (start < end)
	{
		int mid = partition(arr, start, end);
        if (mid < (start + end) / 2)
        {
            quick_sort(arr, start, mid-1);
            start = mid + 1;  // 不再多压入一层栈，直接在本层栈进行处理尾递归部分。
        }
        else
        {  // 尽可能的降低站深度
            quick_sort(arr, mid+1, end);
            end = mid - 1;
        }
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

	quick_sort(arr, 0, arr.size() - 1);
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