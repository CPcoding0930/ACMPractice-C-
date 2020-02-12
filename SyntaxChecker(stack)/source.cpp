#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string str;
	while (getline(cin, str)){
		vector <pair<char, long int> >result;
		vector <pair<char, long int> >other;
		for ( long int i = 0; i < str.size(); i++)	{
			if (str.at(i) == '{' || str.at(i) == '(' || str.at(i) == '[') {
				result.push_back(make_pair(str.at(i), i));
			}
			else if (str.at(i) == '}')	{
				if (result.back().first == '{')
					result.pop_back();
				else	{
					other.push_back(make_pair(str.at(i), i));
					break;
				}
			}
			else if (str.at(i) == ')'){
				if (result.back().first == '(')
					result.pop_back();
				else	{
					other.push_back(make_pair(str.at(i), i));
					break;
				}
			}
			else if (str.at(i) == ']'){
				if (result.back().first == '[')
					result.pop_back();
				else	{
					other.push_back(make_pair(str.at(i), i));
					break;
				}
			}
		}

		if (!other.empty())
			cout << other.front().second + 1 << endl;
		else if (!result.empty())
			cout << result.front().second + 1 << endl;
		else
			cout << "Success" << endl;
	}

	return 0;
}
