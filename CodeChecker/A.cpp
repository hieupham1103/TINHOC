#include"bits/stdc++.h"
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e3 + 10;

int n;
int a[maxN][maxN];
int b[maxN][maxN];
int pre[2][maxN];

int cal(){
    // cout << "With: " << endl;
    int res = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n + 1; j++){
            pre[0][j] = pre[0][j - 1] + a[i][j] * (j % 2 == 0);
            pre[1][j] = pre[1][j - 1] + a[i][j] * (j % 2);
        }
        // for (int j = 1; j <= n; j++){
        //     cout << a[i][j] << " ";
        // }
        // cout << endl;
        // for (int j = 1; j <= n; j++){
        //     cout << pre[0][j] << " ";
        // }
        // cout << endl;
        // for (int j = 1; j <= n; j++){
        //     cout << pre[1][j] << " ";
        // }
        // cout << endl;
        int tres = 0;
        for (int j = 2; j <= n; j+=2){
            tres = max(tres, pre[0][j] + pre[1][n] - pre[1][j + 1]);
            tres = max(tres, pre[1][j] + pre[0][n] - pre[0][j]);
            // cout << j << ": " << pre[0][j] + pre[1][n] - pre[1][j + 1] << " " << pre[1][j] + pre[0][n] - pre[0][j] << endl;
        }
        // cout << i << ": " << tres << endl;
        res += tres;
    }
    return res;
}

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("SPACED.inp", "r")) {
        freopen("SPACED.inp", "r", stdin);
        freopen("SPACED.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    int res = 0;
    res = max(res, cal());
    swap(a,b);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            a[i][j] = b[j][i];
        }
    }
    res = max(res, cal());
    cout << res << endl;
    return 0;
}
/*
xx..
..xx
xx..
..xx
.x.xx.
*/