#include <queue>
#include <iostream>
#include <string>
using namespace std;

char largest(string s) {
	char c = 'a';
	for (int i = 0; i < s.length(); i++) {
		if (s.at(i) > c) {
			c = s.at(i);
		}
	}
	return c;
}

string eraseStr(string s, char c) {
	for (int i = 0; i < s.length(); i++) {
		if (c == s.at(i)) {
			s = s.substr(i + 1, s.length());
			return s;
		}
	}

}

string out(string s, char c) {
	if (s.size() == 1 || s.size()== 0) {
		return s;
	}
	else {
		string str = eraseStr(s, largest(s));
		cout << largest(s);
		return out( str, largest(str));
	}
}

int main() {
	int numCase;
	cin >> numCase;
	vector<string> s(numCase);
	for (int i = 0; i < numCase; i++) {
		cin >> s[i];
		cout<<out(s[i], largest(s[i]))<<endl;
	}                                     
	return 0;
}
