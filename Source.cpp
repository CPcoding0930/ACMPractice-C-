#include <iostream>
#include <cstdlib>
#define MAX_N 30000
using namespace std;
//A Question about disjoint set
//1. Make set
int set[MAX_N], num[MAX_N], n;
void make_set() {
	for (int i = 1; i <= n; i++) {
		set[i] = i;
		num[i] = 1;
	}
}
//2. Group & Union Set
void union_set(int a, int b) {
	//if not the same
	if (set[a] != set[b]) {
		int x = set[a], y = set[b];
		num[set[a]] = 0;
		for (int i = 1; i <= n; i++) {
			if (set[i] == x) {
				set[i] = y;
				num[set[b]]++;
			}
		}
	}
}

int main()
{
	int t, m, a, b;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		make_set();
		while (m--) {
			cin >> a >> b;
			union_set(a, b);
		}
		int max = 0;
		for (int i = 1; i <= n; i++) {
			if (num[i] > max) max = num[i];
		}
		cout << max << endl;
	}
	return 0;
}