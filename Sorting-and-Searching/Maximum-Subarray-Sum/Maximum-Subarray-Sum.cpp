#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{

    int n;
    cin >> n;

    ll arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    ll cs = 0, ms = LLONG_MIN;

    for (int i = 0; i < n; i++)
    {
        cs += arr[i];
        ms = max(cs, ms);

        if (cs < 0)
            cs = 0;
    }

    cout << ms << endl;

    return 0;
}
