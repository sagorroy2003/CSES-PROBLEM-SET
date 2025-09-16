#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define en endl

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll x, n;
    cin >> x >> n;

    set<ll> pos = {0, x};       // Store positions, including start (0) and end (x)
    multiset<ll> lengths = {x}; // Store passage lengths

    vector<ll> ans; // Store answers for each step

    for (int i = 0; i < n; i++)
    {
        ll p;
        cin >> p;

        // Find nearest left and right positions
        auto it = pos.upper_bound(p);
        ll right = *it;
        ll left = *prev(it);

        // Remove old segment length
        lengths.erase(lengths.find(right - left));

        // Insert new segment lengths
        lengths.insert(p - left);
        lengths.insert(right - p);

        // Insert the new position
        pos.insert(p);

        // Store the largest passage at this step
        ans.push_back(*lengths.rbegin());
    }

    for (ll res : ans)
        cout << res << " ";
    cout << endl;

    return 0;
