#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int CaseNum;
	cin >> CaseNum;

	for (int i = 0; i < CaseNum; i++)
	{
		int N, K;
		long long int magicnum;
		vector<pair<long long int, int>> sequence;

		cin >> N >> K;
		for (int j = 0; j < N; j++)
		{
			cin >> magicnum;
			sequence.push_back(make_pair(magicnum, j));
		}

		vector<pair<long long int, int>> temp;
		while (!sequence.empty() && sequence.size() != 1){
			for (int j = 0; j < K && !sequence.empty(); j++)
			{
				temp.push_back(sequence.at(0));
				sequence.erase(sequence.begin());
			}

			pair<long long int, int> maxPair = make_pair(temp.at(0).first, temp.at(0).second);
			for (int j = 1; j < temp.size(); j++)
				if (temp.at(j).first > maxPair.first)
					maxPair = make_pair(temp.at(j).first, temp.at(j).second);

			cout << maxPair.second + 1 << " ";
			temp.erase(remove(temp.begin(), temp.end(), maxPair), temp.end());

			for (int j = 0; j < temp.size(); j++)
				temp.at(j).first--;

			for (int j = temp.size() - 1; j >= 0; j--)
			{
				sequence.push_back(temp.at(0));
				temp.erase(temp.begin());
			}
		}
		cout << sequence.front().second + 1 << endl;
	}

	return 0;
}
