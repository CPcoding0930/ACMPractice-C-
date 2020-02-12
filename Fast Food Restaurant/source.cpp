#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	long long int customersNum;

	while (cin >> customersNum)
	{
		queue<long long int> currentQueue;
		long long int A, O, L;

		cin >> A >> O >> L;
		if (customersNum == 1)	{
			cout << A << endl;
			continue;
		}
		long long int previousServedTime = A;
		currentQueue.push(O);

		//Details of the other customers
		bool isPrint = false;
		for (long long int i = 1; i < customersNum; i++)
		{
			cin >> A >> O >> L;
			while (!currentQueue.empty() && A - previousServedTime >= currentQueue.front())	{
				previousServedTime += currentQueue.front();
				currentQueue.pop();
			}
			if (currentQueue.size() > L){			
				if (i == customersNum - 1)	{
					cout << -1 << endl;
					isPrint = true;
					break;
				}
				else {
					continue;
				}
			}
			if (currentQueue.empty()) {
				previousServedTime = A;
			}
			currentQueue.push(O);
		}

		if (isPrint) { continue; }

		while (currentQueue.size() != 1)
		{
			previousServedTime += currentQueue.front();
			currentQueue.pop();
		}
		cout << previousServedTime << endl;
	}
	return 0;
}
