#include <bits/stdc++.h>
#define MAXN 500001
#define oo 1000000000
#define plli pair<long long, int>
#define pii pair<int, int>
using namespace std;
using ll = long long;
using ull = unsigned long long;
int n;
bool st[4 * MAXN];
bool ok[MAXN];
void build(int l, int r, int id)
{
    if(l == r)
    {
        st[id] = ok[l];
        return;
    }
    else
    {
        int mid = (l + r) >> 1;
        build(l, mid, id * 2); build(mid + 1, r, id * 2 + 1);
        st[id] = max(st[id * 2], st[id * 2 + 1]);
    }
}
void update(int l, int r, int id, int u, bool val)
{
    if(r < u || l > u) return;
    if(l == r && r == u)
    {
        st[id] == val;
        return;
    }
    int mid = (l + r ) >> 1;
    update(l, mid, id * 2, u, val);
    update(mid + 1, r, id * 2 + 1, u, val);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
    return;
}
bool get(int l, int r, int id, int u, int v)
{
    if(l > v || r < u) return 0;
    else if(u <= l && r <= v) return st[id];
    int mid = (l + r) >> 1;
    return max(get(l, mid, id * 2, u, v), get(mid + 1, r, id * 2 + 1, u, v));
}
void sol()
{
    cin >> n;
    string s; cin >> s;
    for(int i = 1; i < n; i++)
    {
        if(s[i] == s[i - 1] && s[i] == 'B') ok[i] = 1;
    }
    build(0, n - 1, 1);
    int q; cin >> q;
    int opt, l, r, i;
    char c;
    while(q--)
    {
        cin >> opt;
        if(opt == 1)
        {
            cin >> i >> c;
            i--;
            s[i] = c;
            if(c == 'B')
            {
                if(i) update(0, n - 1, 1, i, s[i - 1] == 'B');
                if(i < n - 1) update(0, n - 1, 1, i + 1, s[i + 1] == 'B');
            }
            else
            {
                if(i) update(0, n - 1, 1, i, 0);
                if(i < n - 1) update(0, n - 1, 1, i + 1, 0);
            }
        }
        else
        {
            cin >> l >> r;
            cout << (get(0, n - 1, 1, l - 1, r - 1) ? "Yes" : "No") << "\n";
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    sol();
}
