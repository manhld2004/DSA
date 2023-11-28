#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

struct Point
{
	double x, y;

	Point(int _x, int _y)
	{
		x = _x;
		y = _y;
	}

	Point()
	{
	}

	double getDis(Point o)
	{
		double p1 = o.x - x;
		double p2 = o.y - y;
		return sqrt(x*x + y*y);
	}
} nodePos[100003];

typedef pair<int,int> ii;
typedef pair<int, Point> node;
typedef pair<double, int> di;

int n;
double dis[100003];
vector<node> adj[100003];// pair < node , position >

void dijkstra(int source)
{
	memset(dis, 0x3f3f3f, sizeof dis);
	priority_queue<di, vector<di>, greater<di>> pq;// pair< value, node >

	dis[source] = 0;

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
			int alt = nodePos[u].getDis(ed.se);
			if(dis[u] + alt < dis[ed.fi])
			{
				dis[ed.fi] = dis[u] + alt;
				pq.push({dis[ed.fi], ed.fi});
			}
		}
	}
}

int main()
{


	return 0;
}