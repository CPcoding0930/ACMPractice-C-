#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct node {
	bool type;
	int weight;
};

int main()
{
	string input;
	stack <node> Node;
	int a[10000];
	while (cin >> input)
	{
		int count = 0;
		for (int i = 0; i < input.length(); i++)
		{
			char c = input.at(i);
			if (c == '(') {
				node N;
				N.type = 1;
				N.weight= i;
				Node.push(N);
			}
			if (c == ')') {
				a[count++] = ((i - Node.top().weight) / 2) + 1;
				Node.pop();
			}
		}

		for (int i = 1; i < count; i++)
			a[0] =  a[0]^ a[i];
		cout << a[0] << endl;
	}
}
