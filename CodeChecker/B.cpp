#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int a[1000];
int b[1000];
int check[1000];
int ans = 1e18;
void backtrack(int id){
    if (id > n){
        int m1 = 0;
        int m2 = 0;
        for (int i = 1; i <= n;i++){
            if (check[i]){
                m1 = max(m1,a[i]);
            }
            else{
                m2 = max(m2,b[i]);
            }
        }
        ans = min(ans, abs(m1 - m2));
    }
    backtrack(id + 1);
    check[id] = 1;
    backtrack(id + 1);
    check[id] = 0;
}

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    // freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i] >> b[i];
        }
        ans = 1e18;
        backtrack(1);
        cout << ans << endl;
    }
    return 0;
}