#include<bits/stdc++.h>
using namespace std;

#define ll long long

//void solve()
//{
//    int n;
//    cin >> n;
//
//
//}

int main(){    ///A
    ll n;
    cin >> n;

    ll arr[n];

    for(int i=0; i<n; i++) cin >> arr[i];
    ll cnt =0;ll cn=0;

    for(int i=0; i<n-1; i++){
        if(arr[i] > arr[i+1]){
            cnt += abs(arr[i]-arr[i+1]);
            cn = cn + cnt;
            arr[i+1] = arr[i+1]+cnt;
            cnt =0;
        }
    }
//    if(arr[n-1] < arr[n-2]){
//        cn += (arr[n-2] - arr[n-1]);
//    }

    cout << cn << endl;
    return 0;
}
