#include <bits/stdc++.h>
#define MAXN 501
#define pii pair<int, int>
#define fi first
#define se second
#define oo 1000000000
using namespace std;
using ll = long long;
using ull = unsigned long long;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int MOD = 1000000007;
int h, w;
bool in(int x, int y)
{
    return (0 <= x && x < h && 0 <= y && y < w);
}
void sol()
{
    cin >> h >> w;
    char a[MAXN][MAXN];
    string t;
    for(int i = 0; i < h; i++)
    {
        cin >> t;
        for(int j = 0; j < w; j++) a[i][j] = t[j];
    }
    deque<pii> q;
    q.push_back({0, 0});
    int cnt[MAXN][MAXN];
    for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) cnt[i][j] = oo;
    cnt[0][0] = 0;
    while(!q.empty())
    {
        pii tm = q.front();
        q.pop_front();
        int x = tm.fi, y = tm.se;
        for(int i = 0; i < 4; i++)
        {
            if(in(x + dx[i], y + dy[i]))
            {
                int cost = 0;
                if(a[x + dx[i]][y + dy[i]] == '#') cost = 1;
                if(cnt[x][y] + cost < cnt[x + dx[i]][y + dy[i]])
                {
                    cnt[x + dx[i]][y + dy[i]] = cnt[x][y] + cost;
                    if(cost) q.push_back({x + dx[i], y + dy[i]});
                    else q.push_front({x + dx[i], y + dy[i]});
                }
            }
        }
        for(int i = x - 2; i <= x + 2; i++)
        {
            for(int j = y - 2; j <= y + 2; j++)
            {
                if(in(i, j) && !(abs(i - x) == 2 && abs(j - y) == 2))
                {
                    if(cnt[x][y] + 1 < cnt[i][j])
                    {
                        cnt[i][j] = cnt[x][y] + 1;
                        q.push_back({i, j});
                    }
                }
            }
        }
    }
    // for(int i = 0; i < h; i++)
    // {
    //     for(int j = 0; j < w; j++) cout << cnt[i][j] << " ";
    //     cout << "\n";
    // }
    cout << cnt[h - 1][w - 1];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    sol();
}
