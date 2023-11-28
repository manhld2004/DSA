#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

struct edge
{
	int d;//trong so canh a b
	int a, b;
};

typedef pair<int, int> ii;

int n, dis[100003], dis2[100003];
bool check[100003];
vector<edge> listEdge;

bool cmp1(edge x, edge y)
{
	return x.d < y.d; 
}

bool cmp2(edge x, edge y)
{
	return x.d > y.d; 
}

void solve(int source)
{
	memset(dis, 0x3f, sizeof dis);
	memset(dis2, 0x3f, sizeof dis2);
	memset(check, 0, sizeof check);

	vector<edge> sameD;//luu va xu li cac canh chung trong so
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	dis[source] = 0;

	check[source] = 1;
	sort(listEdge.begin(), listEdge.end(), cmp1);
	for(int i = 0; i < listEdge.size(); i++)
	{
		edge ed = listEdge[i];
		sameD.push_back(ed);
		if(check[ed.a])
		{
			pq.push({dis[ed.a], ed.a});
		}

		if(i == listEdge.size() - 1 || listEdge[i++].d != listEdge[i].d)
		{
			while(!pq.empty())
			{
				int u = pq.top().se;
				int d = pq.top().fi;

				if(dis[u] != d) continue;

				for(auto edg : sameD)
				if(edg.a == u && dis[u] + edg.d < dis[edg.b])
				{
					check[edg.b] = 1;
					dis[edg.b] = dis[u] + edg.d;
					pq.push({dis[edg.b], edg.b});
				}
			}

			sameD.clear();
		}
	}

	memset(check, 0, sizeof check);
	check[source] = 1;
	sort(listEdge.begin(), listEdge.end(), cmp2);
	for(int i = 0; i < listEdge.size(); i++)
	{
		edge ed = listEdge[i];
		sameD.push_back(ed);
		if(check[ed.a])
		{
			pq.push({dis2[ed.a], ed.a});
		}

		if(i == listEdge.size() - 1 || listEdge[i++].d != listEdge[i].d)
		{
			while(!pq.empty())
			{
				int u = pq.top().se;
				int d = pq.top().fi;

				if(dis2[u] != d) continue;

				for(auto edg : sameD)
				if(edg.a == u && dis2[u] + edg.d < dis2[edg.b])
				{
					check[edg.b] = 1;
					dis2[edg.b] = dis2[u] + edg.d;
					pq.push({dis2[edg.b], edg.b});
				}
			}

			sameD.clear();
		}
	}

	for(int i = 1; i <= n; i++)
	{
		dis[i] = min(dis[i], dis2[i]);
	}
}

int main()
{

	return 0;
}