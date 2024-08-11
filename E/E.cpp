#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define vb vector<bool>
#define pib pair<int, bool>

const int INF = 1e9 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;
    if (n < k)
        swap(n, k);
    ll res = 0;
    if (k == 0)
    {
        cout << (ll)n * n;
        return;
    }
    for (int i = k + 1; i <= n; i++)
    {
        res += (ll)n / i * (i - k);
        // cout << res << ' ';
        if (n % i >= k)
            res += (ll)(n % i - k + 1);
        // cout << res << '\n';
    }
    cout << res;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}