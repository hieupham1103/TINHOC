#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n = (2097151 xor 1747626 xor 1922389);
    int m = (4194303 xor 3844778 xor 4019541);
    cout << n << " " << m;

    return 0;
}

/*
111111111111111111111
010101010101010101010
111010101010101010101

1111111111111111111111
1010101010101010101010
1101010101010101010101
*/