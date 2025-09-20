#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() // this is really a tricky problem , my first logic is wrong ( pratially correct for one case)
{
    ll r, c;
    cin >> r >> c;
    ll n = max(r, c);

    if (n % 2)
    { // odd
        if (r >= c)
        {
            cout << (n - 1) * (n - 1) + c << "\n";
            return;
        }
        if (c >= r)
        {
            cout << n * n - (r - 1) << "\n";
            return;
        }
    }
    else
    { // even

        if (r >= c)
        {
            cout << n * n - (c - 1) << "\n";
            return;
        }
        if (c >= r)
        {
            cout << (n - 1) * (n - 1) + r << "\n";
            return;
        }
    }
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}