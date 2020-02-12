#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	int taskNum = 0;
	while (cin >> taskNum)
	{
	    queue <vector <int> > High;
    	queue <vector <int> > Low;
    	int*array = new int[taskNum]; //result
    	vector <int>  task;
		int timer = 0;
		for (int i = 0; i < taskNum; i++)
		{
			int R, W, P;
			cin >> R >> W >> P;
			task.push_back(R);
			task.push_back(W);
			task.push_back(i);
			if (P == 0)
			{
				High.push(task);
			}
			else
			{
				Low.push(task);
			}
			task.clear();
		}
		
	     while (timer != High.front().front() && timer != Low.front().front()) {
		       	timer ++;
	    	}
		while (!High.empty() || !Low.empty()) {
		   
			if (!High.empty() && timer >= High.front().front()) {
				timer += High.front().at(1);
				array[High.front().back()] = timer;
				High.pop();
			}
			else if (!Low.empty() && timer >= Low.front().front()) {
				timer += Low.front().at(1);
				array[Low.front().back()] = timer;
				Low.pop();
			}
			else {
				timer ++;
			}
		}
		
		for (int i = 0; i < taskNum; i++) {
		    if (i == 0 ){cout<<array[i];}
		    else {cout<<' '<<array[i];}
		}
		cout <<endl;
		
	}
	return 0;
}
