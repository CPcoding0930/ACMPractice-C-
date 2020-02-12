#include <iostream>
using namespace std;

struct Node {
	int val;
	Node* next;
	Node(int x) : val(x), next(NULL) {}
};

class LinkedList
{
public:
	Node* dummyhead;
	Node* reference;

	int length;

	LinkedList()
	{
		dummyhead = new Node(NULL);
	}

	void addAtIndex(int index, int val)
	{
		Node* cur = reference;
		Node* add = new Node(val);

		for (int i = 0; i < index - 1; i++)
		{
			cur = cur->next;
		}
		add->next = cur->next;
		cur->next = add;
		reference = add;
	}

	void removeIndex(int index)
	{
		Node* cur = reference;

		for (int i = 0; i < index - 2; i++)
		{
			cur = cur->next;
		}
		cur->next = cur->next->next;
		reference = cur->next;
	}

	void printIndex(int index)
	{
		Node* cur = reference;
		for (int i = 0; i < index - 1; i++)
		{
			cur = cur->next;
		}
		reference = cur;
		cout << cur->val << endl;
	}

};

int main()
{
	int stuNum;
	cin >> stuNum;
	LinkedList* circle = new LinkedList();
	Node* cur = circle->dummyhead;

	for (int i = 0; i < stuNum; i++)
	{
		int value;
		cin >> value;
		Node* add = new Node(value);
		if (cur->next == NULL)
		{
			circle->dummyhead->next = add;
			add->next = add;
			cur = cur->next;
			circle->reference = add;
		}
		else
		{
			circle->addAtIndex(i, value);
			circle->reference = circle->dummyhead->next;
		}
	}
	circle->reference = circle->dummyhead->next;

	int operationNum;
	cin >> operationNum;
	for (int i = 0; i < operationNum; i++)
	{
		int operation, pos;
		cin >> operation >> pos;

		if (operation == 1)
		{
			int val;
			cin >> val;
			circle->addAtIndex(pos, val);
		}
		else if (operation == 2)
		{
			circle->removeIndex(pos);
		}
		else if (operation == 3)
		{
			circle->printIndex(pos);
		}
	}
	return 0;
}
