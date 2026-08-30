#include <bits/stdc++.h>
#define MAXN 200030
using namespace std;
using ll = long long;
void sol()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<ll> first(n, -1);
    vector<ll> prefix;
    prefix.push_back(0);
    ll j = 0;
    ll step = 0;
    while(first[j] == -1)
    {
        first[j] = step;
        prefix.push_back(prefix.back() + a[j]);
        j = (j + a[j]) % n;
        step++;
    }
    ll cycleStart = first[j];
    ll cycleEnd = step;
    ll cycleLen = cycleEnd - cycleStart;
    ll cycleSum = prefix[cycleEnd] - prefix[cycleStart];
    if(k <= cycleStart)
    {
        cout << prefix[k];
        return;
    }
    ll ans = prefix[cycleStart];

    k -= cycleStart;
    ans += (k / cycleLen) * cycleSum;
    ans += prefix[cycleStart + (k % cycleLen)] - prefix[cycleStart];
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    sol();
}
