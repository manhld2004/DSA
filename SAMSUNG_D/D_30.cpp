#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef pair<int,int> ii;

int n, dis[100003];
vector<ii> adj[100003];// pair < node , value >

void dijkstra(int source)
{
	memset(dis, 0, sizeof dis);
	priority_queue<ii> pq;// pair< value, node >

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
			if(dis[u] + ed.se > dis[ed.fi])
			{
				dis[ed.fi] = dis[u] + ed.se;
				pq.push({dis[ed.fi], ed.fi});
			}
		}
	}
}

int main()
{


	return 0;
}