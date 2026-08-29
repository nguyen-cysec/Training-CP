#include <bits/stdc++.h>
#define MAXN 200030

using namespace std;
using ll = long long;

void sol()
{
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    // first[j] = bước đầu tiên mà ta đứng ở vị trí j
    vector<ll> first(n, -1);

    // prefix[i] = tổng sau i bước
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

    // Vị trí j đã xuất hiện trước đó
    ll cycleStart = first[j];
    ll cycleEnd = step;

    ll cycleLen = cycleEnd - cycleStart;
    ll cycleSum = prefix[cycleEnd] - prefix[cycleStart];

    // Nếu k nằm hoàn toàn trước chu kỳ
    if(k <= cycleStart)
    {
        cout << prefix[k];
        return;
    }

    ll ans = prefix[cycleStart];

    k -= cycleStart;

    // Số chu kỳ đầy đủ
    ans += (k / cycleLen) * cycleSum;

    // Phần dư
    ans += prefix[cycleStart + (k % cycleLen)]
           - prefix[cycleStart];

    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sol();
}
