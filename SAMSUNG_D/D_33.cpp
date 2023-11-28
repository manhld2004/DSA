#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

struct cell
{
	int x, y;

	cell()
	{

	}

	cell(ii r)
	{
		x = r.fi;
		y = r.se;
	}
};

int n, dis[1000][1000], val[1000][1000];
ii moveV[] = {ii(0,1),ii(0,-1),ii(1,0),ii(-1,0)};
ii newMove[] = {ii(0,1), ii(1,0)};

bool validate(cell cur)
{
	if(cur.x < 0 || cur.x >= n || cur.y < 0 || cur.y <= n) return false;

	return true;
}

void dijkstra(cell source)
{
	memset(dis, 0x3f3f3f, sizeof dis);
	priority_queue<iii, vector<iii>, greater<iii>> pq;// pair< value, node >

	dis[source.x][source.y] = 0;

	pq.push({0, {source.x, source.y}});

	while(!pq.empty())
	{
		cell u = cell(pq.top().se);
		int d = pq.top().fi;

		pq.pop();

		if(d != dis[u.x][u.y])
			continue;

		for(int i = 0; i < 4; i++)
		{
			ii ed = moveV[i];
			cell v = u;
			v.x += ed.fi;
			v.y += ed.se;
			
			if(!validate(v)) continue;

			if(dis[u.x][u.y] + val[v.x][v.y] < dis[v.x][v.y])
			{
				dis[v.x][v.y] = dis[u.x][u.y] + val[v.x][v.y];
				pq.push({dis[v.x][v.y], {v.x, v.y}});
			}
		}
	}
}

void dijkstraAlter(cell source)
{
	memset(dis, 0x3f3f3f, sizeof dis);
	priority_queue<iii, vector<iii>, greater<iii>> pq;// pair< value, node >

	dis[source.x][source.y] = 0;

	pq.push({0, {source.x, source.y}});

	while(!pq.empty())
	{
		cell u = cell(pq.top().se);
		int d = pq.top().fi;

		pq.pop();

		if(d != dis[u.x][u.y])
			continue;

		for(int i = 0; i < 4; i++)
		{
			ii ed = newMove[i];
			cell v = u;
			v.x += ed.fi;
			v.y += ed.se;
			
			if(!validate(v)) continue;

			if(dis[u.x][u.y] + val[v.x][v.y] < dis[v.x][v.y])
			{
				dis[v.x][v.y] = dis[u.x][u.y] + val[v.x][v.y];
				pq.push({dis[v.x][v.y], {v.x, v.y}});
			}
		}
	}
}

int main()
{

	return 0;
}