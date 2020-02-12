#include <iostream>
#include <vector>
#include <stack>
using namespace std;

long long int getMaxArea(vector <long long int> hist, int n)
{
	stack<int> s;
	long long int max_area =0; // Initialize max area 
	long long int tp;  // To store top of stack 
	long long int area_with_top; // To store area with top bar as the smallest bar 

	// Run through all bars of given histogram 
	int i = 0;
	while (i < n)
	{
		if (s.empty() || hist[s.top()] <= hist[i]) {
			s.push(i++);
		}
		else
		{
			tp = s.top();  // store the top index 
			s.pop();  // pop the top 
			area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
			if (max_area < area_with_top) {
				max_area = area_with_top;
			}
		}
	}

	// Now pop the remaining bars from stack and calculate 
	// area with every popped bar as the smallest bar 
	while (s.empty() == false)
	{
		tp = s.top();
		s.pop();
		area_with_top = hist[tp] * (s.empty() ? i :	i - s.top() - 1);

		if (max_area < area_with_top) {
			max_area = area_with_top;
		}
	}
	return max_area;
}

int main()
{
	int testCase = 0;
	cin >> testCase;
	for (int i = 0; i < testCase; i++)
	{
		vector < long long int> hist;
		int num = 0;
		cin >> num;
		for (int j = 0; j < num; j++)
		{
			int S;
			cin >> S;
			hist.push_back(S);			
		}
		cout << getMaxArea(hist, hist.size()) <<endl;
		hist.clear();
	}
	return 0;
}
