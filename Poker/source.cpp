# include <iostream>
# include <stack>
# include <string>
using namespace std;

//Function to find the maximum value
void maximum(stack <int>  S)
{
	int maxNum = S.top();
	while (!S.empty())
	{
		if (S.top() > maxNum)
		{
			maxNum = S.top();
			S.pop();
		}
		else
		{
			S.pop();
		}
	}
	cout << maxNum <<endl;
}

int main()
{
	int caseNum = 0;
	cin >> caseNum;
	for (int i = 0; i < caseNum; i++)
	{
		int M; //number of operations
		int N; //number of card
		cin >> N; 
		stack <int> card; //Store the card
		for (int j = 0; j < N; j++)
		{
			int cardvalue;
			cin >> cardvalue;
			card.push(cardvalue);
		}
		//Operation start
		cin >> M;
		for (int j = 0; j < M; j++)
		{
			string operation;
			operation.clear();
			cin >> operation;
			//m stands for output the maximum value 
			if (operation.at(0) == 'm')
			{
				maximum(card);
			} // r stands for removing the top
			else if (operation.at(0) == 'r') 
			{
				card.pop();
			} //a stands for adding
			else if (operation.at(0) == 'a') 
			{
				int AddingValue;
				cin >> AddingValue;
				card.push(AddingValue);
			}
		}
	}
	return 0;
}
