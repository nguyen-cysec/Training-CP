#include <bits/stdc++.h>
#define MAXN 100001
#define oo 1000000000
#define plli pair<long long, int>
#define pii pair<int, int>
using namespace std;
using ll = long long;
using ull = unsigned long long;
int n, m;
void sol()
{
    cin >> n >> m;
    vector<vector<int>> g;
    int u, v;
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
    }
    int S, T; cin >> S >> T;
    ll dis[MAXN][3];
    for(int i = 1; i <= n; i++) for(int j = 0; j < 3; j++) dis[i][j] = oo;
    dis[S][0] = 0;
    queue<pii> q;
    q.push({S, 0});
    while(!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for(auto v: g[x])
        {
            if(dis[x][y] + 1 < dis[v][(y + 1) % 3])
            {
                dis[v][(y + 1) % 3] = dis[x][y] + 1;
                q.push({v, (y + 1) % 3});
            }
        }
    }
    cout << dis[T][0];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    sol();
}
