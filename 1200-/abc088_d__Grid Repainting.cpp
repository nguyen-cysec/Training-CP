#include <bits/stdc++.h>
#define MAXN 60
#define oo 1000000000
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
using ll = long long;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;
bool in(int x, int y)
{
    return ((0 <= x && x < n) && (0 <= y && y < m));
}
void sol()
{

    char a[MAXN][MAXN];
    string t;
    cin >> n >> m;
    int dt = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> t;
        for(int j = 0; j < m; j++)
        {
            a[i][j] = t[j];
            dt += (t[j] == '.');
        }
    }
    queue<pii> s;
    bool ok[MAXN][MAXN] = {0};
    int time = 0;
    s.push({0, 0});
    ok[0][0] = 1;
    int f = 0;
    while(!s.empty())
    {
        if(f) break;
        int tmp = (int)s.size();
        for(int j = 0; j < tmp; j++)
        {
            pii pi = s.front();
            int x = pi.fi, y = pi.se;
            for(int i = 0; i < 4; i++)
            {
                if(in(x + dx[i], y + dy[i]) && !ok[x + dx[i]][y + dy[i]] && a[x + dx[i]][y + dy[i]] == '.')
                {
                    ok[x + dx[i]][y + dy[i]] = 1;
                    s.push({x + dx[i], y + dy[i]});
                }
            }
            s.pop();
            if(ok[n - 1][m - 1])
            {
                f = 1;
                break;
            }
        }
        time++;
    }
    cout << (ok[n - 1][m - 1] ? dt - time - 1 : -1);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    sol();
}
