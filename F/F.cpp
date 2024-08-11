// By DThang
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz size()
#define ll long long
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define F(i, a, b) for (int i = a; i < b; ++i)
#define FD(i, a, b) for (int i = a; i > b; --i)
#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL);
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()

void solve()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    int n = n1 + n2 + n3;
    map<string, int> mp, vis;
    vector<string> a(n), b(n);
    F(i, 0, n1)
    {
        int x;
        cin >> a[i] >> x;
        mp[a[i]] += x;
        if (mp[a[i]] >= 20)
            vis[a[i]] = 1;
    }
    mp.clear();
    F(i, 0, n2)
    {
        int x;
        cin >> b[i] >> x;
        mp[b[i]] += x;
        if (mp[b[i]] >= 20 && vis[b[i]] == 1)
            vis[b[i]] = 2;
    }
    mp.clear();
    int ans = 0;
    F(i, 0, n3)
    {
        int x;
        cin >> b[i] >> x;
        mp[b[i]] += x;
        if (mp[b[i]] >= 20 && vis[b[i]] == 2)
        {
            vis[b[i]] = 3;
            ans++;
        }
    }
    cout << ans << " ";
    F(i, 0, n1)
    {
        if (vis[a[i]] == 3)
        {
            vis[a[i]] = 0;
            cout << a[i] << " ";
        }
    }
}

int main()
{
    faster();
    int t;
    // cin >> t;
    // while(t--)
    //{
    solve();
    //}
    return 0;
}