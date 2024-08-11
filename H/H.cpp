#include<bits/stdc++.h>
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
    ll n, m, a, c, x;
    cin >> n >> m >> a >> c >> x;
    a %= m;
    x %= m;
    c %= m;
    vector<ll> X(n + 1);
    X[0] = x;
    for (int i=1; i<=n; i++)
        X[i] = (X[i-1] * a % m + c) % m;

    int cnt = 0;
    for (int i=1; i<=n; i++) {
        int left = 1;
        int right = n;
        while(left <= right) {
            int mid = (left + right) / 2;
            if (X[mid] == X[i]) {
                cnt++;
                break;
            }
            if (X[mid] < X[i]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    cout << cnt;
}

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}