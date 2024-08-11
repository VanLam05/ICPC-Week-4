// https://codeforces.com/contest/1776/problem/L
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int, int>
#define pcc pair<char, char>
#define fi first
#define se second

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cntMin = 0, cntAdd = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '+')
            cntAdd++;
        else
            cntMin++;
    }

    int tot = cntAdd - cntMin;
    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (!tot)
        {
            cout << "YES\n";
            continue;
        }
        if (a == b)
        {
            cout << "NO\n";
            continue;
        }

        bool c1 = !((tot * b) % (b - a));
        int k = (tot * b) / (b - a);
        bool c2 = (k >= (cntMin * -1) && k <= cntAdd);
        if (c1 && c2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}