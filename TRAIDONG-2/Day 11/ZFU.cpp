#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e6 + 10;
const ii mod = {1e9 + 7, 1e9 + 9};
const ii base = {50,24};
 
ii POW[maxN];
 
ii mul(ii a, ii b){
    (a.fi *= b.fi) %= mod.fi;
    (a.se *= b.se) %= mod.se;
    return a;
} 
 
ii add(ii a, ii b){
    (a.fi += b.fi) %= mod.fi;
    (a.se += b.se) %= mod.se;
    return a;
}
 
 
ii subtr(ii a, ii b){
    (a.fi = a.fi - b.fi + mod.fi) %= mod.fi;
    (a.se = a.se - b.se + mod.se) %= mod.se;
    return a;
}
 
struct hashtype{
    vector <char> s;
    vector <ii> ha;
    vector <int> turn;
    int len(){
        return s.size() - 1;
    }
    void init(string s0){
        int l = s0.length();
        s.push_back(' ');
        ha.push_back({0,0});
        turn.push_back(0);
        for (int i = 0; i < l; i++){
            s.push_back(s0[i]);
            ha.push_back(add(mul(ha[i], base), {s0[i], s0[i]}));
        }
    }
    void push(char c){
        s.push_back(c);
        ha.push_back(add(mul(ha.back(), base), {c,c}));
    }
    void pop(){
        turn.pop_back();
        s.pop_back();
        ha.pop_back();
    }
    ii get(int l, int r){
        if (r > len()){
            return {-1,-1};
        }
        return subtr(ha[r], mul(ha[l - 1], POW[r - l + 1]));
    }
};

void print(ii x, char c = endl){
    cout << x.fi << ' ' << x.se << c;
}

int a[maxN];


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
    POW[0] = {1,1};
    for (int i = 1; i < maxN; i++){
        POW[i] =  mul(POW[i - 1], base);
    }

    string s;
    cin >> s;
    hashtype HASH;
    HASH.init(s);
    int n = a[1] = HASH.len();
    for (int i = 2; i <= n; i++){
        if (s[i - 1] != s[0]){
            continue;
        }
        int l = 0;
        int r = n - i;
        int res = 0;
        while(l <= r){
            int mid = (l + r) / 2;
            // cout << i << " " << i + mid << " " << 1 << ' ' << 1 + mid << endl;
            if (HASH.get(i, i + mid) == HASH.get(1,1 + mid)){
                l = mid + 1;
                res = mid;
            }
            else{
                r = mid - 1;
            }
        }
        a[i] = res + 1;
    }

    // for (int i = 1; i <= n; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    for (int i = n; i >= 1; i--){
        a[i] = max(a[i], a[i + 1]);
    }

    

    int test;
    cin >> test;
    while(test--){
        int t;
        cin >> t;
        cout << a[t] << endl;
    }
    return 0;
}

/*
abaababaab
abaababaab
*/