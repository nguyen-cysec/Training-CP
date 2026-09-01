#include <bits/stdc++.h>
#define MAXN 2001
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
    vector<vector<pii>> s(n + 10, vector<pii>());
    int u, v, w;
    ll mindis[MAXN][MAXN];
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) mindis[i][j] = oo;
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        s[u].push_back({v, w});
    }
    for(int i = 1; i <= n; i++)
    {
        priority_queue<plli, vector<plli>, greater<plli>> pq;
        pq.push({0, i});
        while(!pq.empty())
        {
            auto [mi, o] = pq.top();
            //cout << mi << " " << o << "\n";
            pq.pop();
            for(auto [x, y]: s[o])
            {
                if(!mindis[i][x] || mi + y < mindis[i][x])
                {
                    mindis[i][x] = mi + y;
                    pq.push({mindis[i][x], x});
                }
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        ll mi = oo;
        for(int j = 1; j <= n; j++)
        {
            if(i != j) mi = min(mi, mindis[i][j] + mindis[j][i]);
            else mi = min(mi, mindis[i][j]);
        }
        cout << (!mi || mi >= oo ? -1 : mi) << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    sol();
}
