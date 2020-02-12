/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 100866
 * Submitted at:  2019-12-13 11:50:07
 *
 * User ID:       740
 * Username:      55700892
 * Problem ID:    741
 * Problem Name:  Coin flipping easy game
 */

#include <iostream>
#include <string>
using namespace std;

int n, m;
int table[100][10];
int tableCopy[100][10];
int result = 0;

static void brain(int level);
static int countTotal() {
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			count += table[i][j];
		}
	}
	return count;
}

static void input() {
	while (cin >> n >> m) {
		result = 0;
		for (int i = 0; i < n; i++) {
			string row;
			cin >> row;
			for (int j = 0; j < m; j++) {
				table[i][j] = (int)row.at(j) - '0';
				tableCopy[i][j] = (int)row.at(j) - '0';
			}
		}
		brain(0);
		cout << result << endl;
	}
}


static int rowCount(int row) {
	int count = 0;
	for (int i = 0; i < m; i++) {
		count += table[row][i];
	}
	return count;
}

static void flipColumn(int column) {
	for (int i = 0; i < n; i++) {
		if (table[i][column] == 0)
			table[i][column] = 1;
		else
			table[i][column] = 0;
	}
}

static void brain(int level) {
	if (level < m) {
		level++;
		brain(level);
		flipColumn(level - 1);
		brain(level);
	}
	if (level == m) {
		int x = countTotal();
		for (int i = 0; i < n; i++) {
			if (rowCount(i) < m / 2)
				x += m - (2 * rowCount(i));
		}
		if (x > result)
			result = x;
	}
}

int main() {
	input();
	return 0;
}
