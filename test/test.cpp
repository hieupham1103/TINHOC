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

ii operator + (const ii &a, const ii &b){
    return {a.fi + b.fi, a.se + b.se};
}
ii operator * (const ii &a, const ii &b){
    return {a.fi * b.fi, a.se * b.se};
}

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
    ii a = {2,2};
    ii b = {3,3};
    ii c = (a + b) * a;
    cout << c.fi << " " << c.se << endl;
    return 0;
}