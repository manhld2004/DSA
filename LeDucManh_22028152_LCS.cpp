#include <bits/stdc++.h>
using namespace std;

string a, b;
int f[1000][1000];

int main()
{
	cin >> a >> b;
	a = " " + a;
	b = " " + b;

	cout << a.size() << endl;

	for (int i = 1; i < a.size(); ++i)
	{
		for (int j = 1; j < b.size(); ++j)
		{
			f[i][j] = max(f[i-1][j], f[i][j-1]);

			if(a[i] == b[j])
			{
				f[i][j] = max(f[i][j], f[i-1][j-1] + 1);
			}
		}
	}

	cout << f[a.size() - 1][b.size() - 1];
	return 0;
}