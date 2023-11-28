#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef pair<int,int> ii;

int n, dis[100003];
vector<ii> adj[100003];// pair < node , value >
set<int> S, T;

void dijkstra(set<int> source)
{
	memset(dis, 0x3f3f3f, sizeof dis);
	priority_queue<ii, vector<ii>, greater<ii>> pq;// pair< value, node >

	for(auto src : source)
	{
		adj[0].push_back({src, 0});
	}
	dis[0] = 0;

	pq.push({0, 0});

	while(!pq.empty())
	{
		int u = pq.top().se;
		int d = pq.top().fi;

		pq.pop();

		if(d != dis[u])
			continue;

		for(auto ed : adj[u])
		{
			if(dis[u] + ed.se < dis[ed.fi])
			{
				dis[ed.fi] = dis[u] + ed.se;
				pq.push({dis[ed.fi], ed.fi});
			}
		}
	}
}

void printShortestDistance()
{
	int mn = 0x3f3f3f;
	for(auto node : T)
	{
		mn = min(mn, dis[node]);
	}

	cout << mn;
}

int main()
{


	return 0;
}