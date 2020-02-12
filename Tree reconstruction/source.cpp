#include <iostream>
#include <string>
using namespace std;

string brain(int inorder[], int preorder[], int depth)
{
	string str;
	int i;
	for ( i = 0; i < depth; i++) {
		if (inorder[i] == preorder[0])	break;
	}
	if (i != 0) { str += brain(inorder, preorder + 1, i); }
	if (i != depth - 1) { str += brain(inorder + i + 1, preorder + i + 1, depth - i - 1); }
	return str + to_string(preorder[0]) + " ";
}

int main() {
	int numCase;
	cin >> numCase;
	while (numCase-- > 0) {
		int Num;
		cin >> Num;
		int inorder[100], preorder[100];
		for (int i = 0; i < Num; i++) {
			cin >> preorder[i];
		}
		for (int j = 0; j < Num; j++) {
			cin >> inorder[j];
		}
		string output = brain(inorder, preorder, Num);
		for (int i = 0; i < output.length() - 1; i++) {
			cout << output.at(i);
		}
		cout << endl;
	}
	return 0;
}
