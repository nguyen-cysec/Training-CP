#include <bits/stdc++.h>
#define MAXN 500001
#define oo 1000000000
#define plli pair<long long, int>
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
using ll = long long;
using ull = unsigned long long;
struct Node
{
    int sum;
    int min_pref;
};
Node st[4 * MAXN];
int n, q;
string s;
Node merge(Node left, Node right)
{
    Node res;
    res.sum = left.sum + right.sum;
    res.min_pref = min(left.min_pref, left.sum + right.min_pref);
    return res;
}
void build(int id, int l, int r)
{
    if(l == r)
    {
        if(s[l] == 'A') st[id] = {1, 1};
        else st[id] = {-1, -1};
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = merge(st[id * 2], st[id * 2 + 1]);
}

void update(int id, int l, int r, int pos, char c)
{
    if(l == r)
    {
        if(c == 'A') st[id] = {1, 1};
        else st[id] = {-1, -1};
        return;
    }
    int mid = (l + r) / 2;
    if(pos <= mid) update(id * 2, l, mid, pos, c);
    else update(id * 2 + 1, mid + 1, r, pos, c);
    st[id] = merge(st[id * 2], st[id * 2 + 1]);
}
Node get(int id, int l, int r, int u, int v)
{
    if(v < l || r < u) return {0, oo};
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    Node left = get(id * 2, l, mid, u, v);
    Node right = get(id * 2 + 1, mid + 1, r, u, v);
    if(left.min_pref == oo) return right;
    if(right.min_pref == oo) return left;
    return merge(left, right);
}
void sol()
{
    cin >> n >> s >> q;
    build(1, 0, n - 1);
    while(q--)
    {
        int type;
        cin >> type;
        if(type == 1)
        {
            int i;
            char c;
            cin >> i >> c;
            update(1, 0, n - 1, i - 1, c);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            Node res = get(1, 0, n - 1, l - 1, r - 1);
            cout << (res.min_pref >= 0 ? "Yes" : "No") << "\n";
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    sol();
    return 0;
}
