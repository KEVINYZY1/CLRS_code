#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <tuple>

using namespace std;

typedef struct
{
    int small;
    int big;
} node;

void print_node_vector(vector<node> const &arr);

tuple<int, int> fuzz_partition(vector<node> &arr, int start, int end)
{
	node pivot = arr[end];
	int p1 = start - 1, p2 = end + 1;
	int pointer = start;
	while (pointer < p2){
		if(arr[pointer].big < pivot.small)
		{
			p1++;
			node tmp = arr[pointer];
			arr[pointer] = arr[p1];
			arr[p1] = tmp;
			pointer++;
		}
		else if(arr[pointer].small > pivot.big)
		{
			p2--;
			node tmp = arr[pointer];
			arr[pointer] = arr[p2];
			arr[p2] = tmp;
		}
		else
		{
			pivot.small = max(arr[pointer].small, pivot.small);
			pivot.big = min(arr[pointer].big, pivot.big);
			pointer ++;
		}
	}
	return make_tuple(p1, p2);
}

void fuzz_quick_sort(vector<node> &arr, int start, int end)
{
	int p1, p2;
	while (start < end)
	{
		tie(p1, p2) = fuzz_partition(arr, start, end);
		if(p1-start < end-p2)
		{
			fuzz_quick_sort(arr, start, p1);
			start = p2;
		}
		else
		{
			fuzz_quick_sort(arr, p2, end);
			end = p1;
		}
	}
}

int main()
{
	vector<node> arr;
	cout << "Enter random seed: ";
	unsigned seed;
	cin >> seed;
	srand(seed);
	for(int i=0; i<10; i++)
	{
		int a = rand() % 6;
		int b = rand() % 10;
		if (a > b)
		{
			int tmp = a;
			a = b;
			b = tmp;
		}
		node item = {a, b};
		arr.push_back(item);
	}
	print_node_vector(arr);
	fuzz_quick_sort(arr, 0, arr.size()-1);
	cout << "After fuzz sort: " << endl;
	print_node_vector(arr);
}

void print_node_vector(vector<node> const &arr)
{
	for (node i : arr)
	{
		cout << "[" << i.small << ", " << i.big << "] ";
	}
	cout << endl;
}