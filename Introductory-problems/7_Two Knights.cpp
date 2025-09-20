#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    // CSES problem solution here
    ll n;
    cin >> n;

    for (ll k = 1; k <= n; k++)
    {
        ll total_place = (k * k) * (k * k - 1) / 2;

        ll total_attacking_rectangles = 2 * (k - 1) * (k - 2); // 2 * 3 and 3 * 2 rectangles

        // each rectangle give two attacking positions

        ll total_attacking_positions = 2 * total_attacking_rectangles;

        cout << total_place - total_attacking_positions << endl;
    }
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