#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool ConeIsMore(vector <vector<char> > table, int size, int j) {
	int countzero = 0;
	int countone = 0;
	for (int i = 0; i < size; i++) {
		(table[i][j] == '0')?++countzero: ++countone;
	}
	if (countone >= countzero) {
		return true;
	}
	return false;
}

bool RoneIsMore(vector <vector<char> > table, int size, int i) {
	int countzero = 0;
	int countone = 0;
	for (int j = 0; j < size; j++) {
		(table[i][j] == '0') ? ++countzero : ++countone;
	}
	if (countone >= countzero) {
		return true;
	}
	return false;
}

int main() {
	//Initialise row and column
	int row; 
	int column;
	while (cin >> row >> column) {
		//Initiallise 2D vector
		vector <vector<char> > table(row, vector<char>(column));

		//get each digit of number and store it into number
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				cin >> table[i][j];
			}
		}

		//check for column
		for (int j = 0; j < column; j++) {
			if (!ConeIsMore(table, row, j)) {
				for (int i = 0; i < row; i++) {
					(table[i][j] == '0') ? table[i][j] = '1' : table[i][j] = '0';
				}
			}
		}

		//check for row
		for (int j = 0; j < row; j++) {
			if (!RoneIsMore(table, column, j)) {
				for (int i = 0; i < column; i++) {
					(table[j][i] == '0') ? table[j][i] = '1' : table[j][i] = '0';
				}
			}
		}

		//check for column
		for (int j = 0; j < column; j++) {
			if (!ConeIsMore(table, row, j)) {
				for (int i = 0; i < row; i++) {
					(table[i][j] == '0') ? table[i][j] = '1' : table[i][j] = '0';
				}
			}
		}

		//check for row
		for (int j = 0; j < row; j++) {
			if (!RoneIsMore(table, column, j)) {
				for (int i = 0; i < column; i++) {
					(table[j][i] == '0') ? table[j][i] = '1' : table[j][i] = '0';
				}
			}
		}

		//Count One in the table
		int ans = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				(table[i][j] == '1') ? (ans++) : (ans = ans);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
