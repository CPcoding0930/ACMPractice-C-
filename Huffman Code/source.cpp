#include <iostream>
using namespace std;

class min_heap
{
private:
	int size;
	int numbers[100000];
public:
	min_heap() {
		size = 0;
	}
	int getSize() {
		return size;
	}
	int Pop() {
		int value = numbers[0];
		int child;
		numbers[0] = numbers[size - 1];
		int hole = 0;
		int temp = numbers[0];
		for (; hole * 2 + 1 < size; hole = child) {
			child = hole * 2 + 1;
			if (numbers[child + 1] < numbers[child] && child + 1 < size)
				child++;
			if (numbers[child] < temp)
				numbers[hole] = numbers[child];
			else
				break;
		}
		numbers[hole] = temp;
		size--;
		return value;
	}
	void Insert(int key) {
		int i = size;
		numbers[i] = key;
		while (numbers[i] < numbers[(i - 1) / 2] && i != 0) {
			swap(numbers[i], numbers[(i - 1) / 2]);
			i = (i - 1) / 2;
		}
		size++;
	}
};

int main() {
	int num;
	while (cin >> num) {
		min_heap minHeap;
		for (int i = 0; i < num; i++) {
			int m;
			cin >> m;
			minHeap.Insert(m);
		}

		int sum = 0;
		while (minHeap.getSize() > 1) {
			int min1 = minHeap.Pop();
			int min2 = minHeap.Pop();

			sum += (min1 + min2);
			minHeap.Insert(min1 + min2);
		}
		cout << sum << endl;
	}
	return 0;
}
