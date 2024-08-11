#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define vb vector<bool>
#define pib pair<int, bool>

const int INF = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vi a(n + 1), b(n + 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    a[n] = a[0]; // Making the array circular
    for (int i = 0; i < n; i++)
        cin >> b[i];
    b[n] = b[0]; // Making the array circular

    vi aa(n), bb(n);
    for (int i = 0; i < n; i++)
    {
        aa[i] = (a[i] ^ a[i + 1]);
        bb[i] = (b[i] ^ b[i + 1]);
    }

    vi res;
    int k = 0;
    while (k < n)
    {
        while (k < n && aa[k] != bb[0])
            k++;
        if (k == n)
            break;

        bool check = true;
        for (int i = 0; i < n; i++)
        {
            if (bb[i] != aa[(i + k) % n])
            {
                check = false;
                break;
            }
        }
        if (check)
            res.push_back(k);

        if (res.size() >= 2)
            break;

        k++;
    }

    if (res.size() == 0)
        return;

    if (res.size() == 1)
    {
        cout << res[0] << ' ' << (a[res[0]] ^ b[0]) << '\n';
    }
    else if (res.size() == 2)
    {
        int ans = res[0];
        while (ans < n)
        {
            cout << ans << ' ' << (a[ans] ^ b[0]) << '\n';
            ans += (res[1] - res[0]);
        }
    }
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
