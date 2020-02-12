#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;

// Returns true if it is possible to arrange 
// k elements of arr[0..n-1] with minimum distance 
// given as mid. 
bool isFeasible(int mid, vector <int> rooms, int size, int C)
{
	// Place first element at arr[0] position 
	int pos = rooms.at(0);
	// Initialize count of elements placed. 
	int elements = 1;
	// Try placing k elements with minimum 
	// distance mid. 
	for (int i = 1; i < size; i++)
	{
		if (rooms[i] - pos >= mid)
		{
			// Place next element if its 
			// distance from the previously 
			// placed element is greater 
			// than current mid 
			pos = rooms[i];
			elements++;

			// Return if all elements are placed 
			// successfully 
			if (elements == C) { return true; }
		}
	}
	return 0;
}

// Returns largest minimum distance for k elements 
// in arr[0..n-1]. If elements can't be placed, 
// returns -1. 
int largestMinDist(vector <int> rooms, int size, int C)
{
	// Sort the positions 
	sort(rooms.begin(), rooms.end());

	// Initialize result. 
	int res = -1;
	// Consider the maximum possible distance 
	int left =rooms.at(0), right = rooms.at(size-1) ;

	// Do binary search for largest minimum distance 
	while (left < right)
	{
		int mid = (left + right) / 2;
		// If it is possible to place k elements with minimum distance mid, search for higher distance. 
		if (isFeasible(mid, rooms, rooms.size(), C))
		{
			// Change value of variable max to mid iff all elements can be successfully placed 
			res = max(res, mid);
			left = mid + 1;
		}
		// If not possible to place k elements, search for lower distance 
		else
		{
			right = mid;
		}
	}

	return res;
}

// Driver code 
int main()
{
	int testCase = 0;
	cin >> testCase;
	for (int i = 0; i < testCase; i++)
	{
		vector <int> rooms;
		int N = 0; //number of rooms
		int C = 0; //Minimum distance 
		cin >> N >> C;
		for (int j = 0; j < N; j++)
		{
			int R;
			cin >> R;
			rooms.push_back(R);
		}
		cout << largestMinDist(rooms, rooms.size(), C) <<endl;
		rooms.clear();
	}
	return 0;
}
