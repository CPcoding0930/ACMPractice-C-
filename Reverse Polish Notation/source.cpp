#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int main() {
	//setup stack
	stack <int> s;
	//setup string to store the operation
	string operation;
	
	while (getline(cin, operation)) {
		for (int i = 0; i <= operation.size();i+=2) {
			if (operation.at(i) >= '0' && operation.at(i) <= '9') {
				int num = operation.at(i) -48;
				s.push(num);
			}
			else if (operation.at(i) == '+') {
				int num1 = s.top();
				s.pop();
				int num2 = s.top();
				s.pop();
				s.push(num1 + num2);
			}
			else if (operation.at(i) == '*') {
				int num1 = s.top();
				s.pop();
				int num2 = s.top();
				s.pop();
				s.push(num1 * num2);
			}
			else if (operation.at(i) == '-') {
				int num1 = s.top();
				s.pop();
				int num2 = s.top();
				s.pop();
				s.push(num2 - num1);
			}
		}
		cout << s.top() << endl;
	}

	return 0;
}
