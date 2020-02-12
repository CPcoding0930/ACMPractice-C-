#include <iostream>
#include <stack>
#include <vector>
using namespace std; 
int main() 
{
	int testcase ;
	cin >> testcase;
		for (int i = 0; i < testcase; i++)
		{
			stack <int> Acopy;
			stack <int> A;
			stack <int> B;
			stack <int> S;
			stack <int> Bfinal;
			//Step 1: A stack
			int Astacksize;
			cin >> Astacksize;
			for (int j = 0; j < Astacksize; j++)
			{
				int Anum;
				cin >> Anum;
				Acopy.push(Anum);
			}
			//Step 2: Permutation of expected B stack
			int PermutationNum;
			cin >> PermutationNum;
			for (int j = 0; j < PermutationNum; j++)
			{
				//clear B stack
				while (!B.empty())
				{
					B.pop();
				}
				//clear S stack
				while (!S.empty())
				{
					S.pop();
				}
				//clear A stack
				while (!A.empty())
				{
					A.pop();
				}
				A = Acopy;
				for (int k = 0; k < Astacksize; k++)
				{
					int perm;
					cin >> perm;
					Bfinal.push(perm);
				}

				//Enter from the Bfinal to Bstack
				while (!Bfinal.empty())
				{
					B.push(Bfinal.top());
					Bfinal.pop();
				}
				//Implement the 2 Movements stated
				while (!A.empty() || (!S.empty() && S.top() == B.top()))
				{
					//1. Top of A  equals to Top of B
					if (!A.empty() && A.top() == B.top())
					{
						A.pop();
						B.pop();
					}//2. Top of A  equals to Top of B
					else if (!S.empty() && S.top() == B.top())
					{
						S.pop();
						B.pop();
					}//Other A.top()!=B.top && S.top()!=B.top()
					else
					{
						S.push(A.top());
						A.pop();
					}
				}

				if (A.empty() && B.empty())
				{
					cout << "Aye" << endl;
				}
				else
				{
					cout << "Impossible" << endl;
				}

			}
		
	
		}
		return 0;
}
