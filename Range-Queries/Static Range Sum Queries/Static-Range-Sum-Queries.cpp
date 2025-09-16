#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{

    ll n, q;
    cin >> n >> q;

    ll arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    ll prefix[n]; // storing prefix sum

    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = arr[i] + prefix[i - 1];
    }

    while (q--)
    {
        ll a, b;
        cin >> a >> b;

        ll ans = (a == 1) ? prefix[b - 1] : prefix[b - 1] - prefix[a - 2];

        cout << ans << endl;
    }

    return 0;
