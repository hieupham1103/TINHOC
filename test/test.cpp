#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    int a[1000];
    a[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int res = 0;
    for (int i = 1; i <= n; i++){
        for (int j = i, x = 0; j >= 1;j--){
            x = x xor a[j];
            if (x >= k){
                cout << j << " " << i << endl;
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}