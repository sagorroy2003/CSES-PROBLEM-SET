#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    // CSES problem solution here
    ll n;
    cin >> n;

    if (n % 4 == 1 || n % 4 == 2)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    vector<ll> set1, set2;

    if (n % 4 == 3)
    {
        set1 = {1, 2};
        set2 = {3};
        for (ll i = 4; i <= n; i += 4)
        {
            set1.push_back(i);
            set1.push_back(i + 3);
            set2.push_back(i + 1);
            set2.push_back(i + 2);
        }
    }
    else // n % 4 == 0
    {
        for (ll i = 1; i <= n; i += 4)
        {
            set1.push_back(i);
            set1.push_back(i + 3);
            set2.push_back(i + 1);
            set2.push_back(i + 2);
        }
    }

    cout << set1.size() << endl;
    for (ll x : set1)
        cout << x << " ";
    cout << endl;

    cout << set2.size() << endl;
    for (ll x : set2)
        cout << x << " ";
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