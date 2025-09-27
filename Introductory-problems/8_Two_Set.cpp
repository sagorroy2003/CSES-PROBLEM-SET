#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    // CSES problem solution here
    ll n;
    cin >> n;

    ll a = (n * (n + 1) / 2) / 2; // sum of first n natural numbers / 2

    if ((n * (n + 1) / 2) % 2 != 0)
    { // jor na hole vag kora jabe na
        cout << "NO" << endl;
        return;
    }

    vector<ll> v, v2;

    for (ll i = 1; i <= n; i++)
    {
        v.push_back(i);
    }

    cout << "YES" << endl;

    ll k = n - 1;

    while (a > 0)
    {
        ll x = v[k--];
        if (a >= x)
        {
            v2.push_back(x);
            a -= x;
            v[k + 1] = 0;
            // v.pop_back();
        }
        else
        {
            v2.push_back(a);
            a = 0;
        }
    }

    cout << v2.size() << endl;
    for (auto it : v2)
        cout << it << " ";
    cout << endl;

    cout << v.size() - v2.size() << endl;
    for (auto it : v)
    {
        if (it != 0)
            cout << it << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int t;
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    solve(); // Most CSES problems are single test case

    return 0;
}