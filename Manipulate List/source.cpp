#include <iostream>
#include <list>
using namespace std;

void reverse(std::list <int>::iterator first, std::list <int>::iterator last)
{
	while ((first != last) && (first != --last)) {
		std::iter_swap(first++, last);
	}
}

int main() {
	//Create variable states the number of member in the list
	int number;
	cin >> number;

	//Create the list "list"
	list <int> list;
	
	//Input the member value
	for (int i = 0; i < number; i++) {
		int value;
		cin >> value;
		list.push_back(value); 
	}

	//Set the number of case
	int caseNum;
	cin >> caseNum;

	//Set instruction
	int instruction;
	for (int i = 0; i < caseNum; i++) {
		cin >> instruction;
		if (instruction == 1) {
			int pos = 0; 
			int val = 0;
			cin >> pos >> val;
			std::list <int>::iterator it = list.begin();
			advance(it, pos);
			list.insert(it, val);
		}
		else if (instruction == 2) {
			int dpos = 0;
			cin >> dpos;
			std::list <int>::iterator it1 = list.begin();
			advance(it1, dpos-1);
			list.erase(it1);
		}
		else if (instruction == 3) {
			int rfirst = 0; 
			int rlast = 0;
			cin >> rfirst >> rlast;
			std::list <int>::iterator start = list.begin();
			std::list <int>::iterator end = list.begin();
			advance(start, rfirst-1);
			advance(end, rlast);
			reverse(start, end);
		}
		else if (instruction == 4) {
			int p;
			cin >> p;
			std::list <int>::iterator it4 = list.begin();
			advance(it4, p-1);
			cout << *it4 << endl;
		}
	}
	return 0;
}
