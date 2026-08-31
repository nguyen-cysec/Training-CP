#include <bits/stdc++.h>
#define MAXN 2010
#define oo 1000000000
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
using ll = long long;
void sol()
{
    int t, n, m;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        vector<vector<int>> g;
        g.resize(n + 10, vector<int>());
        int cl[MAXN];
        for(int i = 1; i <= n; i++) cin >> cl[i];
        int u, v;
        for(int i = 0; i < m; i++)
        {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int dis[MAXN][MAXN];
        for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) dis[i][j] = oo;
        dis[1][n] = 0;
        queue<pii> a;
        a.push({1, n});
        bool ok[MAXN][MAXN] = {0};
        ok[1][n] = 1;
        while(!a.empty())
        {
            pii t = a.front();
            a.pop();
            int u = t.fi, v = t.se;
            for(auto x: g[u]) for(auto y: g[v])
            {
                if(cl[x] != cl[y] && !ok[x][y])
                {
                    ok[x][y] = 1;
                    dis[x][y] = dis[u][v]+ 1;
                    a.push({x, y});
                }
            }
        }
        cout << (dis[n][1] == oo ? -1 : dis[n][1]) << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    sol();
}
