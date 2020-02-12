#include <iostream>
#include <map>
using namespace std;

int getNum(long long n) {
	int first = 0;
	int second = 1;

	int res=0;

	for (int i = 2; i <= n; i++) {
		res = (first + second) % 10;
		first = second;
		second = res;
	}

	return res;
}

int find(int n) {
	if (n <= 60) {
		return n;
	}
	else {
		find(n % 60);
	}
}
int main() {
	map<int, int>Fibonacci;
	map<int, int>::iterator itr;
	//set the map with ans from 0-60
	int value = 0;
	Fibonacci.insert(pair<int, int>(0, 0));
	Fibonacci.insert(pair<int, int>(1, 1));
	for (int i = 2; i <= 60; i++) {
		Fibonacci.insert(pair<int, int>(i, getNum(i)));
	}

	//the input 
	int n;
	while (cin >> n) {
		int num = find(n);
		cout<<Fibonacci.at(num)<<endl;
	}
	return 0;
}
