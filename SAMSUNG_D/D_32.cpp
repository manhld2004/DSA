#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef pair<int, int> ii;

int n;
vector<ii> adj[100003];
int dis[100003];

void solve(int cur, int pre)
{
	for(auto next : adj[cur])
	if(next.fi != cur)
	{
		dis[next.fi] = dis[cur] + next.se;
		solve(next.fi, cur);
	}
}

int findShortestPath(int a, int b)
{
	return abs(dis[a] - dis[b]);
}

int main()
{
	return 0;
}