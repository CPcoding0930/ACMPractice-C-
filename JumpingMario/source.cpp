#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int main() {
	int Ncase;
	cin >> Ncase;

	//Initialise a 2D vector named wall
	vector <vector <int>> wall(Ncase);
	for (int i = 0; i < Ncase;i++) {
		int wallnum;
		cin >> wallnum;
		wall[i] = vector<int>(wallnum);

		int height;
		for (int j = 0; j < wallnum; j++) {
			cin >> height;
			wall[i][j] = height;
		}
	}

	for (int i = 0; i < Ncase;i++) {
		

		int high = 0;
		int low = 0;
		for (int j = 0; j < wall[i].size() -1 ; j++) {
			if (wall[i][j] < wall[i][j + 1]) { high++; }
			else if (wall[i][j] > wall[i][j + 1]) { low++; }
		}

	cout << "Case " << i + 1 << ": "<< high << " " << low << endl;
	}

	return 0;
}
