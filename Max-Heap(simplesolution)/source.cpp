#include <iostream>
using namespace std;
void max_heapify(int* a, int i, int n)
{
	int j, temp;
	temp = a[i];
	j = 2 * i;
	while (j <= n)
	{
		if (j < n && a[j + 1] > a[j])
			j = j + 1;
		if (temp > a[j])
			break;
		else if (temp <= a[j])
		{
			a[j / 2] = a[j];
			j = 2 * j;
		}
	}
	a[j / 2] = temp;
	return;
}
void build_maxheap(int *arr, int size)
{
	int i;
	for (i = size / 2; i >= 1; i--)
	{
		max_heapify(arr, i, size);
	}
}
int main()
{
	int numofOperations = 0;
	while (cin >> numofOperations)
	{
		int size = 1;
		int arr[10000];
		for (int i = 0; i < numofOperations; i++)
		{
			char operation;
			cin >> operation;
			int value = 0;
			if (operation == 'a')
			{
				cin >> value;
				arr[size] = value;
				build_maxheap( arr ,size);
				size +=1;
			}
			else if (operation == 'p')
			{
				arr[1] = arr[size - 1];
				size -= 1;
				build_maxheap(arr, size);
			}
			else if (operation == 'r')
			{
				int sum = 0;
				for (int i = 1; i < size; i++)
				{
					sum += arr[i];
				}
				cout << sum << endl;
			}
		}
	}
	return 0;
}
