#include <bits/stdc++.h>
#define MAXN 1001
#define oo 1000000000
#define plli pair<long long, int>
#define pii pair<int, int>
using namespace std;
using ll = long long;
using ull = unsigned long long;
int n, m;
bool in(int x, int y)
{
    return (0 <= x && x < n && 0 <= y && y < m);
}
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
void sol()
{
    char s[MAXN][MAXN];
    int rank[MAXN][MAXN] = {0};
    bool ok[MAXN][MAXN] = {0};
    cin >> n >> m;
    string t;
    for(int i = 0; i < n; i++)
    {
        cin >> t;
        for(int j = 0; j < m; j++) s[i][j] = t[j];
    }
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
    {
        if(s[i][j] == '#')
        {
            ok[i][j] = 1;
            continue;
        }
        for(int k = 0; k <= 3; k++)
        {
            if(in(i + dx[k], j + dy[k]) && s[i + dx[k]][j + dy[k]] == '#') rank[i][j] = 1;
        }
        if(!rank[i][j]) rank[i][j] = 2;
    }
    int mx = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!ok[i][j])
            {
                if(rank[i][j] == 2)
                {
                    int cnt = 1;
                    queue<pii> q;
                    vector<pii> vt;
                    q.push({i, j});
                    ok[i][j] = 1;
                    while(!q.empty())
                    {
                        auto [x, y] = q.front();
                        q.pop();
                        if(rank[x][y] == 1) continue;
                        for(int k = 0; k <= 3; k++)
                        {
                            if(in(x + dx[k], y + dy[k]) && !ok[x + dx[k]][y + dy[k]])
                            {
                                cnt++;
                                q.push({x + dx[k], y + dy[k]});
                                ok[x + dx[k]][y + dy[k]] = 1;
                                if(rank[x + dx[k]][y + dy[k]] == 1) vt.push_back({x + dx[k], y + dy[k]});
                            }
                        }

                    }
                    for(auto[u, v]: vt)
                    {ok[u][v] = 0;}
                    mx = max(mx, cnt);
                }
                else mx = max(mx, 1);
            }
        }
    }
    cout << mx;
}
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    sol();
}
