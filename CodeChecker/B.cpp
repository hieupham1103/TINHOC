#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2e5 + 10;

int a[maxN];

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, k;
        cin >> n >> k;
        vector <int> ls[2];
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            ls[i % 2].push_back(a[i]);
        }
        sort(a + 1, a + 1 + n);
        sort(all(ls[0]));
        sort(all(ls[1]));
        
        for (int i = 1; i <= n; i++){
            if (a[i] != ls[i % 2][(i - 1) / 2]){
                cout << "NO" << endl;
                goto bru;
            }
        }

        cout << "YES" << endl;

        bru:;
    

    }
    return 0;
}
