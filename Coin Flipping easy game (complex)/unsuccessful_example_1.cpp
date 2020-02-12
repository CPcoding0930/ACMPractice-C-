#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int RcountDifference(vector <vector<char> > table, int col, int var) {
	int Difference = 0;
	for (int j = 0; j < col; j++) {
		if (table[var][j] == '1') {
			Difference -= 1;
		}
		else {
			Difference += 1;
		}
	}
	return Difference;
}

int CcountDifference(vector <vector<char> > table, int row, int var) {
	int Difference = 0;
	for (int i = 0; i < row; i++) {
		if (table[i][var] == '1') {
			Difference -= 1;
		}
		else {
			Difference += 1;
		}
	}
	return Difference;
}

// Flipping
void FlipRow(vector<vector<char> >& table, int rowNum, vector<int>& row, vector<int>& column)
{
	for (int i = 0; i < column.size(); ++i)
	{
		if (table[rowNum][i] == '0')
		{
			table[rowNum][i] = '1';
			column[i] -= 2;
		}
		else
		{
			table[rowNum][i] = '0';
			column[i] += 2;
		}
	}
	row[rowNum] = -1 * row[rowNum];
}

void FlipColumn(vector<vector<char> >& table, int colNum, vector<int>& row, vector<int>& column)
{
	for (int i = 0; i < row.size(); ++i)
	{
		if (table[i][colNum] == '0')
		{
			table[i][colNum] = '1';
			row[i] -= 2;
		}
		else
		{
			table[i][colNum] = '0';
			row[i] += 2;
		}
	}
	column[colNum] = -1 * column[colNum];
}
// End New Code

int main() {
	//Initialise row and column
	int r;
	int c;
	while (cin >> r >> c) {
		//Initiallise 2D vector
		vector <vector<char> > table(r, vector<char>(c));

		//get each digit of number and store it into number
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> table[i][j];
			}
		}

		//Build two arrays to store the value "zero-one"
		vector <int> row;
		vector <int> column;

		//store for vector
		//For Row
		for (int i = 0; i < r; i++) {
			row.push_back(RcountDifference(table, c, i));
		}
		//For Column
		for (int j = 0; j < c; j++) {
			column.push_back(CcountDifference(table, r, j));
		}

		//New Code
		for (int j = 0; j < 2; ++j)
		{
			for (int i = 0; i < row.size(); ++i)
			{
				if ((row[i] == 0 && table[i][0] == '0') || row[i] > 0)
				{
					FlipRow(table, i, row, column);
				}
			}

			for (int i = 0; i < column.size(); ++i)
			{
				if ((column[i] == 0 && table[0][i] == '0') || column[i] > 0)
				{
					FlipColumn(table, i, row, column);
				}
			}
		}
		//Check 1
		int numCheck = 0;

		//Output Check
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (table[i][j] == '1') {
					numCheck++;
				}
			}
		}
		cout << numCheck << endl;
	}

	return 0;
}
