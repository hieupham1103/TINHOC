#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
#define all(s) s.begin(), s.end()
using namespace std;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());



int random(int left, int right){
    if (left >= right){
        return left;
    }
    int t = 0;
    for (int i = 1; i <= 4; i++){
        t = (t << 15) xor (rand() & ((1ll << 15) - 1));
    }
    return (t % (right - left + 1)) + left;
}


void randomTree(int n){
    for (int i = 2; i <= n; i++){
        cout << i << ' ' << random(1, i - 1) << endl;
    }
}

string randomStr(const int len) {
    static const char alphanum[] =
        "AB*";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    
    return tmp_s;
}

void random_pair(int n, char en = endl){
    int l = random(1,n);
    cout << l << " " << random(l,n) << en;
}

vector <int> adj[1000];

signed main(){
    srand(time(0));
    freopen("input.inp", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test = random(1,3);
    cout << test << endl;
    while(test--){
        random_pair(1000000);
    }
    return 0;
}