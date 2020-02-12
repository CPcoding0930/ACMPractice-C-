#include <iostream>
using namespace std;

int mypow(int a, int b)
{
	int pow = 1;
	for (int m = 0; m < b; m++)
	{
		pow *= a;
	}
	return pow;
}

int checkMaze(int **maze, int k, int endx, int endy, int &res)
{
	if (k == 1)
	{
		if (maze[endx][endy] == maze[endx - 1][endy] && maze[endx][endy] == maze[endx][endy - 1] && maze[endx][endy] == maze[endx - 1][endy - 1] && maze[endx][endy] == 0)
		{
			return 0;
		}
		else if (maze[endx][endy] == maze[endx - 1][endy] && maze[endx][endy] == maze[endx][endy - 1] && maze[endx][endy] == maze[endx - 1][endy - 1] && maze[endx][endy] == 1)
		{
			return 1;
		}
		else
		{
			res += 4;
			return 4;
		}
	}
	else
	{
		int a = checkMaze(maze, k - 1, endx - mypow(2, k - 1), endy - mypow(2, k - 1), res);
		int b = checkMaze(maze, k - 1, endx, endy, res);
		int c = checkMaze(maze, k - 1, endx - mypow(2, k - 1), endy, res);
		int d = checkMaze(maze, k - 1, endx, endy - mypow(2, k - 1), res);
		if (a == b && b == c && c == d && a == 0)
		{
			return 0;
		}
		else if (a == b && b == c && c == d && a == 1)
		{
			return 1;
		}
		else
		{
			res += 4;
			return 4;
		}
	}
}

int main()
{
	int k;
	int n;
	while (cin >> k)
	{
		if (k == 0)
		{
			cin >> n;
			cout << 1 << endl;
		}
		else {
			n = mypow(2, k);
			char **table = new char*[n];
			for (int i = 0; i < n; i++)
			{
				table[i] = new char[n];
			}
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					cin >> table[i][j];
				}
			}
			int **maze = new int*[n];
			for (int i = 0; i < n; i++)
			{
				maze[i] = new int[n];
			}
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					maze[i][j] = table[i][j] - '0';
				}
			}
			delete[]table;
			int num = 1;
			checkMaze(maze, k, n - 1, n - 1, num);
			cout << num << endl;
			delete[]maze;
		}
	}
	return 0;
}
