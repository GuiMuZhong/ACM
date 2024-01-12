#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 400 + 5;
const int maxm = 20000 + 5;
int n, m;
int head[maxn], to[maxm], front[maxm], flow[maxm], cost[maxm], ppp;
int dis[maxn], minflow[maxn];
bool flag[maxn];
pair<int, int> par[maxn];

struct MIN_COST_MAX_FLOW{

	void init() {
		memset(head, -1, sizeof(head));
		ppp = 0;
	}

	bool spfa(int s, int t)
	{
		int u, v;
		for(int i = 0; i <= t; i++)
			dis[i] = INF;
		memset(flag, 0, sizeof(flag));
		dis[s] = 0;
		minflow[s] = INF;
		queue <int> q;
		q.push(s);
		while(!q.empty())
		{
			u = q.front();
			q.pop();
			flag[u] = 0;
			for(int i = head[u]; ~i; i = front[i])
			{
				v = to[i];
				if(flow[i] && dis[v] > dis[u] + cost[i])
				{
					dis[v] = dis[u] + cost[i];
					par[v] = (make_pair(u, i));
					minflow[v] = min(minflow[u], flow[i]);
					if(!flag[v])
					{
						flag[v] = 1;
						q.push(v);
					}
				}
			}
		}
		if(dis[t] == INF)
			return 0;
		return 1;
	}

	int slove(int s, int t)
	{
		int ans = 0, p;
		while(spfa(s, t))
		{
			p = t;
			while(p != s)
			{
				flow[par[p].second] -= minflow[t];
				flow[par[p].second^1] += minflow[t];
				p = par[p].first;
			}
			ans += dis[t];
		}
		return ans;
	}

	void add_edge(int u, int v, int f, int c)
	{
		to[ppp] = v, front[ppp] = head[u], flow[ppp] = f, cost[ppp] = c, head[u] = ppp++;
		to[ppp] = u, front[ppp] = head[v], flow[ppp] = 0, cost[ppp] = -c, head[v] = ppp++;
	}
}mcmf;

int main()
{
	int u, v, f, c;
	memset(head, -1, sizeof(head));
	ppp = 0;
	cin >> n >> m;
	while(m--)
	{
		scanf("%d%d%d%d", &u, &v, &f, &c);
		mcmf.add_edge(u, v, f, c);
	}
	int ans = mcmf.slove(1, n);
	cout << ans << '\n';
	return 0;
}
