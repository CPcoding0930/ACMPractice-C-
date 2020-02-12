#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int fibo[5000000];
int temp[5000000];

const static int radix = 1024;
static int p[] = { 0,10,20,30 };

inline int getRadix(int n, int i)
{
	return n >> p[i] & (radix - 1); 
 }

inline void rsort(int n, int d)
{
	int count[radix];
	for (int i = 0; i < d; i++)
	{
		memset(count, 0, sizeof(int) * radix);
		for (int j = 1; j <= n; j++)
			count[getRadix(fibo[j], i)]++;  //count of that radix increase by 1
		for (int j = 1; j < radix; j++)
			count[j] += count[j - 1];  //Add up to buckets
		for (int j = n - 1; j >= 0; j--)
			temp[count[getRadix(fibo[j + 1], i)]--] = fibo[j + 1];  //Assign value in order
		memcpy(fibo, temp, sizeof(int)*(n + 1));
	}
}

int main()
{
	int t;
	cin >> t;
	while (t > 0)
	{
		fibo[0] = 0;
		fibo[1] = 1;
		t--;
		int n, q;
		int d = 1;
		cin >> n >> q;
    		if (q > 1023)	d++;
		if (q > 1024 * 1023 - 1)	d++;
		for (int i = 2; i <= n; i++)
			fibo[i] = (fibo[i - 1] + fibo[i - 2]) % q;
		rsort(n, d);
		long long res = 0;
		for (long long i = 1; i <= n; i++)
			res += ((i*fibo[i]) % q);
		res = res % q;
		cout << res << endl;
	}
	return 0;
}
