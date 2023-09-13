#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <int> ls;
    int sum = 0;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        ls.push_back(x);
        sum += x;
    }
    sort(all(ls));

    int res = n;

    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            int s = 0;
            for (int k = i; k <= j; k++){
                s += ls[k];
            }
            if (s == 0){
                res = min(res, n - (j - i + 1));
            }
        }
    }

    cout << res << endl;

    return 0;
}